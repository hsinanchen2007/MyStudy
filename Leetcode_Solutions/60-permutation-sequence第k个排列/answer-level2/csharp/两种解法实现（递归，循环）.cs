## 解法一
思路：用递归的思想，第一个数字的索引是由后面n-1个数值的阶层倍数，即Idx[0] = k/(n-1)!
1. 先将数组存入线性表List
2. 按递归逻辑，依次从前到后进行访问
3. 将剩余数据依次输出

时间复杂度：O(n)
空间复杂度：O(n)
```csharp
public class Solution {
    public string GetPermutation(int n, int k) {
        string str = "";
        int t, idx,nF=1;
        List<char> r = new List<char>();
        for(int i=1;i<=n;i++)
        {//从小打大存入数据
            nF *= i;
            r.Add((char)(i+'0'));
        }
        nF /= n;
        for(int i=n-1;i> 0 && k>0;i--)
        {//按顺序读出数据
            idx = (k-1) / nF;        
            str += r[idx] ;
            r.RemoveAt(idx);
            k -= idx * nF;
            nF /= i;
        }
        str += r[0];//剩余最后一个数据
        return str;
    }
}
```
![image.png](https://pic.leetcode-cn.com/82b23bd87e4ae3187e30b2684108426b56bd1af775898f1b624019e523d98e6c-image.png)

## 解法二：
思路：同上面一样，改用递归的方式实现，逻辑一样，因此执行效率跟上面差不多

```csharp
public class Solution {

    List<char> r = new List<char>();
    public string Recursion(int n,int fa,int k)
    {
        if(n == 0 || k == 0) return r[0].ToString();
        int idx = (k-1)/fa;
        string str = r[idx].ToString();
        r.RemoveAt(idx);
        return  str + Recursion(n-1,fa/n, k-idx*fa);
    }

    public string GetPermutation(int n, int k) {
        string str = "";
        int t, idx,nF=1;
        
        for(int i=1;i<=n;i++)
        {
            nF *= i;
            r.Add((char)(i+'0'));
        }
        return Recursion(n-1,nF/n,k);
    }
}
```
