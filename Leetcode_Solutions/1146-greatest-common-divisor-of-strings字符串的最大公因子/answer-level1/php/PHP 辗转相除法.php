 这题偏数学，算法的东西少一些

```php
class Solution
{

    /**
     * @param String $str1
     * @param String $str2
     * @return String
     */
    function gcdOfStrings($str1, $str2)
    {
        if (empty($str1) || empty($str2)) return '';
        if ($str1 . $str2 !== $str2 . $str1) return '';
        $xLen = $this->gcd(strlen($str1), strlen($str2));
        return substr($str1, 0, $xLen);
    }

    // 辗转相除法求最大公约数
    private function gcd($a, $b)
    {
        return $b == 0 ? $a : $this->gcd($b, $a % $b);
    }
}
```
