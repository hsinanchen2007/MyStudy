### 解题思路
**思想：先排序,再使用双指针遍历，注意去除重复的组合情况**
1. 先固定三个元素的最小的元素`nums[i]`;
- 如果当前元素大于`0`，则三数之和肯定大于`0`，直接退出循环;
- 如果`i > 0`且 `nums[i] == nums[i-1]`，也直接跳过，因为前一次遍历已经考虑了当前的所有组合情况;
2. 再设置两个指针`left`和`right`,其中`left`指向`nums[i]`的后面，`right`则指向数组的末尾；
- 如果当前三个数之和等于`0`,把结果保存到结果集中，并去除重复组合后继续遍历下一个组合；
- 如果当前三个数之和小于`0`，则需要把`left`前移，寻找更大的数的组合；
- 如果当前三个数之和大于`0`，则需要把`right`后移，寻找更小的数的组合；


### 代码

```java
class Solution {
    public List<List<Integer>> threeSum(int[] nums) {
        List<List<Integer>> ans = new ArrayList<>();
        int len = nums.length;
       if(nums == null || len < 3){//特殊情况
           return ans;
       }
       Arrays.sort(nums);
       for(int i=0;i<len-2;i++){
           if(nums[i] > 0){
               break;
           }
           if(i > 0 && nums[i] == nums[i-1]){
               continue;
           }
           int left = i+1;
           int right = len-1;
           while(left<right){
               int sum = nums[i]+nums[left]+nums[right];
            if(sum == 0){
                ans.add(Arrays.asList(nums[i],nums[left],nums[right]));
              
               while(left<right&& nums[left] == nums[left+1]){
                   ++left;
               }
               while(left<right&& nums[right] == nums[right-1]){
                   --right;
               }
               ++left;
               --right;
            }
            else if(sum < 0){
                ++left;
            }
            else if(sum > 0){
                --right;
            }
           }
       }
        
    return ans;

    }
}
```