![image.png](https://pic.leetcode-cn.com/6a30bd530febc5e13f4d150c2d7dcfbcb1a6495010c6c68909b6a6f203ff58a1-image.png)

### 解题思路
此处撰写解题思路

### 代码

```php
class Solution {

    /**
     * @param String $S
     * @return String
     */
    function compressString($S) {        
        $temp = 1;
        $total = strlen($S);
        $newS = '';
        $a = [];
        $num = [];

        for ($i = 0; $i < $total - 1; $i++) {
            if ($S[$i] == $S[$i + 1]) {
                $temp++;
            } else {
                array_push($a, $S[$i]);
                array_push($num, $temp);
                $temp = 1;
            }
        }

        array_push($a, $S[$total - 1]);
        array_push($num, $temp);

        foreach ($a as $key => $val) {
            $newS .= $val . $num[$key];
        }

        return strlen($newS) >= strlen($S) ? $S : $newS;
    }
}
```