> 执行用时：2 ms
> 内存消耗：39.8 MB
> 我的提交执行用时已经战胜 96.91 % 的 java 提交记录

状态转移图参考官方题解的（稍微改了一丁点）：
![image.png](https://pic.leetcode-cn.com/4aef3b340bc0574a3f326d32fdedd8ca8b31113c8c76a5d8bdd6be6f6ca1cdce-image.png)

相较与官方的写成状态转换表并放进代码，我是按照我最开始接触到的状态机的样子写的，所以还是用到了不少`if-else`（主要还是我太菜）。不过看起来倒是比最开始写的纯`if-else`版本舒服些。（有空再用状态转换表改写一下，感观可能好很多）

```java
class Solution {
    private enum Status {start, signed, number, end}

    private int signal = 1;
    private int result = 0;

    public int myAtoi(String str) {
        Status status = Status.start;
        char[] chs = str.toCharArray();
        for (int i = 0; i < chs.length; i++) {
            status = getNextStatus(status, chs[i]);
            // System.out.println(result);
            // 溢出 or 已计算得int极值，不用再浪费时间计算了
            if ((result == Integer.MAX_VALUE && signal == 1)
                    || (result == Integer.MIN_VALUE && signal == -1)) return result;
            // 结束状态，也不用再浪费时间计算了
            if (status == Status.end)
                return signal * result;
        }
        if (status == Status.number) return signal * result;
        return 0;
    }

    private Status getNextStatus(Status status, char ch) {
        switch (status) {
            case start:
                if (ch == ' ') return Status.start;
                else if (ch == '+') return Status.signed;
                else if (ch == '-') {
                    signal = -1;
                    return Status.signed;
                } else if (Character.isDigit(ch)) {
                    result = result * 10 + ch - '0';
                    return Status.number;
                } else
                    return Status.end;
            case signed:
                if (Character.isDigit(ch)) {
                    result = result * 10 + ch - '0';
                    return Status.number;
                } else return Status.end;
            case number:  // 从number状态到number状态才可能会溢出
                if (Character.isDigit(ch)) {
                    if (!willOverflow(ch - '0'))
                        result = result * 10 + ch - '0';
                    return Status.number;
                } else return Status.end;
        }
        return Status.end;
    }

    // 如果溢出就直接给结果赋值Max/Min了
    private boolean willOverflow(int end) {
        if (result > Integer.MAX_VALUE / 10) {
            result = signal == 1 ? Integer.MAX_VALUE : Integer.MIN_VALUE;
            return true;
        } else if (result == Integer.MAX_VALUE / 10) {
            if (signal == 1 && end >= 7) {
                result = Integer.MAX_VALUE;
                return true;
            } else if (signal == -1 && end >= 8) {
                result = Integer.MIN_VALUE;
                return true;
            }
        }
        return false;
    }
}
```

> 把枚举换成int之后执行时间还是2ms。用枚举清晰一些。

> 占用内存比最优方法稍微多了几M，也许状态转换表会好些
