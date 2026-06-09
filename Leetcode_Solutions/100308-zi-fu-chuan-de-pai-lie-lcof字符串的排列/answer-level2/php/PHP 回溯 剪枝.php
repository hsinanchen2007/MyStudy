### 解题思路
此处撰写解题思路
排列组合的问题，也可以用回溯的方法来解决，在本题中涉及到剪枝的问题。
1. 设计回溯函数，我的思路是首先将原字符串转化成数组并排序，方便后续剪枝
2. 参数设计，包含三个参数，第一个是原始字符串，第二个拼接后的字符串，第三个是已使用过的字符
3. 结束条件，当第二个参数拼接后的字符串长度等于原始字符串长度，即认为该串符合条件
4. 回溯过程，遍历原始字符串，若在第三个参数中存在，则说明已用过；若当前字符串与前一个字符串相同且前一个字符串未使用，则认为是剪枝条件；下面即正常拼接字符串，进行递归；然后再将拼接的字符去掉，清空条件，进行回溯。
### 代码

```php
class Solution {
    public $arr = [];
    /**
     * @param String $s
     * @return String[]
     */
    function permutation($s) {
        //回溯
        $arr = str_split($s);
        sort($arr);
        
        $this->backtracking($arr ,'', []);
        return $this->arr;
    }

    function backtracking($arr, $str, $arrUsed) {
        if (strlen($str) == count($arr)) {
            $this->arr[] = $str;
            return;
        }
        $len = count($arr);
        for ($i = 0; $i < $len; $i ++) {
            $ch = $arr[$i];
            if (isset($arrUsed[$i])) {
                continue;
            }
            //剪枝
            if (!isset($arrUsed[$i - 1]) && isset($arr[$i - 1]) && $arr[$i] == $arr[$i - 1]) {
                continue;
            }
            $tmp = $str;
            $str .= $ch;
            $arrUsed[$i] = 1;
            $this->backtracking($arr, $str, $arrUsed);
            $str = $tmp;
            unset($arrUsed[$i]);
        }
    }
}
```