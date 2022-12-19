### 解题思路
一位业务狗的截图思路

### 代码

```php
class Solution
{

    /**
     * @param String $S
     * @return String
     */
    function compressString($S)
    {

        if ((strlen($S) <= 1)) {
            return $S;
        }

        $arr = str_split($S, 1);
        $count = 0;
        $tmp = "";
        $str = "";

        foreach ($arr as $k => $value) {

            if ($k == 0) {
                $tmp = $value;
                $count++;
                continue;
            }

            if ($value == $tmp) {
                $count++;
                $tmp = $value;
            } else {
                $str .= $tmp . $count;
                $count = 1;
                $tmp = $value;
            }

            if ($k == (count($arr) - 1)) {
                $str .= $tmp . $count;
            }
        }

        return strlen($str) >= strlen($S) ? $S : $str;
    }
}

```