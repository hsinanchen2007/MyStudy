### 解题思路
此处撰写解题思路
题意读了好几遍，写完发现理解错了。。一定要审好题，看好case！！！
本题大概就是边计数边输出，每个都计数，当与上个数字不同时，就停止计数写入到数组中。当相同时，继续计数，知道不相等。
### 代码

```php
class Solution {

    /**
     * @param Integer $n
     * @return String
     */
    function countAndSay($n) {
        $arr[1] = [1];
        $i = 2;
        while ($i <= $n) {
            $tmp = [];
            foreach ($arr[$i - 1] as $key => $value) {
                if ($sum[$value]) {
                    $count ++;
                } else {
                    if ($sum) {
                        $tmp[] = $count;
                        $tmp[] = $arr[$i - 1][$key - 1];
                    }
                    $sum = [];
                    $sum[$value] = 1;
                    $count = 1;
                }
            }
            $tmp[] = $count;
            $tmp[] = $value;
            $sum = [];
            $arr[$i] = $tmp;
            $i ++;
        }
        return implode('', $arr[$n]);
    }
}
```