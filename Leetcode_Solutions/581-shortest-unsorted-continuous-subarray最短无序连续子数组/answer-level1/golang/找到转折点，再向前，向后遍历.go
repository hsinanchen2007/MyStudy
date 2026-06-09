### 解题思路
此处撰写解题思路

### 代码

```golang
func findUnsortedSubarray(nums []int) int {
	start:=0
	end:=0
	flagStart:=true
	flagEnd:=true
    //找到转折的子数组
	for i,j:= 0,len(nums)-1;i< (len(nums)-1)&&j>=i; {
		fmt.Println("i  j  :",i,"  ",j)
		if flagStart&&nums[i]>nums[i+1]{
			start=i
			flagStart=false
		}
		if flagEnd&&nums[j]<nums[j-1]{
			end=j
			flagEnd=false
		}
		fmt.Println("start  ",start,"  ",end)
		if !flagStart&&!flagEnd{
			break
		}
        //当没有找到的时候，i往后遍历
		if flagStart{
			i++
		}
        //当没有找到的时候，j往前遍历
		if flagEnd{
			j--
		}

	}
    //如果start和end始终都没有找到，则返回0
	if start==end&&start==0{
		return 0
	}

    //找到转折子数组里面的最大和最小值
	x:=nums[start]
	y:=nums[end]
	for i:=start;i<=end;i++{
		if nums[i]<x{
			x=nums[i]
		}
		if nums[i]>y{
			y=nums[i]
		}
	}
    //要求前面的数都小于最小值
	for k:=0;k<start;k++{
		if nums[k]>x{
			start=k
			break
		}
	}

    //要求后面的数都大于最大值
	for k:= len(nums)-1;k>end;k--{
		fmt.Println("end:::",end)
		if nums[k]<y{
			end=k
			break
		}
	}

	return end-start+1
}
```