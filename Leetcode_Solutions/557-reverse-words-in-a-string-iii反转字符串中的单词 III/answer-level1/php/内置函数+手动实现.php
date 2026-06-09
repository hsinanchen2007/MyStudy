### [THINKING]
- 内置函数法
    - 分割然后再合并
    - 每个单词都是一个空格隔开，我们可以使用PHP现成的函数explode进行分割成数组
    - 然后对数组每个单元进行反转
    - 然后impode合并数组单元
- 自己实现反转函数
    - 注意空格位置，只有中间两个字符串单词会隔开一个
    - 首位没有空格
    - 注意边界判断
    - 注意异常判断

### [CODING]
```
class Solution {

    /**
     * @param String $s
     * @return String
     */
     // 执行用时 :40 ms, 在所有 php 提交中击败了13.45%的用户
     // 内存消耗 :15.6 MB, 在所有 php 提交中击败了5.56%的用户
     // 分割+反转+合并
    function reverseWords($s) {
        if(empty($s)) return '';
        $arr = explode(" ",$s);
        foreach ($arr as &$value) {
            $value = $this->reverseString($value);
        }
        unset($value);
        $s = implode(" ",$arr);
        return $s;
    }

    /**
    * 辅助方法  反转某个单独字符串
    * @param String $str 字符串
    * @return String $str 反转后的字符串
    */
    function reverseString($str) {
        $len = strlen($str);
        for($i=0; $i<intval($len/2); $i++) {
            $str[$i]        = $str[$i] ^ $str[$len-$i-1];
            $str[$len-$i-1] = $str[$i] ^ $str[$len-$i-1];
            $str[$i]        = $str[$i] ^ $str[$len-$i-1];
        }
        return $str;
    }

    /**
     * @param String $s
     * @return String
     */
     // 使用内置函数
     // 执行用时 :4 ms, 在所有 php 提交中击败了99.16%的用户
     // 内存消耗 :15.6 MB, 在所有 php 提交中击败了5.56%的用户
    function reverseWords2($s) {
        $arr = explode(" ",$s);
        foreach ($arr as &$value) {
           $value = strrev($value);
        }
        unset($value);
        $s = implode(" ",$arr);
        return $s;
    }



    /**
     * @param String $s
     * @return String
     */
     //
     // 执行用时 :36 ms, 在所有 php 提交中击败了21.01%的用户
     // 内存消耗 :15.2 MB, 在所有 php 提交中击败了16.67%的用户
    function reverseWords3($s) {
       if(empty($s)) return '';
       $len = strlen($s); // 总的字符串长度
       $out = ''; // 最终反转后的字符串
       $sign= 0;  // 上一个空格位置
       for($i=0; $i<$len; $i++) {
            // 如果到 某个空格，或者 遍历到最后一个字符串
            if($s[$i] == ' ' || $i == $len-1 ) {
                // 然后倒叙遍历 到上一个空格位置
                for($j=$i; $j>=$sign; $j--) {
                    if($s[$j] != ' ') $out .= $s[$j];// 追加上去
                }
                // 同时注意 每个空格连接起来的单词 追加上去要加上空格
                if($i != $len-1){ // 最后一个就不需要空格
                      $out .= ' ';
                }
                $sign = $i; // 然后记录这次空格位置
            }
       }
       return $out;
    }



}
$obj = new Solution();
$x   = 'Let\'s take LeetCode contest';
echo $obj->reverseWords3($x);

```
