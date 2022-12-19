### 解题思路
1.需要注意的点就是数组中可能有重复元素，所以检验的时候，如果是自己不可以，必须2个数字的key不同才可以
2.返回的时候判断下大小，小的先返回

### 代码

```php
class Solution {

    /**
     * @param Integer[] $nums
     * @param Integer $target
     * @return Integer[]
     */
    function twoSum($nums, $target) {
       foreach ($nums as $k => $v) {
            if (in_array($target - $v, $nums)) {
                $temp = array_search($target - $v, $nums);
                if ($temp != $k) {
                    if ($k > $temp) {
                        return [$temp, $k];
                    } else {
                        return [$k, $temp];
                    }

                }
            }
        }
    }
}
```