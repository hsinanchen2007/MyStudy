class Solution {

    /**
     * @param Integer[] $candidates
     * @param Integer $target
     * @return Integer[][]
     */
    public $ret = [];
    function combinationSum($candidates, $target) {
        // 本身可以无限重复
        $start = 0;
        $arr = [];  // 传入一个序列
        $this->dfs($candidates,$target,$start,$arr);
        return $this->ret;
    }

    public function dfs($candidates, $target, $start,$arr){
        if(array_sum($arr) > $target) return;
        if(array_sum($arr) == $target) $this->ret[] = $arr;

        for($i=$start; $i<count($candidates);$i++) {
            $arr[] = $candidates[$i];
            $this->dfs($candidates,$target,$i,$arr);
            array_pop($arr);
        }
    }
}