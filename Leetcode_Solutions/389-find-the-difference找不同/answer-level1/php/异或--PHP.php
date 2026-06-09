### 解题思路
同只出现一次元素的那道题。相同的数异或完就是0。$t比$s多一个字符，这里先取出$t最后一个元素，一次遍历即可。
```
php -r 'echo "0" ^ "a" ^ "a" ^ 4;'

4
```
关于位运算可参考：[http://niliu.me/articles/2070.html](http://niliu.me/articles/2070.html)

### 性能
执行用时 :8 ms, 在所有 php 提交中击败了79.41%的用户
内存消耗 :15 MB, 在所有 php 提交中击败了20.00%的用户

### 代码

```php
class Solution {

    /**
     * @param String $s
     * @param String $t
     * @return String
     */
    function findTheDifference($s, $t) {
        $res = $t[strlen($t) - 1];
        for ($i = 0; $i < strlen($s); $i++) {
            $res ^= $s[$i] ^ $t[$i];
        }

        return $res;
    }
}
```

### 问题
发现其他语言初始化$res = 0都可以，PHP输出不对，知道的同学帮忙回复下哈
```
function findTheDifference($s, $t) {
        $res = "0";
        for ($i = 0; $i < strlen($t); $i++) {
            if (isset($s[$i])) {
                $res ^= $s[$i] ^ $t[$i];
            } else {
                $res ^= $t[$i];
            }
        }

        return $res;
    }
```
