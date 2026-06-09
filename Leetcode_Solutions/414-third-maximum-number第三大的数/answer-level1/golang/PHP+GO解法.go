- 时间复杂度O(n)
- PHP空间复杂度O(1),GO空间复杂度O(n)

```PHP内置函数解法 []
class Solution {

    /**
     * @param Integer[] $nums
     * @return Integer
     */
    function thirdMax($nums) {
        $nums = array_unique($nums);
        rsort($nums);
        $count = count($nums);
        if ($count == 0) return false;
        if ($count == 1) return $nums[0];
        if ($count == 2) return $nums[0] > $nums[1] ? $nums[0] : $nums[1];
        return $nums[2];
    }
}
```
```PHP []
class Solution {

    /**
     * @param Integer[] $nums
     * @return Integer
     */
    function thirdMax($nums) {
        $count = count($nums);
        
        $a=$b=$c=null;
        for ($i=0; $i<$count; $i++) {
            if ($nums[$i] === $a || $nums[$i] === $b || $nums[$i] === $c) {
                continue;
            }
            if ($nums[$i] >= $c) { // 注意 (-424>null)为真
                $c = $nums[$i];
            }

            if ($a < $b) {
                $tmp = $a;
                $a = $b;
                $b = $tmp;
            }

            if ($a < $c) {
                $tmp = $a;
                $a = $c;
                $c = $tmp;
            }

            if ($b < $c) {
                $tmp = $b;
                $b = $c;
                $c = $tmp;
            }
        }
        return $c === null ? $a : $c;
    }
}
```
```GO []
func thirdMax(nums []int) int {
    if len(nums) == 1 {return nums[0]}
    if len(nums) == 2 {
        if nums[0] > nums[1] {
            return nums[0]    
        } else {
            return nums[1]            
        }
    }
    arr := []int{}
	hash := make(map[int]string)
	for _,v := range nums{
		if _, ok := hash[v]; !ok {
			arr = append(arr, v)
			hash[v] = "fuck"
		}
	}
	sort.Ints(arr)
    if len(arr) == 1 {return arr[0]}
    if len(arr) == 2 {
        if arr[0] > arr[1] {
            return arr[0]    
        } else {
            return arr[1]            
        }
    }
    return arr[len(arr)-3]
}
```


