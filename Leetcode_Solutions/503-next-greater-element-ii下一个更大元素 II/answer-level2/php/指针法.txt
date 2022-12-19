### 解题思路
未使用题解的 栈来解答，利用指针逐步位移计算

### 代码

```php
class Solution {

    /**
     * @param Integer[] $nums
     * @return Integer[]
     */
    function nextGreaterElements($nums) {
        $cnt = count($nums);
        $ret = [];
        for ($i=0; $i < $cnt; $i++) { 
            $j = $i + 1;
            $len = 0;
            while (1) {
                if($j >= $cnt){
                    $j = 0;
                }
                if($nums[$j] > $nums[$i]){
                    $ret[] = $nums[$j];
                    break;
                }else{
                    $j ++;
                    $len ++;
                }
                if($len >= $cnt){
                    $ret[] = -1;
                    break;
                }
            }
        }
        return $ret;
    }
}
```