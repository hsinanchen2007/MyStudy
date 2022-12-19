### 解题思路
基本是有限状态机的思路，因为使用 enum 来表示状态和输入类型，性能不太乐观，考虑性能的话使用 `int[]` 更合适。
维护三个变量：
- `status` 基本状态
- `exponent` 标记科学记数法
- `containNumber` 标记数字输入状态，防止出现类似 `"."` 的情况

### 代码

```csharp
public class Solution {

    protected enum CharType {Number, Symbol, Dot, Exponent, Space, Other};
    protected enum Status {Begin, Symbol, Integer, Dot, Decimal, End, Error};

    public bool IsNumber(string s) {
        Status status = Status.Begin;
        bool exponent = false;
        bool containNumber = false;
        for (int i = 0; i < s.Length; i++) {
            CharType charType = GetCharType(s[i]);
            status = TransferStatus(status, charType, ref exponent);
            if (status == Status.Error) {
                return false;
            }
            if (charType == CharType.Number && !exponent) {
                containNumber = true;
            }
        }
        if (!containNumber) {
            return false;
        }
        return TransferStatus(status, CharType.Space, ref exponent) == Status.End;
    }

    protected Status TransferStatus(Status status, CharType charType, ref bool isExponent) {
        switch (status) {
            case Status.Begin:
                if (charType == CharType.Symbol) {
                    return Status.Symbol;
                } else if (charType == CharType.Number) {
                    return Status.Integer;
                } else if (!isExponent) {
                    if (charType == CharType.Space) {
                        return status;
                    } else if (charType == CharType.Dot) {
                        return Status.Dot;
                    }
                }
                break;
            case Status.Symbol:
                if (charType == CharType.Number) {
                    return Status.Integer;
                } else if (charType == CharType.Dot && !isExponent) {
                    return Status.Dot;
                }
                break;
            case Status.Integer:
            case Status.Decimal:
                if (charType == CharType.Number) {
                    return status;
                } else if (charType == CharType.Space) {
                    return Status.End;
                } else if (!isExponent) {
                    if (charType == CharType.Exponent) {
                        isExponent = true;
                        return Status.Begin;
                    } else if (charType == CharType.Dot && status == Status.Integer) {
                        return Status.Dot;
                    }
                }
                break;
            case Status.Dot:
                if (charType == CharType.Number) {
                    return Status.Decimal;
                } else if (charType == CharType.Space) {
                    return Status.End;
                } else if (charType == CharType.Exponent) {
                    isExponent = true;
                    return Status.Begin;
                }
                break;
            case Status.End:
                if (charType == CharType.Space) {
                    return status;
                }
                break;
        }
        return Status.Error;
    }

    protected CharType GetCharType(char c) {
        if ("0123456789".IndexOf(c) > -1) {
            return CharType.Number;
        } else if (c == '+' || c == '-') {
            return CharType.Symbol;
        } else if (c == ' ') {
            return CharType.Space;
        } else if (c == '.') {
            return CharType.Dot;
        } else if (c == 'e') {
            return CharType.Exponent;
        } else {
            return CharType.Other;
        }
    }
}
```