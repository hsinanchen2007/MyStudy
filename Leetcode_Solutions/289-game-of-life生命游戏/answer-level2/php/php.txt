### 解题思路
![QQ图片20200402153659.png](https://pic.leetcode-cn.com/d01ff25563bfee8aed4b73d172c8bb33c2a34ac921236f379eb6a4184019209f-QQ%E5%9B%BE%E7%89%8720200402153659.png)


### 代码

```php
class Solution {

    /**
     * @param Integer[][] $board
     * @return NULL
     */
    function gameOfLife(&$board) {
        $new = [[]];
        $x_arr = [-1,-1,-1,0,0,1,1,1];
        $y_arr = [-1,0,1,-1,1,-1,0,1];

        foreach ($board as $k=>$v){
            foreach ($v as $k2=>$v2){
                $life = 0;
                foreach ($x_arr as $k3=>$v3){
                    $life += $board[$k+$v3][$k2+$y_arr[$k3]] ?: 0;
                }
                if ($life == 2){
                    $new[$k][$k2] = $v2;
                }elseif($life == 3){
                    $new[$k][$k2] = 1;
                }else{
                    $new[$k][$k2] = 0;
                }
            }
        }

        $board = $new;
    }
}
```