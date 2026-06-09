### 解题思路
自定义排序思路；双指针分别对对比的两个数字字符串的字符进行大小比较。

### 代码

```php
class Solution {

    /**
     * @param Integer[] $nums
     * @return String
     */
    function largestNumber($nums) {
        usort($nums,function($a,$b){
            $as = (string)($a);
            $bs = (string)($b);

            $al = strlen($as);
            $bl = strlen($bs);

            if( $al == $bl){
                return $bs > $as ? 1 : 0;
            }
            //double pointer;;
            $acp = 0;
            $bcp = 0;

            for($i=0;$i<$al+$bl;$i++){
                if($bs[$bcp] > $as[$acp] ){
                    return 1;
                } else if($bs[$bcp] < $as[$acp]) {
                    return 0;
                }

                    $acp++;
                    $bcp++;
                    if($bcp == $bl){
                        $bcp = 0;
                    }
                    if($acp == $al){
                        $acp = 0;
                    }
            }

            if( $bs[$bl-1] > $as[0] ){
                return 1;
            }

        });

        if( $nums[0] == 0){
            return "0";
        }
        $str = "";
        foreach($nums as $v) {
            $str .= $v;
        }

        return $str;
    }

}
```