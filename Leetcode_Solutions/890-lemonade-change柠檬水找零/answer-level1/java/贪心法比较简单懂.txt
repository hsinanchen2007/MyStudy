
当遇到20元时优先使用10元找零

```
class Solution {
    public boolean lemonadeChange(int[] bills) {
        int fiveDollar = 0;
        int tenDollar = 0;
        int twentydollar = 0;

        for (int bill : bills) {
            switch (bill) {
                case 5: {
                    fiveDollar++;
                    break;
                }
                case 10: {
                    tenDollar++;
                    if(fiveDollar == 0){
                        return false;
                    }
                    fiveDollar--;
                    break;
                }
                case 20: {
                    twentydollar++;
                    if (tenDollar > 0) {
                        tenDollar--;
                        fiveDollar--;
                    } else {
                        fiveDollar -= 3;
                    }
                    if(tenDollar<0 || fiveDollar<0){
                        return false;
                    }
                    break;
                }
                default: {
                    break;
                }
            }
        }
        return fiveDollar >= 0 && tenDollar >= 0 && twentydollar >= 0;
    }
}
```
