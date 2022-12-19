### 解题思路
#### 哈希表解法
1. 遍历数组，使用一个哈希表记录遍历到的元素（值 => 索引）
2. 遍历的同时查询差值是否在哈希表中存在，找到直接返回，提前终止遍历

#### 双指针解法
1. 由于数组是排好序的，考虑使用双指针解法
2. 使用左右两个指针，向中间逼近，计算访问到的两数之和
3. 小于目标值，则左指针右移；大于目标值，则右指针左移
4. 等于目标值，直接返回，提前终止遍历

> 注意；索引的下标从 1 开始

### 代码 1

```php
class Solution {
    function twoSum($numbers, $target) {
        $length = count($numbers);
        $hash = [];
        for ($i = 1; $i <= $length; ++$i) {
            $diff = $target - $numbers[$i - 1];
            if (isset($hash[$diff])) {
                if ($i < $hash[$diff]) {
                    return [$i, $hash[$diff]];
                } else {
                    return [$hash[$diff], $i];
                }
            }

            if (!isset($hash[$numbers[$i - 1]])) {
                $hash[$numbers[$i - 1]] = $i;
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
     * @param Integer[] $numbers
     * @param Integer $target
     * @return Integer[]
     */
    function twoSum($numbers, $target) {
        // 双指针
        $length = count($numbers);
        $left = 0;
        $right = $length - 1;
        while ($left < $right) {
            $sum = $numbers[$left] + $numbers[$right];
            if ($sum == $target) {
                return [++$left, ++$right];
            } elseif ($sum > $target) {
                $right--;
            } else {
                $left++;
            }
        }

        return [];
    }
}
```