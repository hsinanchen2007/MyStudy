### 解题思路
首先获取数组中所有值出现的次数 `$nums = array_count_values($nums);`然后排序  
以上可得出所有值（$nums的key），以及每个值出现的次数（$nums的value）  

然后获取最小key开始从后推`$k`位数，这样一轮后，如果出现不连续则返回`false`,如果连续则把当前值出现的次数减一（如果等于0，则释放掉当前值），然后继续一轮直到完成。  


### 代码

```php
class Solution {

    /**
     * @param Integer[] $nums
     * @param Integer $k
     * @return Boolean
     */
    function isPossibleDivide($nums, $k) {
        if((count($nums) % $k) !== 0)
            return false;
        $nums = array_count_values($nums);
        ksort($nums);
        $result = true;
        while (true) {
            if(empty($nums))
                break;
            $firstNum = key($nums);
            for($i=0;$i<$k;$i++){
                $cKey = $firstNum+$i;
                if(isset($nums[$cKey]) && $nums[$cKey] > 0){
                    $nums[$cKey]--;
                    if($nums[$cKey] == 0)
                        unset($nums[$cKey]);
                }else{
                    $result = false;
                    break;
                }
            }
        }
        return $result;
    }
}
```