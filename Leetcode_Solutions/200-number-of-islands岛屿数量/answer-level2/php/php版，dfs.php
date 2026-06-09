解法看自《极客时间算法训练营》
```
class Solution {
	private $dx = [-1, 1, 0, 0]; 
	private $dy = [0, 0, -1, 1];

	private $g = [];
    /**
     * @param String[][] $grid
     * @return Integer
     */
    function numIslands($grid) :int {
    	$isLands = 0;
    	$this->g = $grid;
    	$m = count($this->g);
    	$n = count($this->g[0]);
    	for ($i=0; $i < $m; $i++) { 
    		for ($j=0; $j < $n; $j++) { 
    			if (!$this->g[$i][$j]) {
    				continue;
    			}

    			$isLands += $this->sink($i, $j);
    		}
    	}
    
    	return $isLands;
    }

    function sink(int $i, int $j) :int {

    	if (!$this->g[$i][$j]) {
    		return 0;
    	}

    	$this->g[$i][$j] = '0';
    	$m = count($this->g);
    	$n = count($this->g[0]);

    	$dcount = count($this->dx);

    	// 把上下左右都沉底。四联通
    	for ($k = 0; $k < $dcount; $k++) { 
    		$x = $i + $this->dx[$k];
    		$y = $j + $this->dy[$k];

    		if ($x >= 0 && $x < $m && $y >= 0 && $y < $n) {
   
    			if (!$this->g[$x][$y]) {
    				continue;
    			}

    			$this->sink($x, $y);
    		}
    	}

    	return 1;
    }
}

```

下面解法来自《玩转算法面试-- Leetcode真题分门别类讲解》

```
class Solution {
	private $d = [[0, 1], [1, 0], [0, -1], [-1, 0]];
	private $m;
	private $n;
	private $visited;

	private function inArea(int $x, int $y) :bool {
		return $x >=0 && $x < $this->m && $y >= 0 && $y < $this->n;
	}

	private function dfs(array $grid, int $x, int $y) {
		$this->visited[$x][$y] = 1;
		for ($i=0; $i < 4; $i++) { 
			$newX = $x + $this->d[$i][0];
			$newY = $y + $this->d[$i][1];

			if ($this->inArea($newX, $newY) && !isset($this->visited[$newX][$newY]) && $grid[$newX][$newY] == '1') {
				$this->dfs($grid, $newX, $newY);
			}
		}
	}

	public function numIslands($grid) : int {
		$this->m = count($grid);

		if ($this->m === 0) {
			return 0;
		}

		$this->n = count($grid[0]);

		$res = 0;
		for ($i=0; $i < $this->m; $i++) { 
			for ($j=0; $j < $this->n; $j++) { 
				if ($grid[$i][$j] == '1' && !isset($this->visited[$i][$j])) {
					$res++;
					$this->dfs($grid, $i, $j);
				}
			}
		}

		return $res;
	}
}
```