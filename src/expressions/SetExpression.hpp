/**
 * Meet Programming Language Expression.
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
#ifndef MEET_SET_EXPRESSION_H
#define MEET_SET_EXPRESSION_H

#include "../Expression.hpp"
#include "../Statement.hpp"
#include "../Token.hpp"

class SetExpression: public Expression {
    public:
        Token name;

        Expression* expression;
        Expression* value;

        Statement* then;

        std::string type;

        SetExpression(Token name, Expression* expression, Expression* value, Statement* then, std::string type): 
                name(std::move(name)) {
                    this->expression = std::move(expression);
                    this->value = std::move(value);
                    this->type = std::move(type);
                    
                    if (then != nullptr)
                        this->then = then;
        }

        ~SetExpression() {
            delete expression;
            delete value;
        }

        std::string defintion() {
            return EXPRESSION_SET;
        }

        std::string toString() {
            std::stringstream data;

            data << "[ SetExpression: name = ";

            data << name.literal << ", expression = ";
            data << expression->toString() << ", value = ";
            data << value->toString();

            if (then != nullptr)
                data << ", then = " << then->toString() << ", type = " << type;
            else
                data << ", type = " << type;

            data << " ]";

            return data.str();
        }
};

#endif