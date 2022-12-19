用fiveCount和tenCount记录五元和十元的个数
遍历bills：
* 遇到五元，fiveCount++
* 遇到十元，fiveCount--,tenCount++
* 遇到二十元，优先使用十元+五元的方式找零，如果没有十元，fiveCount-3
* 每次找零结束后判断fiveCount是否小于0，如果小于0就返回false
```
class Solution {
    public boolean lemonadeChange(int[] bills) {
        int fiveCount = 0;
        int tenCount = 0;
        for(int i=0; i<bills.length; i++){
            if(bills[i]==5){
                fiveCount++;
            }else if(bills[i]==10){
                fiveCount--;
                tenCount++;
            }else if(bills[i]==20){
                if(tenCount>0){
                    tenCount--;
                    fiveCount--;
                }else{
                    fiveCount-=3;
                }
            }
            if(fiveCount<0){
                return false;
            }
        }
        return true;
    }
}
```
