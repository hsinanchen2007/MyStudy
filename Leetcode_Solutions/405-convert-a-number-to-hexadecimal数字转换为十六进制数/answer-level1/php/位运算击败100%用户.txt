### 解题思路
如：35 == 0010 0011 = 23

### 代码

```php
class Solution {

    /**
     * @param Integer $num
     * @return String
     */
    //执行用时 :8 ms, 在所有 php 提交中击败了63.64%的用户
    //内存消耗 :14.9 MB, 在所有 php 提交中击败了100.00%的用户
    function toHex($num) {
        // 如果是负数，转换成补码形式，比如：-1 + 4294967296 = 4294967295 = 0xffffffff
        if ($num < 0 ){    
            $num += 4294967296;
        }
        $hexString = "0123456789abcdef";
        $s = '';
        while($num != 0){
            $end = $num&15;
            $s = $hexString[$end] . $s;
            //无符号右移,右移赋值
            $num >>=4;
        }
        if(strlen($s) == 0){
            $s = "0";
        }
        return $s;
    }
}
```