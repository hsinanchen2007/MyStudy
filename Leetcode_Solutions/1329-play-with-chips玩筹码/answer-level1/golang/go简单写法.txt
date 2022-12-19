我感觉是最简单的写法
```
func minCostToMoveChips(chips []int) int {
    var odd,even int =0,0
	for _,x:=range  chips  {
		if x%2==0 {
			even++
		}else {
			odd++
		}
	}

	if odd>even {
		return even
	}else {
		return odd
	}
}
```
