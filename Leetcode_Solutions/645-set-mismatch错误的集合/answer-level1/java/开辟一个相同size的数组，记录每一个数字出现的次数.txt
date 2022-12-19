### 解题思路
开辟一个相同size的数组,记录每一个数字出现的次数，最后出现两次的就是重复的数字，出现0次的就是缺失的数字

### 代码

```java
class Solution {
    public int[] findErrorNums(int[] nums) {
        // 开辟一个相同size的数组
        int[] newNums = new int[nums.length];
        for(int i = 0;i < nums.length;i++) {
            newNums[nums[i] - 1]++;
        }
        int dup = 0;
        int lost = 0;
        for(int i = 0;i < newNums.length;i++) {
            if(newNums[i] == 2) {
                dup = i;
            } else if(newNums[i] == 0) {
                lost = i;
            }
        }
        return new int[]{dup + 1, lost + 1};
    }
}
```