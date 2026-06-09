### 解题思路
刚好自己的思路和官方的思路3闭合数不谋而合，不过，这个算法粗看很MAGIC。在此分享一下思路。

1.看到这个第一反应，递归。所以假设Generate(n+1) = f( Generate(n) )，其中新添加的括号总是在原始的外侧或同等水平，即“()X”,"(X)","X()"三种形态。

2.分析Generate(n)的可能形态。我们以“(......)”这样的形态作为一个**块**，尽可能多的匹配，一个块自身必须是一种有效组合。可以如下图，分为2类，整块类和分块类。
![1.bmp](https://pic.leetcode-cn.com/a3f13eb5f4ec6d1bd27817de6fae5d76cc188757ce44cab10b3fc08ae1bafad5-1.bmp)

3.此时分析Generate(n+1)，即企图在Generate(n)基础上添加一对括号，A和B形态分别有如下可能。如下图，其中橙色为在同等水平添加，绿色为外侧添加。
![3.jpg](https://pic.leetcode-cn.com/1d092c6a849d7460e2a69ed2dd028506277fb69ca51b89ecbe8be7885ef5d19c-3.jpg)


4.由于题目描述中暗含一个要求，输出List中的元素不应重复，所以“()X”和"X()"本质上是一种情况，问题简化成如何用一种方法实现“()X”和“(X)”

5.考虑一种简单粗暴的方法，如下。n=3的时候简直美滋滋，然而n=4的时候，没办法覆盖到“(())(())”这种情况，毕竟太粗糙了啊。嗯，不好用又不优雅
```
res.Add("()" + Generate(n));            //   ()X
res.Add("(" + Generate(n) + ")");       //   (X)
```

6.果断把Generate(n)给左右拆了，“( left ) right”，为了覆盖“()X”的情况，让n=0的时候加一个空string，这样可以left = 0, right = n。回顾一下步骤3的可能性，都覆盖到了。


### 代码

```csharp
public class Solution {
    public IList<string> GenerateParenthesis(int n) {
        List<string> res = new List<string>();

        if (n == 0)
            res.Add("");
        else 
        {
            for (var i = 0; i < n; i++)
            {
                foreach (var left in GenerateParenthesis(i))
                {
                    foreach (var right in GenerateParenthesis(n - i - 1))
                    {
                        res.Add("(" + left + ")" + right);
                    }

                }
            }
        }
        return res;   
    }
}
```