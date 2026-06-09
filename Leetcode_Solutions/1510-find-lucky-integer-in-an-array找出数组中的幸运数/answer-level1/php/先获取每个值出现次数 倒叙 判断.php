### 解题思路
此处撰写解题思路

### 代码

```php
class Solution {

    /**
     * @param Integer[] $arr
     * @return Integer
     */
    function findLucky($arr) {
        $arr_count = array_count_values($arr);
        krsort($arr_count);
        foreach($arr_count as $key=>$v)
        {
            if($v==$key)
            {
                return $v;
            }
        }
        return -1;
    }

}
```