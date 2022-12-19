### 解题思路
1. 思路 1 :暴力解法，枚举所有可能的情况，找出最大值
2. 思路2 :  双指针法，从两侧向中间逼近，如果内部高度不如当前高度，就停止查找


### 代码

```php
class Solution {

    /**
     * @param Integer[] $height
     * @return Integer
     */
//    function maxArea($height)
//    {
//        if (empty($height)) {
//            return 0;
//        }
//        // 思路 1：暴力解法，枚举所有可能的情况
//        $max = 0;
//        $count = count($height);
//        for ($i = 0; $i < $count; ++$i) {
//            for ($j = $i + 1; $j < $count; ++$j) {
//                $max = max($max, $this->getArea($i, $j, $height));
//            }
//        }
//        return $max;
//    }
//
//    private function getArea(int $i, int $j, array $height): int
//    {
//        return ($j - $i) * min($height[$i], $height[$j]);
//    }

    function maxArea($height)
    {
        if (empty($height)) {
            return 0;
        }

        $max = 0;
        // 思路二，双指针法，从两侧向中间逼近，如果内部高度不如当前高度，就停止查找
        for ($i = 0, $j = count($height) - 1; $i < $j;) {
            // 哪个高度小，就从哪个方向向中间查找 
            // 啰嗦一点，但是容易理解
            if ($height[$i] > $height[$j]) {
                $minHeight = $height[$j];
                $area = ($j - $i) * $minHeight;
                $j--;
            } else {
                $minHeight = $height[$i];
                $area = ($j - $i) * $minHeight;
                $i++;
            }

            if ($area > $max) {
                $max = $area;
            }
        }
        return $max;
    }
}
```