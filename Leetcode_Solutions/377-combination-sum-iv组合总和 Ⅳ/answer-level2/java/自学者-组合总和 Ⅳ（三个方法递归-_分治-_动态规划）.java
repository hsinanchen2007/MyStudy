### 解题思路
* 递归实现会超时，但是用来区分78题回溯还是有很大价值
* 分治方法性能刚刚够用，也是裁剪思路，分治也是用的递归，只不过增加了一层缓存
* 动态规划待总结

### 代码

```java []
// 方案二、分治实现 - 击败了10.64%的用户
// target有多少组合，分解为（target-选中的数）的组合数
class Solution {
    private int count = 0;
    public int combinationSum4(int[] nums, int target) {
        if (null == nums) {
            return 0;
        }
        // <目标和，组合个数>
        Map<Integer,Integer> cache = new HashMap<>();
        return combinationToSum(nums,target,cache);
    }
    
    /**
     * 组合总和匹配
     */
    private int combinationToSum(int[] nums, int target, Map<Integer,Integer> cache) {
        //超出边界值，返回0代表不是一个有效组合，组合数为0
        if (target < 0) {
            return 0;
        }
        //如果分治分解后正好为0，代表者满足条件
        if (target == 0) {
            return 1;
        }
        
        Set<Integer> set = cache.keySet();
        if(set.contains(target)) {
            // 目标和为target如果计算过了就直接返回，避免重复计算
            return cache.get(target);
        }
        int sum = 0;
        for (int i = 0; i < nums.length; i++) {
            sum += combinationToSum(nums,target-nums[i],cache);
        }
        cache.put(target,sum);
        return sum;
    }
}
```

```java []
// 方案三、 动态规划
class Solution {
    public int combinationSum4(int[] nums, int target) {
        if (null == nums) {
            return 0;
        }

        int length = nums.length;
        int[] cache = new int[target+1];
        cache[0]=1;
        for (int i = 1;i <= target; i++) {
            int temp = 0;
            for (int j=0;j < length; j++) {
                if (i - nums[j]==0){
                    temp++;
                    continue;
                }
                if (i - nums[j] > 0) {
                    temp += cache[i - nums[j]];
                }
            }
            cache[i] = temp;
        }
        return cache[target];
    }
}
```

```java []
// 方案一、递归算法
// TODO: 非常简单，该题目可以用来学习对比回溯算法
class Solution {
    //组合之和等于target个数
    private int count = 0;

    public int combinationSum4(int[] nums, int target) {
        if (nums == null) {
            return 0;
        }
        combinationToSum(nums, 0, target);
        return this.count;
    }

    public void combinationToSum(int[] nums, int lastSum, int target) {
        if (lastSum > target) {
            return;
        }
        if (lastSum == target) {
            this.count++;
            return;
        }
        int length = nums.length;
        for (int i = 0; i < length; i++) {
            int tmpSum = lastSum + nums[i];
            combinationToSum(nums, tmpSum, target);
        }
    }
}
```