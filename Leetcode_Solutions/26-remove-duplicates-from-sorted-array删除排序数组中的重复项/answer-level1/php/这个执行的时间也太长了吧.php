### 解题思路
直接写的

### 代码

```php
class Solution {

    /**
     * @param Integer[] $nums
     * @return Integer
     */
    function removeDuplicates(&$nums) {
        foreach($nums as $key=>$value){
            $index=array_search($value,$nums);

            if($index!=$key){
                unset($nums[$key]);
            }
        }
    }
}
```