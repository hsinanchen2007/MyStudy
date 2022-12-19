### 解题思路
解题思路： 将三角形中的各个点想象成矩阵的形式，从下向上推导。 状态的定义， 每一行的minRoute 是下面行中 min(minRoute[i-1][j], minRoute[i][j-1]), 从下向上逐步迭代，直到00， 写代码的时候需要注意， minRoute的第一层是不需要的，减少代码依赖，去掉。 三角形的列的值直接取 count($triangle[$i]) 

### 代码

```php
class Solution {

    /**
     * @param Integer[][] $triangle
     * @return Integer
     */
    function minimumTotal($triangle) {
        $minRoute = [] ;
        for($i = count($triangle)-1; $i >= 0; $i--){
            for($j = 0; $j < count($triangle[$i]); $j++){
                $minRoute[$j] = $triangle[$i][$j] + min($minRoute[$j], $minRoute[$j+1]);
            }
        }
        return $minRoute[0];
    }
}
```