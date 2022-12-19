### 解题思路
解法 1：两次循环，暴力解法
解法 2： 利用一个辅助数组，类似 hash


### 代码 1

```php
class Solution {

    /**
     * @param Integer[] $nums
     * @param Integer $target
     * @return Integer[]
     */
    function twoSum($nums, $target) {
        // 暴力解法
        $length = count($nums);
        for ($i = 0; $i < $length -1; ++$i) {
            for ($j = $i + 1; $j < $length; ++$j) {
                if ($nums[$i] + $nums[$j] == $target) {
                    return [$i, $j];
                }
            }
        }

        return [];
    }
}
```

### 代码 2

```php
class Solution {

    /**
     * @param Integer[] $nums
     * @param Integer $target
     * @return Integer[]
     */
    function twoSum($nums, $target) {
        // 辅助数组，记录遍历到的 $nums, 键值颠倒
        $found = [];
        // foreach 效率高于 for
        foreach ($nums as $i => $v) {
            $diff = $target - $v;
            // isset 效率高于 array_key_exists
            if (isset($found[$diff])) {
                return [$found[$diff], $i];
            }

            $found[$v] = $i;
        }
        return $found;
    }
}
```