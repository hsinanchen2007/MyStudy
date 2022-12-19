首先想到的是二分法：
```
function isPerfectSquare($num) {
	$left = 0;
	$right = $num;
	while($left < $right){
		$mid = $right - floor(($right-$left)/2);
		if($mid*$mid==$num){
			return true;
		}else if($mid*$mid<$num){
			$left = $mid+1;
		}else if($mid*$mid>$num){
			$right = $mid-1;
		}
	}
	return $left*$left==$num;
}
```
等差数列:
1+3+5+7+...(2N−1) = N^2
```
function isPerfectSquare($num) {
	$sum = 0;
	$i = 1;
	while($sum < $num){
		$sum += 2*$i-1;
		$i++;
	}
	return $sum==$num;
}
```
