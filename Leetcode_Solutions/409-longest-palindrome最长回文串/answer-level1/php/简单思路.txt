### 解题思路
1. 一定关于两边对称
2. 如果出现的次数是偶数直接加起来
3. 如果是奇数，得选一个做为中点，中点只能一个
4. 如果已经选过中点，再碰到奇数的都需要减去 一个，剩余加起来

### 代码

```php
class Solution {

    /**
     * @param String $s
     * @return Integer
     */
    function longestPalindrome($s) {
    if(empty($s)) return 0;
    $arr = str_split($s);
    $valueNum = array_count_values($arr);
    $count = 0;
    $mid = false;
    foreach ($valueNum as $key => $value) {
        if($value % 2 != 0 && !$mid){
            $count += $value;
            $mid = true;
        }else if($value % 2 != 0 ){
            $count += $value-1;
        } 

              if($value % 2 == 0){
            $count += $value; 
        }
    }
    return $count ;
    }
}
```