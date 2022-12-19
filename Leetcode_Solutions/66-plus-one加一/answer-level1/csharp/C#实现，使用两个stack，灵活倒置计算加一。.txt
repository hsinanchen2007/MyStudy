此题目标不难，行为单一，判定为easy没啥毛病。但是实现时，选定处理对象到处是坑。

最后采用两个栈来解决这个问题：
Main code:
```
/*
 * @lc app=leetcode.cn id=66 lang=csharp
 *
 * [66] 加一
 */
public class Solution {
    public int[] PlusOne(int[] digits)
        {
            var digitsStack = new Stack<int>();
            bool isPromoted = false;

            if (digits == null || digits.Length == 0)
            {
                return new int[0];
            }

            for (int i = 0; i < digits.Length; i++)
            {
                //push
                digitsStack.Push(digits[i]);
            }

            var reverseStack = new Stack<int>();
            //Calculate last number.
            var last = digitsStack.Pop();
            if (last == 9)
            {
                isPromoted = true;
                reverseStack.Push(0);
            }
            else
            {
                isPromoted = false;
                reverseStack.Push(last + 1);
            }

            //Calculate remained numbers.
            while (digitsStack.Count != 0)
            {
                var nextNumber = digitsStack.Pop();
                if (isPromoted)
                {
                    if (nextNumber == 9)
                    {
                        isPromoted = true;
                        reverseStack.Push(0);
                    }
                    else
                    {
                        isPromoted = false;
                        reverseStack.Push(nextNumber + 1);
                    }
                }
                else
                {
                    reverseStack.Push(nextNumber);
                }
            }

            if (isPromoted)
            {
                //After finishing loop, if isPromoted, which means last element is 9 and it plus one to 10.
                reverseStack.Push(1);
            }

            var finalList = new List<int>();
            while (reverseStack.Count != 0)
            {
                var finalElement = reverseStack.Pop();
                finalList.Add(finalElement);
            }

            return finalList.ToArray();
        }
}


```
