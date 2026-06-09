### 解题思路
感谢[@sweetiee](/u/sweetiee/)的动态解，先考虑左括号，之后再比较左右数量

### 代码

```php
class Solution {

    /**
     * @param Integer $n
     * @return String[]
     */

    private $pairs = [];
    function generateParenthesis($n) {
        $this->dfs($n,$n,"");
        return $this->pairs;
    }

    private function dfs($left_pas,$right_pas,$curRes){
        if($left_pas==0 && $right_pas==0){//左右括号皆用尽，返回结果
            $this->pairs[] = $curRes;
            return;
        }

        //左括号不为零，添加左括号
        if($left_pas > 0) $this->dfs($left_pas-1,$right_pas,$curRes . "(");
        //右括号更多，削减右括号
        if($right_pas > $left_pas) $this->dfs($left_pas,$right_pas-1,$curRes . ")");
    }
}
```