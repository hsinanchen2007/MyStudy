### 解题思路
此处撰写解题思路

### 代码

```php
class Solution {

    /**
     * @param String $haystack
     * @param String $needle
     * @return Integer
     */
    function strStr($haystack, $needle) {
        $len = strlen($haystack);//获取长度
        $length = strlen($needle);//获取长度

        if($haystack == $needle || $length == 0){
            return 0;//如果两个字符串全等，或者needle为空时
        }

        if($len == 0 || $len < $length || $len > 1000){
            return -1;//如果haystack小于needle，或者haystack为空，或超出长度（需要）
        }

        for($i=0;$i<$len;$i++){
            $j = 0;//每次循环时恢复初始值
            while ($haystack[$i+$j] == $needle[$j] && $j < $length){
                $j++;//如果符合要求，就继续判断下一个字符
            }
            if($j == $length){
                return $i;//如果全部符合
            }
        }
        return -1;//如果都不符合
    }
}
```