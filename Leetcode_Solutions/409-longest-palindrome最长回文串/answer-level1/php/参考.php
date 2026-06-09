### 解题思路
此处撰写解题思路

### 代码

```php
class Solution {

    /**
     * @param String $s
     * @return Integer
     */
    function longestPalindrome($s) {
        $s = str_split($s);
        $data = array_count_values($s);
        $max = 0;
        foreach($data as $value){
            $max += intdiv($value,2) * 2;
            if($max%2 == 0 && $value%2 == 1){
                $max+=1;
            }
        }
        return $max;
    }
}
```