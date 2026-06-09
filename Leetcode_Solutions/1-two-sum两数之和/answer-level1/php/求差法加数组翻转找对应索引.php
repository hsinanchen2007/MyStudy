### 解题思路
#### 求和法需要用到两次遍历，执行用时明显较高，而求差法只需要使用一次遍历，执行用时较低。
#### 但是求差法我的思路需要使用值去查找对应的索引，这里使用 ```array_flip(array)```对数组进行翻转，从而查找对应的key。
#### 执行用时和内存消耗都相对均衡。

### 代码

```php
class Solution {

    /**
     * @param Integer[] $nums
     * @param Integer $target
     * @return Integer[]
     */
    function twoSum($nums, $target) {
        $numCount = count($nums);
        for ($i = 0; $i < $numCount; $i++){
            $targetVal = $target - $nums[$i];
            if (in_array($targetVal, $nums)){
                $reverseArray = array_flip($nums);
                if (isset($reverseArray[$targetVal]) && $reverseArray[$targetVal] != $i) {
                    return [$i, $reverseArray[$targetVal]];
                }
            }
        }
    }
}
```