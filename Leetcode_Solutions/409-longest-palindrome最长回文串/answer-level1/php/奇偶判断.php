### 解题思路
统计字符串中各个字符出现的次数，偶数次肯定是可以拼凑的，最多可以出现一个奇数字符

### 代码

```php
class Solution {

    /**
     * @param String $s
     * @return Integer
     */
    function longestPalindrome($s) {
        $res = 0;
        $arr = [];
        $len = strlen($s);
        for($i = 0; $i<$len; $i++) {
            $arr[substr($s,$i,1)] += 1;
        }
        $onceTag = false;
        foreach($arr as $k => $v){
            if ($v % 2 == 0) {
                $res += $v;
            } else {
                $res += (int)($v / 2) * 2;
                $onceTag = true;
            }
        }
        return $onceTag ? $res+1 : $res;
    }
}
```