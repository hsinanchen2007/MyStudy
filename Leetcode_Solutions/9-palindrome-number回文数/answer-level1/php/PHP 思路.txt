### 两种解题思路
1. 生成一个反向字串，依次对比元素，一致即为回文
2. 首尾比较，设置中点的判断，到了即可结束循环

### 代码

```php
class Solution {

    /**
     * @param Integer $x
     * @return Boolean
     */
    function isPalindrome1($x) {
        $str = strval($x);
        $str = str_split($str);
        $rstr = array_reverse($str);
        foreach($str as $k=>$v) {
            if ($v !== $rstr[$k]) {
                return false;
            }
        }
        return true;
    }
        function isPalindrome($x) {
        $str = strval($x);
        preg_match_all('/./', $str, $matches);
        $str = $matches[0];
        $count = count($str);
        foreach($str as $k=>$v) {
            $compareKey = $count-$k -1;
            if ($k == $compareKey) break;
            else if ($k >= $count/2) break;
            if ($v !== $str[$compareKey]) {
                return false;
            }
        }
        return true;
    }
}
```