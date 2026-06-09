思路：
1.计算车所在的坐标
2.计算车所在的横列左边有多少个p，记录p的坐标到zp数组
2.计算车所在的横列右边有多少个p，记录p的坐标到yp数组
4.计算车所在的横列有多少个b，根据b的位置去删除zp和yp数组
5.计算车所在的纵列上边有多少个p，记录p的坐标到sp数组
6.计算车所在的纵列下边有多少个p，记录p的坐标到xp数组
7.计算车所在的纵列有多少个b，根据b的位置去删除sp和xp数组
8.因为一个方向只能吃一个，所以这四个数组如果有值，就一个数组当一个


```
function numRookCaptures($board) {
	$che = [];
	$eatCount = 0; //能吃的数量
	//找出车的坐标
	foreach ($board as $xIndex => $xVal) {
		foreach ($xVal as $yIndex => $yVal) {
			//查车
			if ($board[$xIndex][$yIndex] == 'R') {
				$che = [$xIndex,$yIndex];
			}
		}
	}
	//存储左右的p的坐标，车的横列左右两边的卒子p的坐标数组
	$zp = [];$yp = [];
	//计算左右的所有p
	foreach ($board[$che[0]] as $yIndex => $yVal) {
		// 每个坐标就是 $board[$che[0]][$yIndex]  值$xVal
		if ($yVal == 'p' && $yIndex < $che[1]) {
			$zp[$yIndex] = 1 ;
		}
		if ($yVal == 'p' && $yIndex > $che[1]) {
			$yp[$yIndex] = 1 ;
		}
	}

	//过滤左右的p
	foreach ($board[$che[0]] as $yIndex => $yVal) {
		// 每个坐标就是 $board[$che[0]][$yIndex]  值$xVal
		if ($yVal == 'B') {
			if ($yIndex < $che[1] ) {
				foreach ($zp as  $key => $value) {
					if ($yIndex > $key) {
						unset($zp[$key]);
					}
				}
			}
			if ($yIndex > $che[1] ) {
				foreach ($yp as  $key => $value) {
					if ($yIndex < $key) {
						unset($yp[$key]);
					}
				}
			}
		}
	}
	if (count($zp) > 0) {
		$eatCount += 1;
	}
	if (count($yp) > 0) {
		$eatCount += 1;
	}
	print_r(['zyeatCount'=>$eatCount]);
	
	//存储上下的p的坐标 ，车的纵列左右两边的卒子p的坐标数组
	$sp = $xp = [];
	//计算行列所以的p
	foreach ($board as $xIndex => $xVal) {
		if ($xVal[$che[1]]) {
			if ($xVal[$che[1]] == 'p' && $xIndex < $che[0]) {
				$sp[$xIndex] = 1 ;
			}
			print_r(['$xpyIndex'=>$yIndex]);
			if ($xVal[$che[1]] == 'p' && $xIndex > $che[0]) {
				$xp[$xIndex] = 1 ;
			}
		}
	}
	print_r(['$sp'=>$sp,'$xp'=>$xp]);
	//过滤掉上下的b
	foreach ($board as $xIndex => $xVal) {
		if ($xVal[$che[1]]) {
			if ($xVal[$che[1]] == 'B') {
				if ($xIndex < $che[0] ) {
					foreach ($sp as  $key => $value) {
						if ($xIndex > $key) {
							unset($sp[$key]);
						}
					}
				}
				if ($xIndex > $che[0] ) {
					foreach ($xp as  $key => $value) {
						if ($xIndex < $key) {
							unset($xp[$key]);
						}
					}
				}
			}
		}
	}
	print_r(['$sp'=>$sp,'$xp'=>$xp]);
	//有集合取1
	if (count($sp) > 0) {
		$eatCount += 1;
	}
	if (count($xp) > 0) {
		$eatCount += 1;
	}
	print_r(['sxeatCount'=>$eatCount]);
	return $eatCount;
}
```
