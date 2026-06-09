### 解题思路
去空然后获取第一个字符，看是否+-号，跟后面的字符串分离开，后面的单独循环，然后拼接判断是否超出边界条件或者不符合整数条件。
这题需要注意很多测试用例，修修改改之后才成功的，还有注意边界条件。

![image.png](https://pic.leetcode-cn.com/ffef4f5f9aa87b53afbb146ee8959dcf6f453df9b3a8b63df62e9420ae1c60fb-image.png)

### 代码

```php
class Solution {

    /**
     * @param String $str
     * @return Integer
     */
    function myAtoi($str) {
        $str = trim($str);
        if (empty($str)) {
            return 0;
        }
        $first = substr($str, 0,1);
        $f = '';
        if (!is_numeric($first)) {
            if ($first != '-' && $first != '+' ) {
                return 0;
            }else{
                $f = $first;
                $str = substr($str, 1);
                if (strlen($str) == 0) {
                    return 0;
                }
            }
        }
        $num = '';
        $res = '';
        for ($i=0; $i < strlen($str); $i++) { 
            if (!is_numeric($str[$i])) {
                break;
            }
            $num = $num.$str[$i];
            $res = $f.$num;
            if ($res >= (pow(2, 31)-1)) {
                $res = pow(2, 31) - 1;
                break;
            }
            if ($res <= -pow(2, 31)) {
                $res = -pow(2, 31);
                break;
            }
        }
        if (!is_int(intval($res))) {
            return 0;
        }
        return intval($res);
    }
}
```

