根据其他大佬的分析,超级回文数的开方每个数字不会超过2(除了数字3).所以减少搜索范围,判断在L和R的开方值之内的所有每一位不超过3的数字的平方是否为回文数,若是,则计数器加一.
实现很简单,将10进制数转为3进制即可(但还是以10位来计算).
执行用时 : 18 ms , 在所有 java 提交中击败了 92.98% 的用户 内存消耗 : 33.7 MB , 在所有 java 提交中击败了 100.00% 的用户

```
class Solution {
      public int superpalindromesInRange(String L, String R) {
        long lNum=(long)Math.sqrt(Long.parseLong(L));
        long rNum=(long)Math.sqrt(Long.parseLong(R));
        int count=0;
        if(lNum<=3&&rNum>=3)
            count++;
        long i=0;
        while (true){
            i++;
            long temp=changeRadix(i,10,3);
            if(temp>rNum)
                break;
            if(temp>=lNum&&isPalindrome(temp)&&isPalindrome(temp*temp)){
                    count++;
            }
        }
        return count;
    }
    public long changeRadix(long in,int source,int to){
        long re=0L;
        long t=1;
        do {
            re+=(in%to)*t;
            t*=source;
            in/=to;
        } while (in>0);
        return re;
    }
    public boolean isPalindrome(long l){
        long temp=0;
        long temp2=l;
        while (temp2>0){
            temp+=temp2%10;
            temp2/=10;
            if(temp2>0)
                temp*=10;
        }
        if(temp==l)
            return true;
        return false;
    }
}
```
