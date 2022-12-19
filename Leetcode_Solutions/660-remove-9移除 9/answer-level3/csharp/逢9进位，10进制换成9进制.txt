### 解题思路
题目可以看作是10进制换成9进制问题
参考10进制转16进制
采用“除9反向取余数”的办法。
除9取余数得最低1位，然后把商继续除得第2位，……，直到商等于0
### 代码

```csharp
public class Solution {
    public int NewInteger(int n) {
            string num = "";
           

            while (n>0)
            {
                //取余数，得到最高位的数值
                num = (n % 9).ToString() + num;
                //取整数，控制倍数都除过
                n /= 9;
            }
            return   int.Parse(num);
    }
}
```