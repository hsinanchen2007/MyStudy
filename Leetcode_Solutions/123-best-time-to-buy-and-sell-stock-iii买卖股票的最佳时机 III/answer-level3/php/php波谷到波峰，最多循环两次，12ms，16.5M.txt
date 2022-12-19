

```php []
function getlirun($arr){
	$res = array();
	$lastkey = count($arr) - 1;
	$c1 = $maxc1 = 0;
	$minkey1 = $maxkey1 = 0;
	$min1 = $max1 = $arr[0];
	//第一次循环找波谷和波峰，
	foreach($arr as $k=>$v){
		if($v<$min1){
			$min1 = $v;
			$minkey1 = $k;
		}
		if($v>$max1){
			$max1 = $v;
			$maxkey1 = $k;
		}
		if($minkey1<$maxkey1){
			$c1 = $max1 - $min1;
			if($k == $lastkey){
				$c1arr[] = $c1;
			}
			if($c1>$maxc1){
				$maxc1 = $c1;
				$maxc1minkey = $minkey1;
				$maxc1maxkey = $maxkey1;
			}
		}else{//碰到更小值，记录此时最大差值，并重新开始
			if($c1>0){
				$c1arr[] = $c1;
				$c1 = 0;
			}
			$max1 = 0;
		}
	}
	//差值数组只有一个就再循环一次
	if(count($c1arr == 1)){
		$skey = $maxc1minkey+1;
		$ekey = $maxc1maxkey-1;
		$c1 = $maxc1 = 0;
		if(isset($arr[$skey])){
			$min1 = $max1 = $arr[$skey];
			$minkey1 = $maxkey1 = $skey;
		}
		//两波峰和波谷之间，此时波谷之前不需要计算
		for($k=$skey;$k<=$ekey;$k++){
			$v = $arr[$k];
			if($v<$min1){
				$min1 = $v;
				$minkey1 = $k;
			}
			if($v>$max1){
				$max1 = $v;
				$maxkey1 = $k;
			}
			if($minkey1>$maxkey1){
				$c1 = $max1 - $min1;
				if($k == $ekey){
					$c1arr[] = $c1;
				}
			}else{
				if($c1>0){
					$c1arr[] = $c1;
					$c1 = 0;
				}
				$min1 = $max1;
			}
			//var_dump($minkey1.'--'.$maxkey1.'--'.$c1);
		}
		$skey = $ekey+2;
		$c1 = $maxc1 = 0;
		if(isset($arr[$skey])){
			$min1 = $max1 = $arr[$skey];
			$minkey1 = $maxkey1 = $skey;
		}
		//波峰之后
		for($k=$skey;$k<=$lastkey;$k++){
			$v = $arr[$k];
			if($v<$min1){
				$min1 = $v;
				$minkey1 = $k;
			}
			if($v>$max1){
				$max1 = $v;
				$maxkey1 = $k;
			}
			if($minkey1<$maxkey1){
				$c1 = $max1 - $min1;
				if($k == $lastkey){
					$c1arr[] = $c1;
				}
			}else{
				if($c1>0){
					$c1arr[] = $c1;
					$c1 = 0;
				}
				$max1 = 0;
			}
		}
		
	}
	rsort($c1arr);
	//return $c1arr;
	return $c1arr[0]+$c1arr[1];
	
}
```


