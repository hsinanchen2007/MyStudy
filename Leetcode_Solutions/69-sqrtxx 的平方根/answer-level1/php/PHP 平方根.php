### 解题思路
执行用时 :4 ms, 在所有 PHP 提交中击败了96.85% 的用户
内存消耗 :14.9 MB, 在所有 PHP 提交中击败了54.05%的用户

受到 "两数相除" 一题中 "andfly" 同学解法的启发
内层循环：判断($j + $i)的平方是否小于等于$x，是的话，在内部将$j乘2；
外层循环：将内层循环的$j累加保存到$i中(内层的最后一次循环执行后，$j + $i的平方会大于$x，所以将$j除以2)
### 代码

```php
class Solution {

    /**
     * @param Integer $x
     * @return Integer
     */
    function mySqrt($x) {
        if( $x <= 1 ) return $x;
		$i = 0;
		while( $i**2 < $x ){
			$j = 1;
			while( ($j + $i)**2 <= $x ){
				$j = $j<<1;
			}
			if( $j == 1 ) return $i;
			$i += $j>>1;
		}
		return $i;
    }
}
```