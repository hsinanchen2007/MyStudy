遇到个坑，private的bool属性，为了保存状态设置成static，然鹅这玩意儿默认值是true。。怀疑人生为啥答案一直有问题。去掉就好了。

coding：

```
/*
 * @lc app=leetcode.cn id=67 lang=csharp
 *
 * [67] 二进制求和
 */
public class Solution {
    private bool isPromote = false;

    public string AddBinary(string a, string b) {
            //Initialize judge.
            if (string.IsNullOrEmpty(a) && string.IsNullOrEmpty(b))
            {
                return "";
            }

            var stackA = new Stack<char>();
            var stackB = new Stack<char>();

            //Push all elements into stacks to do calculate for end to top.
            foreach (var itemA in a)
            {
                stackA.Push(itemA);
            }
            foreach (var itemB in b)
            {
                stackB.Push(itemB);
            }

            var finalStack = new Stack<char>();
            while (stackA.Count > 0 || stackB.Count > 0)
            {
                if (stackA.Count > 0 && stackB.Count == 0)
                {
                    var result = ProduceBinaryNum(stackA.Pop(), '0',  ref isPromote);
                    finalStack.Push(result);
                }
                if (stackA.Count == 0 && stackB.Count > 0)
                {
                    var result1 = ProduceBinaryNum('0', stackB.Pop(), ref isPromote);
                    finalStack.Push(result1);
                }
                if (stackA.Count > 0 && stackB.Count > 0)
                {
                    var result2 = ProduceBinaryNum(stackA.Pop(), stackB.Pop(), ref isPromote);
                    finalStack.Push(result2);
                }
            }

            if (isPromote)
            {
                finalStack.Push('1');
            }

            string resultS = "";
            while (finalStack.Count > 0)
            {
                resultS += finalStack.Pop();
            }

            return resultS;
        }

        private char ProduceBinaryNum(char a, char b, ref bool isPromote)
        {
            if (a == '0' && b == '0')
            {
                if (isPromote)
                {
                    isPromote = false;
                    return '1';
                }
                else
                {
                    isPromote = false;
                    return '0';
                }
            }
            if ((a == '1' && b == '0') || (a == '0' && b == '1'))
            {
                if (isPromote)
                {
                    isPromote = true;
                    return '0';
                }
                else
                {
                    isPromote = false;
                    return '1';
                }
            }
            if (a == '1' && b == '1')
            {
                if (isPromote)
                {
                    isPromote = true;
                    return '1';
                }
                else
                {
                    isPromote = true;
                    return '0';
                }
            }

            return '0';
        }
}


```
