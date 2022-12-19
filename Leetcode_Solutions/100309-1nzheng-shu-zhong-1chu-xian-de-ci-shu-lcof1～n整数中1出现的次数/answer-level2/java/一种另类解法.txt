### 解题思路
一种另类解法

### 代码

```java
class Solution {
    public int countDigitOne(int n) {
        int part = 10;
        int numLeft = n; //基数
        int numLast = 0; //最后一位数
        int numTimes = 1; //累计的倍数
        int result = 0;
        int caculated = 0; //已计算的数字
        while(numLeft > 0){
            numLast = numLeft % part;

            if(numLast > 0){
                if(numLast > 1){
                    result += numTimes;
                }else{
                    result += caculated + 1;
                }
                result += numLast * getRate(numTimes);
            }
            
            numLeft = numLeft / part;
            caculated += numTimes*numLast;
            numTimes *= part;
        }
        return result;
    }

    public int getRate(int ratio) {
        if(ratio == 1){
            return 0;
        }
        if(ratio == 10){
            return 1;
        }
        return ratio / 10 + getRate(ratio / 10) * 10;
    }
}
```