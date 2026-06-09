### 解题思路
这个题目有点晦涩，后来画图才清晰了一些，只要坐标点x,y轴上都为0，则为孤立点，否则为同一个朋友圈

### 代码

```php
class Solution {

    /**
     * @param Integer[][] $M
     * @return Integer
     */
    function findCircleNum($M) {
        $visitor = [];
        $count = 0;
        for ($i = 0; $i < count($M); $i++) {
            if ($visitor[$i] == 0) {
                $this->dfs($M, $visitor, $i);
                $count++;
            }
        }

        return $count;
    }

    public function dfs(&$M, &$visitor, $i)
    {
        for ($j = 0; $j < count($M); $j++) {
            if ($M[$i][$j] == 1 && $visitor[$j] == 0) {
                $visitor[$j] = 1;
                $this->dfs($M, $visitor, $j);
            }
        }
    }
}
```