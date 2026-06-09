有效括号字符串的结构无非是嵌套和连接两种，即(A)和AB
我们可以利用栈得到括号在字符串中的层数，则显然匹配的左右括号层数是相同的
想要使拆分之后的字符串深度最小，则必须要拆分嵌套结构
可以将奇数层赋予A，偶数层赋予B，反之亦可
```C#
public int[] VPSMaximumNestingDepth(string seq)
        {
            int depth = 0;//括号所在的层数
            int[] answer = new int[seq.Length];
            Stack<char> charStack = new Stack<char>();//字符栈
            Stack<int> indexStack = new Stack<int>();//下标栈
            for (int i = 0; i < seq.Length; i++)
            {
                if(seq[i] == '(')
                {
                    charStack.Push(seq[i]);
                    indexStack.Push(i);
                    depth++;
                }
                else//seq[i] == ')'
                {
                    if (depth % 2 != 0)//depth为奇数，奇数层分给A
                    {
                        answer[indexStack.Peek()] = 0;
                        answer[i] = 0;
                    }
                    else//depth为偶数，偶数层分给B
                    {
                        answer[indexStack.Peek()] = 1;
                        answer[i] = 1;
                    }
                    depth--;
                    charStack.Pop();
                    indexStack.Pop();
                }//else
            }
            return answer;
        }//function
```
