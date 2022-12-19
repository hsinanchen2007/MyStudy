暴力法：
1.首先升序排列
2.取两个指针 left 和 right 指向最左边和最右边
3.将所有数存进 map 中
4.如果 0 - nums[left] - nums[right] < 0, 则 right--; 反之则 left++。

缺点是：超出时间限制　TAT
```
class Solution {
    public List<List<Integer>> threeSum(int[] nums) {
        Arrays.sort(nums); // 对数组进行升序排列 
        // -3 -2 0 1 2 3 5
        List<List<Integer>> ans = new ArrayList<>();
        int len = nums.length;
        int left = 0;
        int right = len - 1;
        
        Map<Integer, Integer> map = new HashMap<>();
        for (int i = 0; i < len; i++){
            map.put(nums[i], i);
        }

        while (left + 1 < right && nums[left] <= 0 && nums[right] >= 0){
            // -1 -1 2
            int remain = 0 - nums[left] - nums[right];
            if  (map.containsKey(remain) && ( 
                                                ((remain < nums[right]) && (remain > nums[left])) 
                                                ||                  
                                                ( 
                                                    map.get(remain) > left 
                                                    && 
                                                    ( 
                                                        (map.get(remain) < right) 
                                                        || 
                                                        (map.get(remain) == right && nums[map.get(remain) - 1] == remain)
                                                    )
                                                )
                                            )
                ){

                List<Integer> tmp = new ArrayList<>();
                tmp.add(nums[left]);
                tmp.add(remain);
                tmp.add(nums[right]);
                ans.add(tmp);            
            } 

            if (remain < 0){
                while ((right > 1) && nums[right - 1] == nums[right])
                    right--;
            } else {
                while ((left < len - 1) && nums[left + 1] == nums[left])
                    left++;
            }
        }

        return ans;
    }
}
```
