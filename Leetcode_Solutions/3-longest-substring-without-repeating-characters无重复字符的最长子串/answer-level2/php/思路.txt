### 解题思路
用一个数组$r保存当前找到的无重复字符子串，$len保存其最大长度，
每次取一个字符：
    如果该字符不在数组$r中，从数组右侧push入该字符，更新最大长度；
    如果该字符已在数组$r中，从数组右侧push入该字符，并从左侧依次pop已有字符，直到取出重复字符为止；

### 代码

```php
class Solution {

    /**
     * @param String $s
     * @return Integer
     */
    function lengthOfLongestSubstring($s) {
        $r = [];
        $len = 0;
        $count = strlen($s);
        for ($i=0;$i<$count;$i++) {
            if (!in_array($s[$i], $r)) {
                array_push($r, $s[$i]);
                $len = max($len, count($r));
            } else {
                array_push($r, $s[$i]);
                while (!empty($r)) {
                    $item = array_shift($r);
                    if ($item === $s[$i]) {
                        break;
                    }
                }
            }
        }
        return $len;
    }
}
```