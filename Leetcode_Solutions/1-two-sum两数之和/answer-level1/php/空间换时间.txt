### 解题思路
最好时长4ms，内存占用有点高
### 代码

```php
class Solution {

    /**
     * @param Integer[] $nums
     * @param Integer $target
     * @return Integer[]
     */
    function twoSum($nums, $target) {
        $tmp =[];
        $index =[];
        foreach ($nums as $key => $val) {
            if (isset($tmp[$target-$val])) {
                $index = [$tmp[$target-$val], $key];
                break;
            }

            $tmp[$val] = $key;
        }
        return $index;
    }
}
```