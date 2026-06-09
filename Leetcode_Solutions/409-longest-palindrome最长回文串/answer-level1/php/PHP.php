### 解题思路
此处撰写解题思路
判断是否是回文，也就是判断字符串是否是2的倍数。所以本题的解题思路就很清晰了
1. 遍历字符串，统计各个字符串你的个数，当达到2的时候，累和
2. 最后遍历一遍统计结果，如果有字符串个数为1，在最后再加1
### 代码

```php
class Solution {

    /**
     * @param String $s
     * @return Integer
     */
    function longestPalindrome($s) {
        //ccdadcc
        //统计字符串个数
        $len = strlen($s);
        $arr = [];
        $count = 0;
        for ($i = 0; $i < $len; $i ++) {
            if ($arr[$s[$i]] == 1) {
                $count += 2;
                $arr[$s[$i]] = 0;
            } else {
                $arr[$s[$i]] = 1;
            }
        }
        foreach ($arr as $num) {
            if ($num == 1) {
                $count ++;
                break;
            }
        }
        return $count;
    }
}
```