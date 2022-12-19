### 解题思路
套用回溯算法模板就好了
result = []
def backtrack(路径, 选择列表):
    if 满足结束条件:
        result.add(路径)
        return
    for 选择 in 选择列表:
        做选择
        backtrack(路径, 选择列表)
        撤销选择

### 代码

```php
class Solution {

    /**
     * @param String $digits
     * @return String[]
     */

    private $phone = array(
                          1=>null,
                          2=>array('a','b','c'),
                          3=>array('d','e','f'),
                          4=>array('g','h','i'),
                          5=>array('j','k','l'),
                          6=>array('m','n','o'),
                          7=>array('p','q','r','s'),
                          8=>array('t','u','v'),
                          9=>array('w','x','y','z'),
                        );

    function letterCombinations($str) {
        if(!$str){
            return [];
        }
        $arr_ret = [];
        $this->dfs($str,0, '',$arr_ret);
        return  $arr_ret;
    }

    function dfs($str, $index, $s_ret, &$arr_ret){

        if( $index == strlen($str)){
            $arr_ret[] =  $s_ret;
            return;
        }

        foreach($this->phone[$str[$index]] as $c){
            $s_ret .= $c;   
            $this->dfs($str,$index+1, $s_ret, $arr_ret);
            $s_ret = substr($s_ret, 0, strlen($s_ret)-1);
        }
    }
}
```