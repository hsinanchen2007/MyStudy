### 解题思路
这个思路比较简单，就是用$target减去循环拿出的元素得到差值
然后尝试判断差值是否在剩余数组中

### 代码

```php
class Solution {

    /**
     * @param Integer[] $nums
     * @param Integer $target
     * @return Integer[]
     */
    function twoSum($nums, $target) {
        foreach ($nums as $key => $v1){
            unset($nums[$key]);
            $v2 = $target - $v1;
            if (in_array($v2, $nums)){
                return [$key, array_search($v2, $nums)];
            }
        }
    }
}
```