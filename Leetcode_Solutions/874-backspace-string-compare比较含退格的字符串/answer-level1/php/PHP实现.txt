### 结果
执行用时: 8 ms, 在所有 PHP 提交中击败了 89.47% 的用户
内存消耗: 15.1 MB, 在所有 PHP 提交中击败了 27.27% 的用户

### 思路
用栈的方式去处理。

### 代码
```
class Solution {

    /**
     * @param String $S
     * @param String $T
     * @return Boolean
     */
    function backspaceCompare($S, $T) {
        
        $tmpS = '';
        for($i=0; $i<strlen($S); ++$i){
            if($S[$i] == '#'){
                //出栈
                $tmpS = substr($tmpS, 0, strlen($tmpS) - 1);
            } else {
                //入栈
                $tmpS .= $S[$i];
            }
        }

        $tmpT = '';
        for($i=0; $i<strlen($T); ++$i){
            if($T[$i] == '#'){
                //出栈
                $tmpT = substr($tmpT, 0, strlen($tmpT) - 1);
            } else {
                //入栈
                $tmpT .= $T[$i];
            }
        }

        if($tmpS != $tmpT){
            return false;
        }

        return true;
    }
}
```