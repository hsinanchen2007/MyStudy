### 解题思路
将index数组中的每一项遍历, 判断在插入后实际对应的下标位置得到($_tmp_index), 然后通过该映射写入到结果中 

### 代码

```php
class Solution {

    /**
     * @param Integer[] $nums
     * @param Integer[] $index
     * @return Integer[]
     */
    function createTargetArray($nums, $index) {
        $target = [];

        $_tmp_indexs = [];
        foreach ($index as $i => $k) {
            if (in_array($k, $_tmp_indexs)) {
                foreach ($_tmp_indexs as &$_tmp_index) {
                    if ($_tmp_index >= $k) {
                        $_tmp_index ++;
                    }
                }
            }
            $_tmp_indexs[] = $k;
            $target[$i] = false;
        }
        
        foreach ($_tmp_indexs as $i => $k) {
            $target[$k] = $nums[$i];
        }
        
        return $target;
    }
}
```