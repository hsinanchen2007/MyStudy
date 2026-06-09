### 解题思路
此处撰写解题思路

### 代码

```php
class Solution {

    /**
     * @param String $s
     * @return String
     */
    function reverseWords($s) {
        // $s = trim($s);
        // $len = strlen($s);
        // $final = "";
        // $start = 0;
        // $count = 0;
        // $cur_word = "";
        // for($i=0;$i<$len;$i++){
        //     if($s[$i] == " "){
        //         $final = $cur_word . $final;
        //         $cur_word = "";
        //         continue;
        //     }
        //     else{
        //         if($cur_word == "") $cur_word = " ";
        //         $cur_word .= $s[$i];
        //     }

        // }
        // $final = $cur_word . $final;

        //trim去除前后的多余空格，explode以空格为界把所有词分入组（空格本身也是元素）,array_filter把所有空元素去掉
        //array_reverse把数组反向排列，impolode + " "即把所有元素以“ ”连接起来
        return implode(" ",array_reverse(array_filter(explode(" ",trim($s)))));
    }
}
```