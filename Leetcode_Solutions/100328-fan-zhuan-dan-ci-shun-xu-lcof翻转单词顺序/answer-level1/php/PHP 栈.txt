### 解题思路
此处撰写解题思路
本题由于需要倒序输出且过滤中间空格，所以我选择了栈这种数据机构来存储结果，中间的单词按照字符拼接。拼接到字符串之后将该字符串入栈；最后输出结果是，出栈即可，再加上拼接空格
### 代码

```php
class Solution {

    /**
     * @param String $s
     * @return String
     */
    function reverseWords($s) {
        //栈存储 字符串数组
        $len = strlen($s);
        for ($i = 0; $i < $len; $i ++) {
            if ($s[$i] == ' ') {
                if ($tmp) {
                    $arr[] = $tmp;
                    $tmp = '';
                }
            } else {
                $tmp .= $s[$i];
            }
        }
        if ($tmp) {
            $arr[] = $tmp;
        }
        $str = '';
        while (count($arr) > 1) {
            $str .= array_pop($arr);
            $str .= " ";
        }
        $str .= array_pop($arr);
        return $str;
    }
}
```