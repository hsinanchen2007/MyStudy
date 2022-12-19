- 分隔点前的1个数 + 分隔点后0的个数就是需要翻转的次数
- 遍历 计数1的个数和后面的0个数，开始设0的个数为0，遍历后再修正0的数量
- 保存最小值



```
class Solution {
    public int minFlipsMonoIncr(String S) {
        int t0=0,t1=0;       
        int total0=0;       
        int min = 0;
        for(int i=0;i<S.length();i++){
            if(S.charAt(i) =='1'){
                t1++;
            }else{
                t0--;
                total0++;
            }            
            min=(t1+t0)<min ? (t1+t0) : min;
        }
        return min + total0;
    }
}
```
