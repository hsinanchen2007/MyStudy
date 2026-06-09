class Solution {

    /**
     * @param String[][] $grid
     * @return Integer
     */
    function numIslands($grid) {
        $num = 0;
        foreach ($grid as $key=>$value) {
            foreach ($value as $k=>$v) {
                if ($grid[$key][$k] == '1') {
                    $this->grid($grid,$key,$k);
                    $num++;
                }
            }
        }
        return $num;
    }
    
    public function grid(&$grid, $key, $k){
        if( $grid[$key][$k] != '1'){
            return $grid;
        }
        $grid[$key][$k] = '2';
        $this->grid($grid, $key + 1, $k);
        $this->grid($grid, $key - 1, $k);
        $this->grid($grid, $key, $k + 1);
        $this->grid($grid, $key, $k - 1);
    }
}