### 解题思路
取数组正数，去重复，按大小排序

### 代码

```php
class Solution {

    /**
     * @param Integer[] $nums
     * @return Integer
     */
    function firstMissingPositive($nums) {
        for($i=0;$i<count($nums);$i++){
            if($nums[$i]>0){
                $newnums[] = $nums[$i];
            }
        }
        $newnums = array_unique($newnums);
        sort($newnums);
        for($j=1;$j<count($newnums)+2;$j++){
            if($j!==$newnums[$j-1]){
                return $j;die;
            }
        }
    }
}
```