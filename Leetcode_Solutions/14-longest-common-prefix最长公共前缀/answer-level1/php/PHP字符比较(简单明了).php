```
class Solution {

    /**
     * @param String[] $strs
     * @return String
     */
    function longestCommonPrefix($strs) {
        $count = count($strs);// 数组总数
        $first = $strs[0];// 第一个字符串
        $strlenFirst = strlen($first);// 第一个字符串长度
        $out = '';// 公共前缀变量
        # 循环第一个字符串
        for ($i=0;$i<$strlenFirst;$i++) {
            $tmp = $first[$i];// 字符串第一个字符
            # 遍历数组
            for ($j=1;$j<$count;$j++) {
                # 判断字符串字符是否相等,不相等则直接返回,相等则在循环外拼接公共前缀
                if ($strs[$j][$i] != $tmp) {
                    return $out;
                }
            }
            # 制作公共前缀
            $out .= $tmp;
        }
        # 返回公共前缀
        return $out;
    }
}
```
