### 解题思路
此处撰写解题思路

### 代码

```java
class Solution {
    public boolean checkPossibility(int[] nums) {
        // 思路：如果nums[i] > nums[i+1],那么这对数影响了序列为非递减。
        // 有两种原因导致，nums[i]太大或者nums[i+1]太小。
        // 要想恢复有两种方法，如果i的元素太大，那么把i的元素改为i-1的元素；如果是因为i+1的元素太小，那么改i+1为i的元素即可。
        int cnt = 0;
        for (int i = 0; i < nums.length - 1; i++) {
            if (nums[i] > nums[i + 1]) {
                int tmp = nums[i];
                if (i >= 1) {
                    nums[i] = nums[i - 1];
                } else {
                    nums[i] = nums[i + 1];
                }
                if (nums[i] > nums[i + 1]) {
                    nums[i] = tmp;
                    nums[i + 1] = nums[i];
                }
                if(++cnt>1){
                    return false;
                }
            }
        }
        return true;
    }
}
```