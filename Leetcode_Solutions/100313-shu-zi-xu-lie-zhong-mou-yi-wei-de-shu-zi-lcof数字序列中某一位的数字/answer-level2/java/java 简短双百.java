### 解题思路
此处撰写解题思路

### 代码

```java
class Solution {
    public int findNthDigit(int n) {
        for(long i=1;i<20;i++){
            long pow=(long)Math.pow(10,i-1);
            long j=9*i*pow;
            if(n>j){
                n-=j;
            }else{
                long num = (n-1)/i+pow;
                long place = (n-1)%i;
                return Long.toString(num).charAt((int)place)-'0';
            }
        }
        return -1;
    }
}
```