```
class NumMatrix {

    function __construct($matrix) {
        $this->sum[0][0] = $matrix[0][0];
        for($i=1;$i<count($matrix);$i++){
            $this->sum[$i][0] = $this->sum[$i-1][0] + $matrix[$i][0];
        }
        for($j=1;$j<count($matrix[0]);$j++){
            $this->sum[0][$j] = $this->sum[0][$j-1] + $matrix[0][$j];
        }
        for($i=1;$i<count($matrix);$i++){
            for($j=1;$j<count($matrix[0]);$j++){
                $this->sum[$i][$j] = $matrix[$i][$j] + $this->sum[$i][$j-1] + $this->sum[$i-1][$j] - $this->sum[$i-1][$j-1];
            }
        }
    }

    function sumRegion($row1, $col1, $row2, $col2) {
        return $this->sum[$row2][$col2] - $this->sum[$row1-1][$col2] - $this->sum[$row2][$col1-1] + $this->sum[$row1-1][$col1-1];
    }
}
```
