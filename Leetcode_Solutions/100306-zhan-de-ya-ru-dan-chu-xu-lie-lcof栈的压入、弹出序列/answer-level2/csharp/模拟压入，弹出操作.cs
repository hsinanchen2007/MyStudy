### 解题思路
模拟压入和弹出操作，从弹出序列的第一位开始，将压入序列的元素压入辅助栈直到某个元素（元素值和弹出序列第一位相等），然后遍历弹出序列的下一位，比较其值和栈顶元素是否相等，如果相等则栈弹出一个，遍历弹出序列下一位，如果不等，则继续将压入序列元素压入。
如果过程中发现压入序列一致到最后都没有弹出序列的元素，则直接返回false。反之遍历完所有元素则为true。

### 代码

```csharp
public class Solution {
    public bool ValidateStackSequences(int[] pushed, int[] popped) {
        Stack<int> stack = new Stack<int>();
        int left = 0;
        int right = 0;
        int length = pushed.Length;
       
        while(right < length)
        {
            if(stack.Count == 0 || popped[right] != stack.Peek())
            {
                for(;left <= length - 1; left++)
                {
                    if(pushed[left] == popped[right])
                    {
                        break;
                    }
                    stack.Push(pushed[left]);
                }
                if(left == length)
                {
                    return false;
                }
                left++;
                right++;
            }else{
                stack.Pop();
                right++;
            }
        }

        return true;
    }
}
```