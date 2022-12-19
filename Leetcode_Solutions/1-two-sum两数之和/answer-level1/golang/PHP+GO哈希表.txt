- 时间复杂度O(n),空间复杂度O(n)
- 设计hash表,要找的纸=>索引
- 目标值 - 当前值 = 要查找的值
- 存在要查找的值,则返回当前值`i`和hash表中的索引
```PHP []
class Solution {

    /**
     * @param Integer[] $nums
     * @param Integer $target
     * @return Integer[]
     */
    function twoSum($nums, $target) {
        $count = count($nums);
        $hash = [];
        for ($i=0;$i<$count;$i++) {
            $hash[$nums[$i]] = $i;
        }
        
        for ($i=0;$i<$count;$i++) {
            $tem = $target - $nums[$i];
            if (isset($hash[$tem])) {
                return [$i, $hash[$tem]];
            }
        }
    }
}
```
```GO []
func twoSum(nums []int, target int) []int {
    count := len(nums)
    hash := map[int]int{}
    for i:=0;i<count;i++{
        hash[nums[i]] = i
    }
    fmt.Println(hash)
    for i:=0;i<count;i++{
        tem := target - nums[i]
        value,isset := hash[tem]
        if isset && i!=value{
            return []int{i,value}
        }
    }
    return []int{}
} 
```
