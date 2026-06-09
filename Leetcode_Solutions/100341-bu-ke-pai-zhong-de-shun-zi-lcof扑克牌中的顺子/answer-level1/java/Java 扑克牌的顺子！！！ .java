### 代码

```java
class Solution {
    public boolean isStraight(int[] nums) {
        int min = 14, max = -1;
        //保存是否有重复的数字
        int flag = 0;
        for (int i = 0; i < 5; i++) {
            int num = nums[i];
            if (num > 13 || num < 0) {
                return false;
            }
            
            if (num == 0) continue;
            // flag第num+1位为1， num已存在
            if(((flag >> num) & 1) == 1) {
                return false;
            }
            // 将flag的第num+1位置为1
            flag |= (1 << num);
            if (num > max) {
                max = num;
            }
            if (num < min) {
                min = num;
            }
            if (max - min > 4) {
                return false;
            }
        }
        return true;
    }
}
```