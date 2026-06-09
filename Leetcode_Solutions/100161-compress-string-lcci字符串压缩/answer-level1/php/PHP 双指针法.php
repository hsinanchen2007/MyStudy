直接上代码

```php
class Solution
{

    /**
     * @param String $s
     * @return String
     */
    function compressString($s)
    {
        // 双指针法
        $n = strlen($s);
        if ($n <= 1) return $s;
        $arr = str_split($s);
        $left = 0;
        $stack = [];
        $return = '';
        while ($left < $n) {
            $right = $left;
            while ($right < $n && $s[$right] == $s[$left]) {
                $right++;
            }
            $return .= $s[$left] . ($right - $left);
            $left = $right;
        }

        if (strlen($return) < strlen($s)) {
            return $return;
        }

        return $s;
    }
}
```