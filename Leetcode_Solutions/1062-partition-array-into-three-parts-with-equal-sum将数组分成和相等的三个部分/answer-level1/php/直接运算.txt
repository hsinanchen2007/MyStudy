### 解题思路
思路同最高票选解，清晰 + 简单

### 代码

```php
class Solution {

    /**
     * @param Integer[] $A
     * @return Boolean
     */
    function canThreePartsEqualSum($A) {
        $size = count($A);
        if($size < 3) return false;//元素数量小于3则直接返回

        for($i=0;$i<$size;$i++){
            $sum += $A[$i];//数组之和
        }

        if($sum%3!=0) return false;//如数组之和不能被3整除，则一定不能三等分

        $target = $sum/3;//目标值为数组总和的三分之一

        $dividers = 0;//分割点，应找到两个，且找到第二个的时候数组还有余下的数字

        $cur_sum = 0;
        for($i=0;$i<$size;$i++){
            $cur_sum += $A[$i];
            if($cur_sum == $target){
                $cur_sum = 0;
                $dividers++;
                if($dividers == 2 && $i<$size-1){
                    return true;
                }
            }
        }

        return false;
    }
}
```