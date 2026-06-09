看了大家思路都是回溯法，想了一个不同方向，找它的下一个更大排序如果不存在说明已经是最小排序
此时就是它的全排列了

```
class Solution {

    /**
     * @param Integer[] $nums
     * @return Integer[][]
     */
    function permuteUnique($nums) {
		if(empty($nums)) return [];
		sort($nums);
		$len = count($nums);
		return $this->swap($nums,$len);
    }
    
    public function swap($nums, $len) {

		if($len == 1) return [$nums];
		$r = $len - 1;
		while ($r > 0) {

			if($nums[$r] > $nums[$r - 1]){
				$a = $r -1;
				$rr = $len - 1;
				while ($rr > 0) {
					if($nums[$rr] > $nums[$a]) {
						$b = $rr;
						break;
					}
					$rr--;
				}
				break;
			}

			$r--;
		}

		if(!isset($a)){
			sort($nums);
			$this->arr[] = $nums;
			return  $this->arr;
		}else{

			[$nums[$a], $nums[$b]] = [$nums[$b], $nums[$a]];
			$alert = array_slice($nums,$a+1);
			sort($alert);
			for($i=0;$i<count($alert);$i++){
				$nums[$i + $a+1] = $alert[$i];
			}
			$this->arr[] = $nums;
			return $this->swap($nums, $len);
		}
	}
}
```