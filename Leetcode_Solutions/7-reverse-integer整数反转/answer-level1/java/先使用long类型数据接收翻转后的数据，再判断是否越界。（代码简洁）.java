```
class Solution {
    public int reverse(int x) {
        long y=0;
        while(x!=0){
            y=y*10+x%10;
            x/=10;
        }
        return y==(int)y?(int)y:0;//看强转后的数据与原数据是否相等就知道是否越界了。
    }
}
```
