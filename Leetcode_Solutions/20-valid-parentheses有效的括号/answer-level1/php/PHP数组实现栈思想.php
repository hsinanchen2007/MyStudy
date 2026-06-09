```
class Solution {

    /**
     * @param String $s
     * @return Boolean
     */
    function isValid($s) {
        $arr = [
            ')'=>'(',
            ']'=>'[',
            '}'=>'{',
        ];
        $count = strlen($s);
        $strack = [];
        for ($i=0;$i<$count;$i++) {
            # 反括号与栈内括号匹配
            if (isset($arr[$s[$i]])) {
                $tmp = array_pop($strack);
                # 入栈括号与该反括号不匹配则为false,直接给出false结果
                if ($arr[$s[$i]] != $tmp) {
                    return false;
                }
            } else {
                #正括号入栈等待匹配
                $strack[] = $s[$i];
            }
        }
        # 全部括号匹配完成,栈内为空则为true
        return $strack ? false : true;
    }
}
```