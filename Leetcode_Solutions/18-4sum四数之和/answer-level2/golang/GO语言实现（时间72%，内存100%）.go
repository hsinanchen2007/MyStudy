### 解题思路

双指针实现：
	遍历i指针取值[0，len-3]
	遍历j指针取值[i+1,len-2]
		遍历左<右
			左指针j+1
			右指针len-1

判定：
	判定添加是否重复


### 代码

```golang
package main

import (
	"fmt"
	"sort"
)

func judgeExist(list [][]int,temp []int) bool {
	var time int
	for i := 0;i<len(list);i++{
		time = 0
		for j :=0;j<len(temp) ;j++  {
			if list[i][j] != temp[j]{
				break
			}else{

				time++
			}
			if time ==len(temp){

				return true
			}
		}
	}
	return false
}

func fourSum(nums []int, target int) [][]int {
	sort.Ints(nums)

	var list [][]int
	var start,end,temp int
	for i :=0;i<len(nums)-3;i++{
		for j := i+1;j<len(nums)-2;j++{
			start = j+1
			end = len(nums)-1
			for start < end{
				temp = nums[i] + nums[j] + nums[start] + nums[end]
				if temp == target{
					tempList := make([]int,4,4)
					tempList[0],tempList[1],tempList[2],tempList[3] = nums[i],nums[j],nums[start],nums[end]
					exist := judgeExist(list,tempList)
					if !exist{
						list = append(list, tempList)
					}
					start++
					continue
				}else if temp > target{
					end--
				}else{
					start++
				}
			}
		}
	}
	return list
}


```