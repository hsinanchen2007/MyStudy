### 解题思路
程序从 i=3 开始迭代，一直到 i=n 结束。每一次迭代，都会计算出多一级台阶的走法数量。迭代过程中只需保留两个临时变量a和b，分别代表了上一次和上上次迭代的结果。 为了便于理解，我引入了temp变量。temp代表了当前迭代的结果值。

### 代码

```php
class Solution {

    /**
     * @param Integer $n
     * @return Integer
     */
    function numWays($n) {
     	if ($n<=0) return 1;
    	if ($n<=2) return $n;

		$a = 1;
		$b = 2;
		$temp = 0;
		for ($i=3; $i <=$n ; $i++) { 
			$temp = ($a +$b)%1000000007;
			$a = $b;
			$b = $temp;
		}
		return $temp;
    }
}
```