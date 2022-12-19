### 代码

```java
//厄拉多塞筛法，先划去除2以外所有的2的倍数，再划去除3以外所有3的倍数，再划去除5以外...普通方法会严重超时
class Solution {
    public int countPrimes(int n) {
        boolean []sign =new boolean [n+1];
        int count=0;
        for(int i=2;i<n;i++)
        {
            if(sign[i]==false)         //它是false说明是质数
            {
                count++;               //注意，从2开始计数，所以0和1没被计进去
                for(int j=i+i;j<n;j+=i)  //筛去它的倍数
                    sign[j]=true;
            }
        }
        return count;
    }
}
```