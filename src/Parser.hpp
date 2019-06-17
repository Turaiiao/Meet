/**
 * Meet Programming Language Parser.
 *
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at:
 *
 * http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 *
 * Copyright (c) 2019 Turaiiao
 * Email: 1171840237@qq.com
 * Github: https://github.com/turaiiao
 */
#ifndef MEET_PARSER_H
#define MEET_PARSER_H

#include <vector>

#include "Statement.hpp"
#include "Expression.hpp"
#include "Token.hpp"

#include "expressions/LiteralExpression.hpp"
#include "expressions/BinaryExpression.hpp"

#include "statements/ExpressionStatement.hpp"

class Parser {
    private:
        std::vector<Token> tokens;
        std::vector<Statement *> statements;

        int position;

        Token look();
        Token look(int pos);
        Token previous();

        bool isAtEnd();
        bool look(TokenType tokenType);

        void insertStatement(Statement* stmt);

        Statement* statement();
        Expression* expression();

        Expression* addition();
        Expression* multiplication();
        Expression* primary();

        ExpressionStatement* expressionStatement();
    public:
        explicit Parser(std::vector<Token> tokens);

        std::vector<Statement *> parseProgram();
};

#endif