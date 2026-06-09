
## 解决方案

本文给出了两种解决方案。

第一种解决方案 是官方题解提到的那种 “及其臃肿的代码”的方法，虽然说臃肿，但实际代码量比起官方解法还是要少一些，而且在很多实际工作中的应用场景下，还是避免不了 像这样 大量使用 if else 来处理特殊输入 的 情况，所以这种方法也不失为一种好的方法。 

第二种方法参考了官方解法，使用了DFA  （Deterministic Finite Automaton）算法，即 “确定有穷自动机”，其特征为：有一个有限状态集合和一些从一个状态通向另一个状态的边，每条边上标记有一个符号，其中一个状态是初态，某些状态是终态。但不同于不确定的有限自动机，DFA中不会有从同一状态出发的两条边标志有相同的符号。

## 方法一：及其臃肿的代码

这种解法说臃肿也不算臃肿，是大部分人（包括笔者）的第一解法， 我们通过分析题目所给示例来写代码处理输入，没问题后就可以提交代码，如果 解答错误 了，就根据出错的测试用例来完善代码，经过来回几次处理特殊测试用例后，即可获得 “通过”。

分析示例2，我们需要去掉前后的空格；分析示例三，得知需要截取前面的数字部分来作为结果；分析示例4，得知输入的第一个字符必须是正负号或者数字；分析示例5，得知超出int范围时需要返回int.MaxValue或int.MinValue.


参考代码：


        public int MyAtoi(string str)
        {
            str = str.Trim();
            if (str.Length == 0) return 0;
            //首位不是数字或者正负号，直接返回0
            if (!char.IsDigit(str[0]) && str[0] != '-' && str[0] != '+') return 0;
            // 截取前面的数字串
            for (int i = 1; i < str.Length; i++)
            {
                if (!char.IsDigit(str[i]))
                {
                    str = str.Substring(0, i);
                    break;
                }
            }
            //只剩下符号了，直接返回0 
            if (str == "-" || str == "+" || str == "+-" || str == "-+") return 0;
            //正常数字求结果
            int result = 0;
            if (int.TryParse(str, out int tryResult2))
            {
                result = tryResult2;
            }
            else
            {
                if (str.Contains("-")) result = int.MinValue;
                else result = int.MaxValue;
            }
            return result;
        }

#### 执行结果

执行结果 通过。 执行用时： 80ms, 内存消耗 24.9M

#### 复杂度分析

**时间复杂度：O(n)**

对长度为n的字符串进行处理。

**空间复杂度：O(1)**

仅用了几个变量, 与n的大小无关。

## 方法二：DFA ，官方解法的优化

该方法使用了DFA（确定有穷自动机）算法，对于输入值str，使用 自动机 来依次处理每个字符，在这个过程中不断的改变自动机的状态，以及当前结果值，来得到最终结果。

根据题目示例分析，可以将自动机的状态总结为4个：start（开始），signed（符号），in_number（数字）,end（结束） .   自动机的初始状态为start ，在处理输入字符的过程中不断的转变状态，当状态变为end时，即可得到最终结果。 

依据题意可以建立如下图所示的自动机（截图来自官方题解）：

![1.png](https://pic.leetcode-cn.com/1f354ea4d7ecf75c1e4432a85914871d60df4d6c1322374ab4c5bf3b4768c51d-1.png)


为了表示方便，我们可以使用int型来表示这4个状态，0表示start，1表示signed，2表示in_number,3表示end。 所以对应上面的自动机状态表格，在代码中可以使用二维int数组来表示：

            public readonly int[,] table = new int[4, 4] {
                { 0,1,2,3 },
                { 3,3,2,3 },
                { 3,3,2,3 },
                { 3,3,3,3 }
            };

根据这个table，我们就可以使用 当前状态 以及 输入字符类型 来获取到下一个状态。比如当前状态为0 start，输入字符类型为 1 +/-，则下一个状态为 table[0][1] ，即 1 signed 。

由题意知 【假设我们的环境只能存储 32 位大小的有符号整数】，但是官方题解的python解法 由于python的数字类型问题 而 没有处理 int型的范围溢出 问题，官方题解的c++解法则直接使用了long long 来跳过对溢出问题的处理。虽然本文解法考虑了这一点，并进行了处理，但官方解法的这种处理也是可以通过的。


参考代码：

        public class Automaton
        {
            /// <summary>
            ///  0 start , 1 signed , 2 in_number , 3 end
            /// </summary>
            public int state = 0;
            public int sign = 1;
            public int result = 0;
            public readonly int[,] table = new int[4, 4] {
                { 0,1,2,3 },
                { 3,3,2,3 },
                { 3,3,2,3 },
                { 3,3,3,3 }
            };
            public int GetCol(char c)
            {
                if (char.IsWhiteSpace(c)) return 0;
                if (c == '+' || c == '-') return 1;
                if (char.IsDigit(c)) return 2;
                return 3;
            }
            public void Get(char c)
            {
                this.state = this.table[this.state, this.GetCol(c)];
                var INT_MAX = int.MaxValue;
                var INT_MIN = int.MinValue;
                // 0 start , 1 signed , 2 in_number , 3 end
                if (this.state == 2)
                {
                    var cInt = Convert.ToInt32(c.ToString());
                    if (this.sign == 1)
                    {
                        if (result > INT_MAX / 10 || (result == INT_MAX / 10 && cInt > 7)) this.result = INT_MAX;
                        else this.result = this.result * 10 + cInt;
                    }
                    else
                    {
                        if (result < INT_MIN / 10 || (result == INT_MIN / 10 && cInt > 8)) this.result = INT_MIN;
                        else this.result = this.result * 10 - cInt;
                    }
                }
                else if (this.state == 1)
                {
                    this.sign = 1;
                    if (c == '-') this.sign = -1;
                }
            }
        }

        public int MyAtoi(string str)
        {
            Automaton automaton = new Automaton();
            foreach (var c in str) automaton.Get(c);
            return automaton.result;
        }


#### 执行结果

执行结果 通过。 执行用时： 88ms, 内存消耗 25M

#### 复杂度分析

**时间复杂度：O(n)**

处理长度为n的字符串。

**空间复杂度：O(1)**

仅用了几个变量，与n的大小无关。


## 参考资料汇总

题目：

[https://leetcode-cn.com/problems/string-to-integer-atoi/](https://leetcode-cn.com/problems/string-to-integer-atoi/)

官方题解：

[https://leetcode-cn.com/problems/string-to-integer-atoi/solution/zi-fu-chuan-zhuan-huan-zheng-shu-atoi-by-leetcode-/](https://leetcode-cn.com/problems/string-to-integer-atoi/solution/zi-fu-chuan-zhuan-huan-zheng-shu-atoi-by-leetcode-/)

DFA 百度百科：

[https://baike.baidu.com/item/dfa/5245832?fr=aladdin#3](https://baike.baidu.com/item/dfa/5245832?fr=aladdin#3)
