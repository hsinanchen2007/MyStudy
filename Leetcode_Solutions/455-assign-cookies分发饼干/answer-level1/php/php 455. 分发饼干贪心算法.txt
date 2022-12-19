### 解题思路
1.将2个数组拍好序，如果是php需要用sort排序，不要使用asort（排序序后index不变）
2.使用贪心算法来进行匹配

### 代码

```php
class Solution {

    /**
     * @param Integer[] $g
     * @param Integer[] $s
     * @return Integer
     */
    function findContentChildren($g, $s) {
        sort($g);
        sort($s);
        $g_count = count($g);
        $s_count = count($s);
        $count = 0;
        $i = 0;
        for ($j = 0; $j < $g_count; $j++) {
           for (;$i < $s_count;$i++) {
                if ($g[$j] <= $s[$i]) {
                    $count++;
                    $i++;
                    break;
                }
            }
        }
//或者使用下面的2个for循环的写法
//        for ($j = 0; $j < $g_count; $j++) {
//        while ($i < $s_count) {
//            if ($g[$j] <= $s[$i]) {
//                $count++;
//                $i++;
//                break;
//            }
//            $i++;
//        }
//    }

        return $count;
    }
}
```