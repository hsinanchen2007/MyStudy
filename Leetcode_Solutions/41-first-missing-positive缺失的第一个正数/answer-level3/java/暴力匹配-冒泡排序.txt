冒泡排序 
对排序后的数组
1，注意首个索引和尾个索引的值
2，正负交替值的特殊处理
击败14%的用户 

### 代码

```java
class Solution {
    public int firstMissingPositive(int[] nums) {
        if (nums.length < 1) {
            return 1;
        }

        //先来一个暴力算法 先冒泡排序
        for (int i = 0; i < nums.length - 1; i++) {
            for (int j = i+1; j < nums.length; j++) {
                if (nums[i] > nums[j]) {//交换值
                    int temp = nums[i];
                    nums[i]  = nums[j];
                    nums[j]  = temp;
                }
            }
        }
        
        //第一个值大于1
        if (nums[0] > 1) {
            return 1;
        }

        //再次循环遍历改变后的数组 找出最小值
        int minValue = 0;//默认值
        for (int i = 0; i < nums.length - 1; i++) {
            if ((nums[i+1] - nums[i]) >= 2 && (nums[i] >= 0)) {//大于等于2
                 return (nums[i] + 1);
            }

            if (nums[i] < 0 && nums[i+1] > 1) {
                return 1;
            }
        }

        if (minValue == 0) {
             if (nums[nums.length-1] <= 0) {
                 minValue = 1;
             } else {
                 minValue = nums[nums.length-1] + 1;
             }
        }
        
        return minValue;
    }
}
```