### 解题思路
一步步推算，注释里有测试思路
### 代码

```csharp
public class Solution {
    public bool IsPalindrome(int x) {
            if (x < 0 || (x % 10 == 0 && x != 0))
                return false;
            //int h = x % 10;//取出最后一位数  比如   14741  h=1   
            //x = x / 10;//x去掉最后一位数  这就变成了   1474  
            //h = (x % 10) + h * 10;//14  
            //x = x / 10;//x  147
            //h = (x % 10) + h * 10;//147  由此  h应该初始化为：int h = x % 10+0  则为：h = x % 10+0*10  让h第一次计算时=0即可
            //x = x / 10;//14     x=h/10
            ////对比
            int h = 0;
            while (x > h)
            {
                h = (x % 10) + h * 10;
                x = x / 10;
            }
            return x == h || x == h / 10;
    }
}
```