V1版暴力法，执行52ms：

重点是如何保存数据，最后输出；
```
class Solution 
{
    /**
     * @param String $s
     * @param Integer $numRows
     * @return String
     */
    function convert($s, $numRows) 
    {
        $s_len = strlen($s);
        if ($s_len <= $numRows || $numRows <= 1) {
            return $s;
        }
        // 使用数组来保存数据
        $arr = [];
        // 数组的键名，表示每一行，从1开始 
        $key = 1;
        // Z形开始行数一直递增，等于最大行数后递减，然后等于最小行数又回归递增
        $add = true;
        for ($i = 0; $i < $s_len; $i ++) {
            
            $arr[$key][] = $s{$i};
            
            if ($key == $numRows) {
                $add = false;
            } elseif ($key == 1) {
                $add = true;
            }
            
            if ($add) {
                ++ $key;
            } else {
                -- $key;
            }
        }
        
        $str = '';
        for ($j = 1; $j <= $numRows; $j ++) {
            $str .= implode('', $arr[$j]);
        }
        
        return $str;
    }
}
```

V2 版，执行16ms，

通过规律来找到每一行的下一个字符，找不到了则换行找^^
```
class Solution
{
    /**
     * @param String $s
     * @param Integer $numRows
     * @return String
     */
    function convert($s, $numRows)
    {
        $s_len = strlen($s);
        if ($s_len <= $numRows || $numRows <= 1) {
            return $s;
        }

        $str = '';

        // 每一行的找下一个字符
        for ($i = 1; $i <= $numRows; $i++) {
            // 当前行数之上的行数数量
            $upperRows = $i - 1;
            // 当前行数之下的行数数量
            $downRows = $numRows - $i;
            // 表示下一个要找到的字符位置，从行数减一的位置开始
            $next = $upperRows;
            // 一上一下^ ^, 所以使用奇偶数来控制
            $j = 0;
            while (isset($s{$next})) {
                $str .= $s{$next};

                if ($j%2 === 0) {
                    if ($downRows == 0) {
                        ++ $j;
                        $next = $next + 2 * $upperRows;
                    } else {
                        $next = $next + 2 * $downRows;
                    }
                } else {
                    if ($upperRows == 0) {
                        ++ $j;
                        $next = $next + 2 * $downRows;
                    } else {
                        $next = $next + 2 * $upperRows;
                    }
                }

                ++$j;
            }
        }

        return $str;
    }
}
```