### 解题思路
当一个式子被解析了一部分时，假设已经解析的是`A`，没有解析的是`X`，有五种情况
1. `!(X)`
2. `&(A,X)` 其中 `&(A) == t`
3. `&(A,X)` 其中 `&(A) == f`
4. `|(A,X)` 其中 `|(A) == t`
5. `|(A,X)` 其中 `|(A) == f`

其中第3、4中情况不需要再解析`X`就已经可以得到值了，情况变成了三种
1. `!(X)`
2. `&(A,X)` 其中 `&(A) == t`
3. `|(A,X)` 其中 `|(A) == f`

当`X`完成一个子式`b`时，则第1种情况得到`!(b)`。对于其余两种情况来说，如果`b`是最后一个子式，则得到`b`；如果`b`不是最后一个子式则要分情况
1. `&(A,b,X)`，`b == t`，则当作 `b` 不存在，继续解析`X`
2. `&(A,b,X)`，`b == f`，跳过`X`，得到结果为`b`
3. `|(A,b,X)`，`b == t`，跳过`X`，得到结果为`b`
4. `|(A,b,X)`，`b == f`，则当作 `b` 不存在，继续解析`X`

### 代码

```cpp
class NestedLevel {
    char op_;
public:
    NestedLevel(char op) : op_(op) {}
    bool operate(bool val) const {
        return (this->op_ == '!') ^ val;
    }

    bool has_shortcut(bool new_value) const {
        return (this->op_ == '&') ^ new_value;
    }
};

class Solution {
    typedef string::iterator iter;
     // |(t,X) = t, &(f,X) = f, where X is skipped
    static iter skip(iter i) {
        for(auto level = 1; level > 0; ) {
            switch(*(++i)){
            case '(':
                ++ level;
                break;
            case ')':
                -- level;
            }
        }
        return i;
    }
public:
    bool parseBoolExpr(string expr) {
        vector<NestedLevel> nested_levels;
        auto value = false;

        for(auto i = expr.begin(); ;) { // successively push for '&' '|' '!'
            switch(*i) {
            case 't':
            case 'f':
                value = (*(i++) == 't');
                for(auto cont = true; cont ; ++ i) { // successively pop for ')'
                    switch(*i) {
                    case ')': // the last sub-expression
                        value = nested_levels.back().operate(value);
                        nested_levels.pop_back();
                        break;
                    case ',': // not the last sub-expression
                        cont = nested_levels.back().has_shortcut(value);
                        if(cont) { // though not the last, but the rest are neglected
                            i = skip(i);
                            nested_levels.pop_back();
                        }
                        break;
                    default: // end of expression
                        return value;
                    }
                }
                break;
            case '&':
            case '|':
            case '!':
                nested_levels.push_back(*i);
                i += 2; // skip '('
            }
        }
        return value;
    }
};
```