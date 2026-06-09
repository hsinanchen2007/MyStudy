### 代码

```php
class Solution
{

    /**
     * @param String $s
     * @return Integer
     */
    function lengthOfLongestSubstring($s)
    {
        $l = strlen($s);
        return $this->_lengthOfLongestSubstring($s,$l,0);
    }

    function _lengthOfLongestSubstring(&$s,$l,$p)
    {
        $map = array();
        for($i=$p;$i<$l;$i++)
        {
            if(in_array($s[$i],$map))
            {
                $p++;
                return max(count($map),$this->_lengthOfLongestSubstring($s,$l,$p));
            }else{
                $map[] = $s[$i];
            }
        }
        return count($map);
    }
}
```