### 解题思路
1.双指针法
2.删除法

### 代码

```php
class Solution {

    /**
     * @param Integer[] $nums
     * @return Integer
     */
    #双指针法
    function removeDuplicates(&$nums) {
        $i = 0;
        for($j=1;$j<count($nums);$j++){
            if($nums[$i] != $nums[$j]){
                $i++;
                $nums[$i] = $nums[$j];
            }
        }
        return $i+1;
    }

    #删除法
    function removeDouplicates(&$nums){
        $length = count($nums);
        $tmp = $nums[0];
        for($i=1;$i<$length;$i++){
            if($tmp == $nums[$i]){
                unset($nums[$i]);
            }else{
                $tmp = $nums[$i];
            }
        }
        return count($nums);
    }
}
```