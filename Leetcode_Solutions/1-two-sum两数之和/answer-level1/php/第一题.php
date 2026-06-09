### 解题思路
看完题目立即想到的，肯定有改进空间，8ms，内存15m

### 代码

```php
class Solution {

    /**
     * @param Integer[] $nums
     * @param Integer $target
     * @return Integer[]
     */
    function twoSum($nums, $target) {
        for($i=0;$i<count($nums);$i++){
            for($j=0;$j<count($nums);$j++){
                if($i==$j){
                    break;
                }
                if($nums[$i]+$nums[$j]==$target){
                    return [$j,$i];
                }
            }
        }
    }
}
```