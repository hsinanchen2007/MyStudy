字符串匹配有很多算法
- BF算法O(m*n)
- RK算法O(n)
- BM算法(坏字符,好后缀规则)O(n)
- KMP(好前缀,坏字符,好后缀规则)O(m)
```
class Solution {

    /**
     * @param String $haystack
     * @param String $needle
     * @return Integer
     */
    function strStr($haystack, $needle) {
        if (empty($needle)) return 0;
        $haystackLen = strlen($haystack);
        $needLen = strlen($needle);
        
        $h = $n = 0;
        while ($h < $haystackLen && $n < $needLen) 
        {
            # 匹配字符是否相等
            if ($haystack[$h] == $needle[$n]) {
                $h++; // 主串后移一位
                $n++; // 模式串后移一位
            } else {
                # 匹配失败则重新开始
                $h = $h - $n + 1; // 主串 找到最开始的位置+1
                $n = 0;// 模式串位置重置
            }
            # 如果模式串已经匹配成功则返回主串位置
            if ($n == $needLen) return $h - $n;
        }
        return -1;
    }
}
```
