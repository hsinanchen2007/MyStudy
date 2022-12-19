### 解题思路
此处撰写解题思路
foreach,对数组进行判断，然后原地删除重复元素，控制重复长度为2
### 代码

```php
class Solution {

    /**
     * @param Integer[] $nums
     * @return Integer
     */
    function removeDuplicates(&$nums) {
        $length = 1;
        foreach($nums as $k=>$v){
            if($v===$nums[$k+1])
            {
                if($length<2)
                    $length +=1;
                else{
                    unset($nums[$k]);
                }
                    
            }else{
                $length = 1;
            }
        }
        return count($nums);
    }
}
```