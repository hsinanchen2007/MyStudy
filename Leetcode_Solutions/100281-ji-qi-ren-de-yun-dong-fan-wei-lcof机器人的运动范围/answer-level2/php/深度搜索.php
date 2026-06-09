### 解题思路
深度搜索，每次有两个方向，下面和右边，所以return 1+（下面x+1）+（右边y+1）

### 代码

```php
class Solution {

    /**
     * @param Integer $m
     * @param Integer $n
     * @param Integer $k
     * @return Integer
     */
    public $visited = [];
    public $m ;
    public $n;
    public function movingCount($m, $n, $k) {
        if ($k == 0) {
            return 1;
        }
        $this->m = $m;$this->n = $n;
        for ($i=0; $i < $m; $i++) { 
    		for ($j=0; $j < $n; $j++) { 
    			$this->visited[$i][$j] = 0;
    		}
    	}	
        $num = $this->dfs(0,0,$k);
        return $num;
    }
    public function dfs($x,$y,$k)
    {
            if ($x > ($this->m-1) || $y > ($this->n-1) || $this->weiSum($x,$y) > $k || $this->visited[$x][$y] == 1) {
                return 0;
            }
            if ($x==0) {
                print_r(['y'=>$y]);
            }
            $this->visited[$x][$y] = 1;
            
            return 1 + $this->dfs($x+1,$y,$k) + $this->dfs($x,$y+1,$k);
        }

    public function weiSum($x,$y)
    {
        $res = 0;
        $xSum = $ySum= 0;
        while ($x > 0) {
            $g = $x % 10;
            $xSum += $g;
            $x = floor($x/10);
        }
        while ($y > 0) {
            $g = $y % 10;
            $ySum += $g;
            $y = floor($y/10);
        }

        return $xSum+$ySum;
    }
}
```