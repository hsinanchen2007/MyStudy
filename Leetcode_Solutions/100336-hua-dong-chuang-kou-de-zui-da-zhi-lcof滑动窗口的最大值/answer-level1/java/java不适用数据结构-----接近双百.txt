思路：暴力解题，外加trick，用maxInd记录遍历过的最大元素的索引，避免重复遍历查询。
各位大神，看看有么有能继续优化的地方，希望能达到双百~~
```
class Solution {
    public int[] maxSlidingWindow(int[] nums, int k) {
        int len = nums.length;
        if (len == 0 || k == 0) return nums;
        int[] res = new int[len - k + 1];
        int maxInd = -1, max = Integer.MIN_VALUE;
        for (int i = 0; i < len - k + 1; i++) {       
            if (maxInd >= i && maxInd < i + k) {
                //判断最右侧划窗的值，滑窗前面的值已经不用判断了，得益于maxInd
                if (nums[i + k - 1] > max) {
                    max = nums[i + k - 1];
                    maxInd = i + k - 1;
                }
            }else{
                //第一轮走
                max = nums[i];
                for ( int j = i + 1; j < i + k; j++) {
                    if (nums[j] > max) {
                        max = nums[j];
                        //实时更新maxInd
                        maxInd = j;
                    }
                }
            }
            res[i] = max;
        }
        return res;
    }
}
```
