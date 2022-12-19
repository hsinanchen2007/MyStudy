### 解题思路
此处撰写解题思路

### 代码

```php
class Solution {

    /**
     * @param String[] $s
     * @return NULL
     */
    //function reverseString(&$s) {
        /*-- 基础循环
        $str_size = $counter = sizeof($s);
        $i = 0;
        $j = $str_size - 1;
        while ($i<$j){
            $temp = $s[$i];
            $s[$i] = $s[$j];
            $s[$j] = $temp;
            $i++;
            $j--;  
        }
        */

        //递归 -- 超时
    //    if (sizeof($s) == 0) { return; } 
    //    $tmp = $s[0]; 
    //    unset($s[0]);
    //    $this->reverseString($s);
    //    array_push($s,$tmp); 

    //}

    function reverseString(&$s) {
        $this->swap(0, count($s)-1, $s);
        
    }

    //加上&保留运算
    function swap($start, $end, &$s) {
        if($start >= $end){
            return;
        }
        
        $temp = $s[$start];
        $s[$start] = $s[$end];
        $s[$end] = $temp;
        $this->swap($start+1, $end-1, $s);
    }
}
```