### 解题思路
此处撰写解题思路

### 代码

```php
class Solution {

    /**
     * @param Integer[][] $matrix
     * @return NULL
     */
    function rotate(&$matrix) {
        $list = [];
        for ($i = 0; $i < count($matrix); $i++) {

            for ($j = 0; $j < count($matrix[$i]); $j++) {

                $newx = $j;
                $newy = abs($i - (count($matrix[$i]) - 1));
                $list[$newx][$newy] = $matrix[$i][$j];

            }
        }

        foreach ($list as $k => $v) {
            ksort($v);
            $list[$k] = $v;
        }
        $matrix = $list;
    }
}
```