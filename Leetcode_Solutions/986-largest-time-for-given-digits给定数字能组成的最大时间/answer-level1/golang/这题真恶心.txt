### 解题思路
此处撰写解题思路

### 代码

```golang
func largestTimeFromDigits(A []int) string {
	numsMap:=make(map[int]int)
	
	count3:=0
	count5:=0
	for _,v:=range A{
		if v<=3{
			count3++
		}
		if v<=5{
			count5++
		}
		numsMap[v]++
	}
	hour:=0
	if numsMap[2]>0&&count3>1&&count5>2{
		numsMap[2]--
		for i:=0;i<4;i++{
			if A[i]==2{
				hour+=A[i]*10
				if i<3{
					A=append(A[:i],A[i+1:]...)
				}else{
					A=A[:i]
				}
				break
			}
		}
		for x:=3;x>=0;x--{
			if numsMap[x]>0{
				for i:=0;i<3;i++{
					if A[i]==x{
						hour+=A[i]
						if i<2{
							A=append(A[:i],A[i+1:]...)
						}else{
							A=A[:i]
						}
						break
					}
				}
				break
			}
		}

		sort.Ints(A)
		if A[1]<=5{
			res:=""
			res+=strconv.Itoa(hour/10)
			res+=strconv.Itoa(hour%10)
			res+=":"
			res+=strconv.Itoa(A[1])
			res+=strconv.Itoa(A[0])
			return res
		}else{
			res:=""
			res+=strconv.Itoa(hour/10)
			res+=strconv.Itoa(hour%10)
			res+=":"
			res+=strconv.Itoa(A[0])
			res+=strconv.Itoa(A[1])
			return res
		}
	}else if (numsMap[1]>0)&&count5>1{
		numsMap[1]--
		for i:=0;i<4;i++{
			if A[i]==1{
				hour+=A[i]*10
				if i<3{
					A=append(A[:i],A[i+1:]...)
				}else{
					A=A[:i]
				}
				break
			}
		}
		sort.Ints(A)
		 if A[1]<=5{
			res:=""
			res+=strconv.Itoa(hour/10)
			res+=strconv.Itoa(A[2])
			res+=":"
			res+=strconv.Itoa(A[1])
			res+=strconv.Itoa(A[0])
			return res
		}else{
			res:=""
			res+=strconv.Itoa(hour/10)
			res+=strconv.Itoa(A[2])
			res+=":"
			res+=strconv.Itoa(A[0])
			res+=strconv.Itoa(A[1])
			return res
		}
	}else if numsMap[0]>0&&count5>1{
		numsMap[0]--
		for i:=0;i<4;i++{
			if A[i]==0{
				hour+=A[i]*10
				if i<3{
					A=append(A[:i],A[i+1:]...)
				}else{
					A=A[:i]
				}
				break
			}
		}
		sort.Ints(A)
		if A[1]<=5{
			res:=""
			res+=strconv.Itoa(hour/10)
			res+=strconv.Itoa(A[2])
			res+=":"
			res+=strconv.Itoa(A[1])
			res+=strconv.Itoa(A[0])
			return res
		}else{
			res:=""
			res+=strconv.Itoa(hour/10)
			res+=strconv.Itoa(A[2])
			res+=":"
			res+=strconv.Itoa(A[0])
			res+=strconv.Itoa(A[1])
			return res
		}

	}
	return ""
}

```