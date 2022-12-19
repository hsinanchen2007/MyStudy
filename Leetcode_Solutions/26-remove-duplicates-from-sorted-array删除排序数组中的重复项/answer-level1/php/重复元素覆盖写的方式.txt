### 解题思路


### 代码

```php
class Solution {

    /**
     * @param Integer[] $nums
     * @return Integer
     */
    function removeDuplicates(&$nums) {
         $len = count($nums);
        if ($len < 2) return $len;

        $ret = [];
        foreach ($nums as $key => $value) {
            $ret[$value] = $value;
        }
        $nums=$ret;
        return count($ret);
    }
}
```