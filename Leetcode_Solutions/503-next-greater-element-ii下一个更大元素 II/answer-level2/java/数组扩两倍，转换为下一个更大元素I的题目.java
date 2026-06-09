### 解题思路
此处撰写解题思路

### 代码

```java
class Solution {
    public int[] nextGreaterElements(int[] nums) {
        int[] numTwonum = new int[nums.length * 2];
        numsTwofunction(nums, numTwonum);
        int[] res = new int[nums.length];
        for (int i = 0; i < nums.length; i++) {
            int flag = 0;
            for (int j = i + 1; j < numTwonum.length; j++) {
                if (nums[i] < numTwonum[j]) {
                    res[i] = numTwonum[j];
                    flag = 1;
                    break;
                }
            }
            if (flag == 0){
                res[i] = -1;
            }
        }
        return res;
    }

    private void numsTwofunction(int[] nums, int[] numTwonum) {
        for (int i = 0; i < numTwonum.length; i++) {
            numTwonum[i] = nums[i % nums.length];
        }
    }
}
```