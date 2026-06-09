### 题目要求如下：
给定一个包含 n 个整数的数组 nums，判断 nums 中是否存在三个元素 a，b，c ，使得 a + b + c = 0 ？找出所有满足条件且不重复的三元组。

注意：答案中不可以包含重复的三元组。
```
例如, 给定数组 nums = [-1, 0, 1, 2, -1, -4]，

满足要求的三元组集合为：
[
  [-1, 0, 1],
  [-1, -1, 2]
]
```
### 代码实现如下：
PHP：
```
class Solution {

    /**
     * @param Integer[] $nums
     * @return Integer[][]
     */
    function threeSum($nums) {
        if( !count($nums) ) return [];
        sort($nums);
        $ret = [];
        for($i = 0;$i < count($nums)-2;$i++){
            if($i>0 && $nums[$i] == $nums[$i-1]) continue;
            $left = $i+1;
            $right = count($nums)-1;
            //因为$nums[$left] + $nums[$right] + $nums[$i] = 0
            $need = 0 - $nums[$i]; 
            while( $left < $right){
                if($nums[$left] + $nums[$right] == $need){
                    array_push($ret,[$nums[$i],$nums[$left],$nums[$right]]);
                    while( $left < $right && $nums[$left] == $nums[$left+1]) $left++;                    
                    while( $left < $right && $nums[$right] == $nums[$right-1]) $right--;
                    $left++;
                    $right--;
                }else if($nums[$left] + $nums[$right] > $need){
                    $right--;
                }else{
                    $left++;
                }
            }
        }
        return $ret;
    }
}
```
Python:
```
class Solution:
    def threeSum(self, nums: List[int]) -> List[List[int]]:
        if not nums:
            return []
        nums.sort()
        ret = []
        
        for i in range(len(nums)-1):
            if i>0 and nums[i] == nums[i-1]:
                continue
            left = i + 1
            right = len(nums)-1
            need = 0 - nums[i]
            while left < right:
                res = nums[left] + nums[right]
                if res == need:
                    ret.append([nums[i],nums[left],nums[right]])
                    while left < right and nums[left] == nums[left+1]:
                        left += 1
                    while left < right and nums[right] == nums[right-1]:
                        right -= 1
                    left += 1
                    right -= 1
                elif nums[left] + nums[right] > need:
                    right -= 1
                else:
                    left += 1
        return ret
```