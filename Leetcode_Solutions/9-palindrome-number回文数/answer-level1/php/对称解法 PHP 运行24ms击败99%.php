解题思路：
- 特殊情况判断
1. 负数肯定不是回文数；
2. 个位数一定是回文数；
- 利用回文数的对称性，判断左右两边对应的数值是否相等；
- 利用PHP中字符串可以当做字符数组使用的特性，实现回文数对称位置的数值对比；

```
    /**
     * @param Integer $x
     * @return Boolean
     */
    function isPalindrome($x) {
        # 负数不是回文数
        if($x < 0) {
            return false;
        }
        # 个位数一定是回文数
        if($x < 10) {
        	return true;
        }

        $str = (string)$x;
        $num_len = strlen($str);
        $middle = intval($num_len/2);
        if($num_len%2 > 0) { # 长度为奇数
            $left = $middle-1;
            $right = $middle+1;
        } else { # 长度为偶数
            $left = $middle-1;
            $right = $middle;
        }

        for($i=0; $i<$middle; $i++) {
            if($str[$left]!=$str[$right]) {
                return false;
            }
            $left--;
            $right++;
        }
        
        return true;
```
