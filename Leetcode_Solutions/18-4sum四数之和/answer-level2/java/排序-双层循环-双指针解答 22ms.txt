```
class Solution {
    public List<List<Integer>> fourSum(int[] nums, int target) {
        // 思路：先排序，然后使用双层循环固定两个数，然后使用双指针去查找最合适的数
        Arrays.sort(nums); // 排序
        int l = nums.length; // 数组总长度
        List<List<Integer>> res = new ArrayList<>(); // 返回的结果
        int pointer1 = 0; // 指针1
        int pointer2 = 0; // 指针2
        for (int i = 0; i <= l-4; i++){ // 第一层循环
            if (nums[i]*4 > target) {
                return res;
            }
            // 重复的数 跳出本次循环
            if(i > 0 && nums[i] == nums[i - 1]){
                continue;
            }
            for (int j = i+1; j <= l-3; j++){ // 第二层循环
                // 1.重复的数 跳出本次循环 注意:j<i+1, 规避情况nums[i]==ums[j]
                // 2.最大值解法 j后面的一定大于等于j， 全部排除
                if(j > i+1 && nums[j] == nums[j - 1] || nums[i] + nums[j]*3 > target){
                    continue;
                }

                pointer1 = j+1; // 指针一赋值
                pointer2 = l-1; // 指针二赋值
                while (pointer1 < pointer2){
                    int sum = nums[i]+nums[j]+nums[pointer1]+nums[pointer2];
                    if (sum > target){
                        while (pointer1 < pointer2 && nums[pointer2] == nums[--pointer2]);
                    } else if (sum < target) {
                        while (pointer1 < pointer2 && nums[pointer1] == nums[++pointer1]);
                    } else {
                        List<Integer> answer = new ArrayList<>();
                        answer.add(nums[i]);
                        answer.add(nums[j]);
                        answer.add(nums[pointer1]);
                        answer.add(nums[pointer2]);
                        res.add(answer);
                        while (pointer1 < pointer2 && nums[pointer2] == nums[--pointer2]);
                        while (pointer1 < pointer2 && nums[pointer1] == nums[++pointer1]);
                    }
                }
            }
        }
        return res;
    }
}
```
