9-->1  (a)  len=1(数量级) 
99-->1*9+10+1=20  (b)   len=10(数量级) (1,21...91)+(10,12..19,11)
999->(b*9+len+Cal(len-1))  Cal(x)为x的1的数量 (1-99,201-299...901-999)+(100-199中的百位)+(100-199中的非百位，即1-99)

5345->(5345/1000不计算1000-1999中的千位1)*Cal(999)+Cal(345)+(1000 这是1000-1999中千位的1)
1345->(1345%1000+1 这是1000-1345中千位1)+Cal(999)+Cal(345)
```
class Solution {
    int getLen(int n){
        int res=1;
        while(n>=10){
            n=n/10;
            res*=10;;
        }
        return res;
    }
    public int countDigitOne(int n) {
        if(n==0)return 0;
        if(n<10)return 1;
        int len=getLen(n);
        if(n/len>1){
            return (n/len)*countDigitOne(len-1)+countDigitOne(n%len)+len;
        }
        else {
            return n%len+1+countDigitOne(n%len)+countDigitOne(len-1);
        }
    }
}
```
