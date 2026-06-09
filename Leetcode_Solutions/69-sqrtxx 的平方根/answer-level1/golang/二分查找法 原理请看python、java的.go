func mySqrt(x int) int {
    if x==0{
		return 0
	}
	start:=1
	end:=x
	for{
		center:=(end+start)/2
		if center==start{
			return start
		}
		if center*center>x{
			end=center
		}else if center*center<x{
			start=center
		}else{
			return center
		}
	}
}