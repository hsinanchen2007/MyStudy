### 解题思路
参考中心扩展算法，含注释

### 代码

```php
class Solution {

    /**
     * @param String $s
     * @return String
     */
    function longestPalindrome($s)
    {
        $len = strlen($s);
        if ($len < 2) return $s; // 字符串长度小于2的情况

        $begin = 0; // 默认开始下标
        $index = 1; // 默认最长回文数1

        for ($i = 0; $i < $len; $i++) {
            if ($index / 2 > $len - $i) break; // 如果目前最大回文子串长度的1/2大于剩余未遍历的部分，停止遍历
            $single = $this->around($s, $len, $i, $i);
            $double = $this->around($s, $len, $i, $i + 1);

            
            if ($single > $double && $single > $index) { // 如果奇数回文比复数回文长且比以前的最长都长
                $index = $single;
                $begin = $i - intval($single / 2);
            }elseif ($double > $single && $double > $index) { // 如果复数回文比奇数回文长且比以前的最长都长
                $index = $double;
                $begin = $i - intval($double / 2) + 1;
            }
        }
        return substr($s, $begin, $index);
    }

    /**
     * 中心扩散法
     *
     * @param $s
     * @param $s_length
     * @param $left
     * @param $right
     *
     * @return int
     */
    function around($s, $s_length, $left, $right)
    {
        while($left >= 0 && $right < $s_length && $s{$left} == $s{$right}) {
            $left--;
            $right++;
        }

        // 返回回文长度
        return $right - $left - 1;
    }
}
```