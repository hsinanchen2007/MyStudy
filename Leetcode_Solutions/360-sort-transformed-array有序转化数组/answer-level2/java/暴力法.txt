### 解题思路
此处撰写解题思路

### 代码

```java
class Solution {
    public int[] sortTransformedArray(int[] nums, int a, int b, int c) {
        int len = nums.length;
        int[] ans = new int[len];
        for(int i = 0; i< len; i++) {
            ans[i] = a*nums[i]*nums[i] + b*nums[i] + c;
        }
        Arrays.sort(ans);
        return ans;

    }
}
```