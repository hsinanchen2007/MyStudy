### 解题思路
此处撰写解题思路
根据提供的hash表解决方法思路来的
### 代码

```php
class Solution {

    /**
     * @param Integer[] $nums
     * @param Integer $target
     * @return Integer[]
     */
    function twoSum($nums, $target) {
        //hash表的方式
        for($i = 0;$i < count($nums);$i++){
            $arr[$nums[$i]] = $i;
        }
        for($i = 0;$i < count($nums);$i++){
            $l = $target-$nums[$i];
            if(array_key_exists($l,$arr) && $arr[$l] != $i){
                return [$i,$arr[$l]];
            }
        }
    }
}
```