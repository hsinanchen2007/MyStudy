### 解题思路
申请一个同样大小的数组，将原数组每一位的值转化为新数组的下标值，如果遇到重复的，则+1，再通过遍历新数组，找到第一个值大于1的数，则它对应的位置下标就是重复的数。

### 代码

```java
class Solution {
    public int findRepeatNumber(int[] nums) {
        int n = nums.length;
        int[] flag = new int[n];
        for (int i = 0; i < n; i++) {
            flag[nums[i]]++;
        }
        int result = 0;
        for (int j = 0; j < n; j++) {
            if (flag[j] > 1){
                result = j;
                break;
            }
        }
        return result;
    }
}
```