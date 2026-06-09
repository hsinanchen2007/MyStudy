### 解题思路
用 state 来记录当前数值的表现形式，如果格式不满足就直接返回
space 来记录有效数值后面是否有空格，如果有需要判断空格后是否有额外数据
代码可以简化成按位操作形式，懒得改了

### 代码

```cpp
class Solution {
    /**
     * N 无状态
     * Dot 小数点
     * I 整数
     * D 小数
     * S 符号
     * e e
     */
    enum State {
        N, Dot, SDot, I, D, S, SI, SD, Ie, IeI,
        IeS, IeSI, SIe, SIeI, SIeS,
        SIeSI, De, DeI, DeS, DeSI,
        SDe, SDeI, SDeS, SDeSI,
    };

public:
    bool isNumber(string s) {
        size_t length = s.size();
        const char *ptr = s.c_str();
        State state = N;
        bool space = false;
        for (size_t i = 0; i < length; i++) {
            switch (ptr[i]) {
                case '+':
                case '-':
                    if (space) {
                        return false;
                    }
                    switch (state) {
                        case N:
                            state = S;
                            break;
                        case Ie:
                            state = IeS;
                            break;
                        case SIe:
                            state = SIeS;
                            break;
                        case De:
                            state = DeS;
                            break;
                        case SDe:
                            state = SDeS;
                            break;
                        default:
                            return false;
                    }
                    break;
                case '.':
                    if (space) {
                        return false;
                    }
                    switch (state) {
                        case N:
                            state = Dot;
                            break;
                        case S:
                            state = SDot;
                            break;
                        case I:
                            state = D;
                            break;
                        case SI:
                            state = SD;
                            break;
                        default:
                            return false;
                    }
                    break;
                case ' ':
                    switch (state) {
                        case N:
                            break;
                        default:
                            space = true;
                            break;
                    }
                    break;
                case 'e':
                    if (space) {
                        return false;
                    }
                    switch (state) {
                        case I:
                            state = Ie;
                            break;
                        case SI:
                            state = SIe;
                            break;
                        case D:
                            state = De;
                            break;
                        case SD:
                            state = SDe;
                            break;
                        default:
                            return false;
                    }
                    break;
                case '0':
                case '1':
                case '2':
                case '3':
                case '4':
                case '5':
                case '6':
                case '7':
                case '8':
                case '9':
                    if (space) {
                        return false;
                    }
                    switch (state) {
                        case N:
                            state = I;
                            break;
                        case Dot:
                            state = D;
                            break;
                        case SDot:
                            state = SD;
                            break;
                        case S:
                            state = SI;
                            break;
                        case Ie:
                            state = IeI;
                            break;
                        case IeS:
                            state = IeSI;
                            break;
                        case SIe:
                            state = SIeI;
                            break;
                        case SIeS:
                            state = SIeSI;
                            break;
                        case De:
                            state = DeI;
                            break;
                        case DeS:
                            state = DeSI;
                            break;
                        case SDe:
                            state = SDeI;
                            break;
                        case SDeS:
                            state = SDeSI;
                            break;
                        case I:
                        case D:
                        case SI:
                        case SD:
                        case IeI:
                        case IeSI:
                        case SIeI:
                        case SIeSI:
                        case DeI:
                        case DeSI:
                        case SDeI:
                        case SDeSI:
                            break;
                        default:
                            return false;
                    }
                    break;
                default:
                    return false;
            }
        }
        return (state == I ||
                state == SI ||
                state == IeI ||
                state == IeSI ||
                state == SIeI ||
                state == SIeSI ||
                state == DeI ||
                state == DeSI ||
                state == SDeI ||
                state == SDeSI ||
                state == D ||
                state == SD);
    }
};
```