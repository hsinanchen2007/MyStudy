### 解题思路
此处撰写解题思路

### 代码

```php
class Solution {

    /**
     * @param Integer $n
     * @return String
     */
    function countAndSay($n) {
        $a = '1';
		$j = 1;
		$i = 0;
		if($n == 1){
			return "1";
		}
		for($k=1;$k<$n;$k++){
			if($k != $n){
				$len = strlen($a);
				$res = '';
				while($j <= $len){
					if($a[$i] == $a[$j]){
						if($a[$j+1] != $a[$j]){
							$r = $j-$i+1;
							$tmp = "$r"."$a[$j]";
							$res .= $tmp;
							$i = $j + 1;
							$j++;
						}
						$j++;
						continue;
					}else{
						$res .= "1"."$a[$i]";
					}
					$i++;
					$j++;
				}
				$a = $res;
				$i = $j = 0;
			}else{
				return $res;
			}
		}
		return $res;
    }
}
```