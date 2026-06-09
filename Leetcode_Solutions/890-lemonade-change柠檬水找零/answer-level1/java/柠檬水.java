### 解题思路
原来这里的贪心算法体现在，找回15元的时候，先考虑10+5，再考虑3个5，怪不得我一开始顺序变了提交错误。。。。

### 代码

```java
class Solution {
    public boolean lemonadeChange(int[] bills) {
        int five=0, ten=0;
        for(int bill : bills){
            if(bill == 5){
                five++;
            }
            else if(bill == 10){
                if(five == 0){
                    return false;
                }
                ten++;
                five--;
            }
            else{
                if(five>0 && ten>0){
                    five--;
                    ten--;
                }
                else if(five>=3){
                    five -= 3;
                }
                else{
                    return false;
                }
            }
        }
        return true;
    }
}
```