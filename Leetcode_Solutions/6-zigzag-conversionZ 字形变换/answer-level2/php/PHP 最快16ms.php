### 解题思路
这道题有点像找规律

每一行当做一个大的循环，然后处理拼接完整的Z的元素，不完整的元素，
重点是一个Z型有两种数据，顶点和中间的数据。

### 代码

```php
class Solution {

    /**
     * @param String $s
     * @param Integer $num
     * @return String
     */
    function convert($s, $num) {
        if ($num < 2) return $s; // 处理行数小于2的情况

        $s_len = strlen($s); // 字符串的长度
        $z_len = $num * 2 - 2; // 一个循环所需的元素个数 `|/`
        $z_count = intval($s_len / $z_len); // 完整的`Z`的个数
        $over = $s_len % $z_len;
        $res = '';

        for($i = 0;$i < $num; $i++) {

            if ($i == 0 || $i == $num - 1) { // 当是第一行和最后一行的时候（每行有一个元素）
                for($j = 0; $j < $z_count; $j++) {
                    // 完整的Z
                    $res .= $s{$j * $z_len + $i};
                }
                // 不完整的Z
                if ($over > $i) $res .= $s{$j * $z_len + $i};
            }else { // 当是中间行的时候（每行有两个元素）
                for($j = 0; $j < $z_count; $j++) {
                    // 完整的Z
                    $res .= $s{$j * $z_len + $i} . $s{($j + 1) * $z_len - $i};
                }
                // 不完整的Z
                if ($over > $i) $res .= $s{$j * $z_len + $i};
                if ($over > ($z_len - $i)) $res .= $s{($j + 1) * $z_len - $i};
            }
        }
        return $res;
    }
}
```