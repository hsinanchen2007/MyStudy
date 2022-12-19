### 解题思路
首先对数组进行判空，之后对数组进行**排序**，排序后固定一个数 **nums[i]**，再在i后面定义**L，R**两个索引指针

将满足和为0的 i+L+R 放入 **sum** 中

如果一开始 nums[i]就大于 0，则sum必然不等于 0，结束循环

如果 nums[i] == nums[i-1]，则说明该数字重复，会导致结果重复，所以应该跳过

当 sum == 0 时，如果 nums[L] == nums[L+1] 则会导致结果重复，应该跳过，L++

当 sum == 0 时，如果 nums[R] == nums[R-1] 则会导致结果重复，应该跳过，R--

时间复杂度：O(n^2)


### 代码

```java
class Solution {
    public List<List<Integer>> threeSum(int[] nums) {
        List<List<Integer>> ans = new ArrayList<>();
        int n = nums.length;
        if(nums == null || n < 3){//判空
            return ans;
        }
        Arrays.sort(nums);//排序
        for(int i = 0 ; i < n ; i++){
            if(nums[i] > 0){//如果一开始元素就大于0，后面也全大于0，就结束循环
                break;
            }
            if(i > 0 && nums[i] == nums[i - 1]){//去重
                continue;
            }
            int L = i + 1;
            int R = n - 1 ;
            while(L < R){
                int sum = nums[i] + nums[L] + nums[R];
                if(sum == 0){
                    ans.add(Arrays.asList(nums[i],nums[L],nums[R]));
                    while(L < R && nums[L] == nums[L + 1]){//去重
                        L++;
                    }
                    while(L < R && nums[R] == nums[R - 1]){//去重
                        R--;
                    }
                    L++;
                    R--;
                }else if(sum > 0){
                    R--;
                }else if(sum < 0){
                    L++;
                }
            }
        }
        return ans;
    }
}
```