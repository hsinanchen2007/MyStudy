将两个数组升序排列,定义2个位置指标,初始为零,进行循环,如果孩子胃口小于等于饼干大小,就让2个指标同时加一(将饼干喂给孩子,计数加一),如果孩子胃口大于饼干大小,就换下一块大一点的饼干(因为都是升序排列了的,不满足这个孩子的饼干也不会满足其他的孩子).
代码如下
```
class Solution {

    /**
     * @param Integer[] $g
     * @param Integer[] $s
     * @return Integer
     */
    function findContentChildren($g, $s) {
        $i = $j = 0;
        $count = 0;
        sort($g);
        sort($s);
        while($i<count($g) && $j<count($s)){
            //不满足孩子
           if($g[$i] > $s[$j]){
                $j++;
           }else{ //满足了
                $i++;
                $j++;
                $count++;
           }   
        }
        return $count;
    }
}
```
萌新第一次写题解,谢谢大家,写的不好请多多见谅