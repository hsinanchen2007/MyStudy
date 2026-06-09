### 解题思路
1. 新建变量用于存储 现有零钱的各面额数量
2. 遍历数组，每次收款后计算现有零钱面额数量，通过操作面额数量来确定能否找开。（5元和10元的都大于等于0）
3. 如果能那么继续遍历，找不开直接返回false

### 代码

```java
class Solution {
    public boolean lemonadeChange(int[] bills) {
        int fiveCount = 0;
        int tenCount = 0;
        int twentyCount = 0;
        int needReturn = 0;
        for (int i = 0; i < bills.length; i++){
            int value = bills[i];
            needReturn = value - 5;
            switch (value){
                case 5:
                {
                    fiveCount ++;
                }
                break;
                case 10:
                {
                    fiveCount --;
                    tenCount ++;
                }
                break;
                case 20:
                {
                    if (tenCount > 0){
                        fiveCount --;
                        tenCount --;
                    }else {
                        fiveCount -=3;
                    }
                    twentyCount ++;
                }
                break;
            }
            if (fiveCount<0 || tenCount <0) 
            {
                return false;
            }
        }
        return true;
    }
}
```