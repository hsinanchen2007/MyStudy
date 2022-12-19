### 解题思路

例子1：
seq = "()"
有一组需要放1套括号，另一组为空

例子2：
seq = "(())"
这两套括号只能放不同组里，这样最大深度是1

例子3：
seq = "((()))"
有一组需要放2套括号，另一组放剩下的1套括号

例子4：
seq = "(((())))"
A B组分别放两套括号，最大深度是2

例子5：
seq = "((((()))))"
有一组需要放3套括号，另一组放剩下的2套括号

例子6：
seq = "()()"
这两套括号无论放A还是B最大深度都是1，可以同时一个组里

通过上面的规律发现，只要用'('的被嵌套的括号数求余2后，结果是0的话就放A组，是1的话就放B组， 并且')'所放的组的和匹配的'('一样，就可以解决问题








### 代码

```csharp
public class Solution {
    public int[] MaxDepthAfterSplit(string seq) {
        int a = 0;
        int[] ret = new int[seq.Length];
        for(int i = 0; i < seq.Length; i++)
        {
            if(seq[i] == '(')
            {
                ret[i] = a % 2;
                a++;
            }
            else
            {
                a--;
                ret[i] = a % 2;
            }
        }
        return ret;
    }
}
```