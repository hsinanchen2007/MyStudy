1.如果使用递归做，那么必须列举出所有的路径的可能，找到一条收货最大的路径。
首先定义int[] nums 为每个房屋的坐标及里面的金额集和，index表示小偷在第（index + 1）的房间里。小偷不能偷相邻的！
得出递归公式：
```
在第index + 1个房间上能偷的最大金额 f(index) = nums[index] + Math.max(f(index + 2), f(index + 3));
```
递归边界条件
```
1.当从Begindex = 0 开始偷，边界index < nums.length - 1
2.当从Begindex = 1 开始偷，边界index < nums.length
3.当从Begindex = 2 开始偷，边界index < nums.length
```
代码如下：
```
class Solution {
    public int rob(int[] nums) {
        if(nums.length == 1) {
            return nums[0];
        }
        int max = Math.max(method(nums, 1, true), method(nums, 0, false));
        return Math.max(max, method(nums, 2, true));
    }

    public int method(int[] nums, int index, boolean flag) {
        if(index >= nums.length && flag) {
            return 0;
        }
        if(!flag && index >= nums.length - 1) {
            return 0;
        }
        int max = nums[index] + Math.max(method(nums, index + 2, flag), method(nums, index + 3, flag));
        return max;
    }

}
```
2.存在大量重复计算
3.待备忘录的递归
这个备忘录分两种情况：1.能到达nums.length - 1 2.不能到达nums.length - 1
```
class Solution {
    public static int rob(int[] nums) {
        HashMap<Integer, Integer> hashMap = new HashMap<>();
        if(nums.length == 1) {
            return nums[0];
        }
        int max = Math.max(method(nums, 1, true, hashMap),method(nums, 2, true,hashMap));
        HashMap<Integer, Integer> hashMap1 = new HashMap<>();
        return Math.max(max, method(nums, 0, false,hashMap1));
    }
    public static int method(int[] nums, int index, boolean flag, HashMap<Integer, Integer> hashMap) {
        if(index >= nums.length && flag) {
            return 0;
        }
        if(!flag && index >= nums.length - 1) {
            return 0;
        }
        if(hashMap.containsKey(index)) {
            return hashMap.get(index);
        }
        int max = nums[index] + Math.max(method(nums, index + 2, flag, hashMap), method(nums, index + 3, flag, hashMap));
        hashMap.put(index, max);
        return max;
    }

}
```
4.动态规划
用 dp[] 来记录当前位置所能获得最大的金额数。
```
dp[i] = nums[i] + Math.max(dp[i - 2], dp[i - 3]);
```
有两种状态
```
1.从 0开始 不包含nums.length-1
2.从 1开始 包含nums.length-1
```
代码如下：
```
class Solution {
    public int rob(int[] nums) {
        int length = nums.length;
        if(length == 0) {
            return 0;
        }
        if(length == 1) {
            return nums[0];
        }
        if(length == 2) {
            return Math.max(nums[0], nums[1]);
        }
        return Math.max(method(nums, 0, nums.length - 1), method(nums, 1, nums.length));
    }
    public int method(int[] nums, int begin, int end) {
        int[] dp = new int[nums.length - 1];
        dp[0] = nums[begin];
        dp[1] = nums[begin + 1];
        if(dp.length <= 2) {
            return Math.max(dp[0],dp[1]);
        }
        dp[2] = nums[begin] + nums[begin + 2];
        for (int i = begin + 3, index = 3; i < end; i++,index++) {
            dp[index] = nums[i] + Math.max(dp[index-2], dp[index-3]);
        }
        return Math.max(dp[dp.length - 1], dp[dp.length - 2]);
    }
}
```
