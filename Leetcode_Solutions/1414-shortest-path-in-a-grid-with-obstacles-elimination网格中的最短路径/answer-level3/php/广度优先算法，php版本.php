### 解题思路
分享php的代码。
1. 通过栈存储待处理的节点。
2. 存储访问过的节点，避免重复访问。
3. 循环栈中元素，每次一步往前走动，当第一次到达右下角，即返回步数。每走一步，将新的位置存储到栈中。

### 代码

```php
class Solution {
    private $arr = array(
        array(-1, 0),
        array(0, -1),
        array(1, 0),
        array(0, 1),
    );

    /**
     * @param Integer[][] $grid
     * @param Integer $k
     * @return Integer
     */
    function shortestPath($grid, $k) {
        if(count($grid) == 1 && count($grid[0]) == 1){
            return 0;
        }
        $visited = array();
        $visited['0_0_'.$k] = 1;

        $stack = array(
            array(0, 0, $k)
        );
        $step = 0;
        while(!empty($stack)){
            $step++;
            // var_dump($step);
            // var_dump(count($stack));
            $stack_add = array();

            while(!empty($stack)){
                list($i, $j, $k) = array_pop($stack);
                foreach($this->arr as $v){
                    $new_i = $i + $v[0];
                    $new_j = $j + $v[1];
                    $new_k = $k;
                    if($grid[$new_i][$new_j] == 1){
                        $new_k--;
                    }
                    if($new_i<0 || $new_j<0 || $new_k<0 
                    || $new_i>count($grid)-1 || $new_j>count($grid[0])-1 
                    || isset($visited[$new_i.'_'.$new_j.'_'.$new_k])
                    ){
                        continue;
                    }
                    if($new_i == count($grid)-1 && $new_j == count($grid[0])-1){
                        return $step;
                    }
                    $visited[$new_i.'_'.$new_j.'_'.$new_k] = 1;
                    $stack_add[] = array($new_i, $new_j, $new_k);
                }
            }
            $stack = $stack_add;
        }

        return -1;
    }
}
```