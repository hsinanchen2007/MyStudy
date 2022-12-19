根据题意，output[i]的值为前面的乘积乘以后面的乘积，因此可以使用动态规划来求解。
以输入[1,2,3,4]为例
dpStart = [24, 24, 12, 4]
dpEnd = [1, 2, 6, 24]
ans = [24, 12, 8, 6]
不难发现 ans[i] = dpEnd[i-1] * dpStart[i+1]
注意处理头尾两个元素的情况。

三次遍历，满足O(n)的要求，并且没有使用除法。
```
class Solution {
    public int[] productExceptSelf(int[] nums) {
        int[] dpStart = new int[nums.length]; //以i作为起点的乘积
        int[] dpEnd = new int[nums.length]; //以i作为终点的乘积
        int[] ans = new int[nums.length]; 

        dpStart[nums.length-1] = nums[nums.length-1]; //以最后一个数开始的乘积是它本身
        dpEnd[0] = nums[0]; //以第一个数结尾的乘积就是它自身

        for (int i = 1; i < nums.length; i++) {
            dpEnd[i] = dpEnd[i-1]*nums[i];
        }

        for (int i = nums.length-2; i >= 0; i--) {
            dpStart[i] = dpStart[i+1]*nums[i];
        }

        for (int i = 0; i < nums.length; i++) {
            int start = i > 0 ? dpEnd[i-1] : 1;
            int end = i < nums.length-1 ? dpStart[i+1] : 1;
            ans[i] = start * end; 
        }
        return ans;
    }
}
```
