因为0不能放在首位，因此我们需要分两种情况枚举：
1.组成的数必有0：此时我们知道0一定会出现在后n-1位里的某一位，我们只需枚举0的位置然后进行计数即可。
2.组成的数中没有0：此时成为了最一般的情况，我们可以直接计数啦。

```
class Solution {
    public int countNumbersWithUniqueDigits(int n) {
     int ans=1,num=10;
     int[] arr=new int[n+1];
     arr[0]=1;
     for(int i=1;i<=n;i++) arr[i]=arr[i-1]*(--num);
     for(int i=1;i<=n;i++) ans+=(i-1)*arr[i-1]+arr[i];
     return ans;
    }
```
