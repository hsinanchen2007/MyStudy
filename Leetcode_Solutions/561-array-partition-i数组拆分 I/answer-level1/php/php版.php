### 解题思路
此处撰写解题思路

### 代码

```php
class Solution {

    /**
     * @param Integer[] $nums
     * @return Integer
     */
    function arrayPairSum($nums) {
        sort($nums);
        $all =  0;
        foreach($nums as $k=>$v){
            if($k%2 == 0){
                $all += $v;
            }
        }
        return $all;
    }
}
```