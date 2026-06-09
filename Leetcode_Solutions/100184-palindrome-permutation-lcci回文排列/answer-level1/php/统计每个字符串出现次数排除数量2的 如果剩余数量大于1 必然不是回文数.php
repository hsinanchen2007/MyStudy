### 解题思路
此处撰写解题思路

### 代码

```php
class Solution {

    /**
     * @param String $s
     * @return Boolean
     */
    function canPermutePalindrome($s) {
        $arr = str_split($s);
        $arr_counts = array_count_values ($arr);
        foreach($arr_counts as $key =>$value)
        {
            if($value % 2==0)
            {
                unset($arr_counts[$key]);
            }

        }
        if(count($arr_counts)>1)
        {
            return false;
        }
        return true;

    }
}
```