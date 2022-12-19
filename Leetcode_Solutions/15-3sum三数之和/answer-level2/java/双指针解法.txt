### 解题思路
此处撰写解题思路

### 代码

```java
class Solution {
    public List<List<Integer>> threeSum(int[] nums) {
        List list = new ArrayList();
        int len = nums.length;
        if(len<3 || nums == null){
            return list;
        }
        Arrays.sort(nums);
        for(int i = 0;i<len; i++){
            if(nums[i]>0) break;
            if(i>0 && nums[i] == nums[i-1]) continue;
            int left = i+1;
            int right = len-1;
            while(left < right){
                int sum = nums[i] + nums[left] + nums[right];
                if(sum == 0){
                    list.add(Arrays.asList(nums[i],nums[left],nums[right]));
                    while (left<right && nums[left] == nums[left+1]) left++; 
                    while (left<right && nums[left] == nums[right-1]) right--; 
                    left++;
                    right--;
                }
                else if (sum < 0) left++;
                else if (sum > 0) right--;
            }
        }      
        return list;
    }
}
```