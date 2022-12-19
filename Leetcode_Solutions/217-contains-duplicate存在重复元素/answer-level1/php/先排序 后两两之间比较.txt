### 解题思路
此处撰写解题思路

### 代码

```php
class Solution {

    /**
     * @param Integer[] $nums
     * @return Boolean
     */
    function containsDuplicate($nums) {
        sort($nums);
        $length = count($nums);
        for($a = 0;$a<$length-1;$a++){
           if($nums[$a] == $nums[$a+1]){
               return true;
           }
        }
        return false;
    }
}
```