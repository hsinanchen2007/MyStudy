package main

import "fmt"

func CanPlaceFlower(flowerBed []int,n int)bool{
	var length=len(flowerBed)
	var cnt=0
	for i:=0;i<length ;i++  {
		if flowerBed[i]==1{
			continue
		}
		var pre=i
		if pre==0{
			pre=0
		}else {pre=flowerBed[i-1]}
		var next=i
		if next==length-1{
			next=0
		}else {next=flowerBed[i+1]}
		if (pre==0&&next==0) {
			cnt++
			flowerBed[i]=1
		}
	}
	return cnt>=n
}
func main()  {
	var flowerBed=make([]int,6)
	var i,n int
	fmt.Scan(&i)
	for j:=0;j<i;j++{
		fmt.Scan(&flowerBed[j])
	}
	fmt.Println("输入目标n")
	fmt.Scan(&n)
	result:=CanPlaceFlower(flowerBed,n)
	fmt.Println(result)
}
