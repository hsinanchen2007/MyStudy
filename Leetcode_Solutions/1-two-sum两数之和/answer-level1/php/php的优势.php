### 解题思路
array_key_exists实在是非常妙

### 代码

```php
class Solution {

    /**
     * @param Integer[] $nums
     * @param Integer $target
     * @return Integer[]
     */
    function twoSum($nums, $target) {
        $scanned = [];//建立一个搜寻表

        for ($i = 0; $i < count($nums); $i++) {
            $diff = $target - $nums[$i];//当前数字与目标值的差

            if (array_key_exists($diff, $scanned)) {//搜寻表中找到与差相同的值，则返回其index
                return [$scanned[$diff], $i];
            }

            $scanned[$nums[$i]] = $i;//把扫描过的数字其index和值存入搜寻表中
        }

    }
}
```