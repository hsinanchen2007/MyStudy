### 解题思路

时间复杂度 O(N)，速度秒杀 90% 以上解题。

### 代码

#### V2.0.0

```php
class Solution {

    /**
     * @param Integer[] $nums
     * @param Integer $target
     * @return Integer[]
     */
    function twoSum($nums, $target) {
        $count = count($nums);
        $queue = [$nums[0] => 0];
        for($i = 1; $i < $count; $i++) {
            $x = $target - $nums[$i];
            if(isset($queue[$x])) return [$queue[$x], $i];
            isset($queue[$nums[$i]]) || $queue[$nums[$i]] = $i;
        }
        return [];
    }
}
```

#### V1.0.0 

```php
class Solution {

    /**
     * @param Integer[] $nums
     * @param Integer $target
     * @return Integer[]
     */
    function twoSum($nums, $target) {
        $count = count($nums);
        $queue = [$nums[0]];
        for($i = 1; $i < $count; $i++) {
            $key = array_search(($target - $nums[$i]), $queue);
            if(false !== $key) return [$key, $i];
            $queue[] = $nums[$i];
        }
        return [];
    }
}
```