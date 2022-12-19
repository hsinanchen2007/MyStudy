### 解题思路
此处撰写解题思路

### 代码

```php
class Solution {

    /**
     * @param Integer[] $height
     * @return Integer
     */
    function trap($height) {
        $left  = 0;
        $right = 0;
        $right_max = 0;
        $vol   = 0;
        $tmp = [];
        foreach($height as $key => $value){
            $right = $value;
            if($left <= $right){
                while( !empty($tmp)){
                    $vol += $left - array_pop($tmp);
                }
                $left = $right;

            }else{
                array_push($tmp,$value);
               
            }
        }
        //扫尾工作
        while(!empty($tmp)){
            $tmp_height = array_pop($tmp);
            if($tmp_height <= $right_max){
            	$vol += $right_max -$tmp_height;
            }else{
            	$right_max = $tmp_height;
            }
 
        }

        return $vol;
    }
}
```