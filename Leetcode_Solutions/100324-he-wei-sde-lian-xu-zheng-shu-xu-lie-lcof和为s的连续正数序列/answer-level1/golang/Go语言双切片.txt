### 解题思路
双切片
![image.png](https://pic.leetcode-cn.com/403eb5d3b9fa779edb8c6bbe08e029eb4d15353193395b6511f365f51c0b8bcd-image.png)


### 代码

```golang
func findContinuousSequence(target int) [][]int {
	var mid = target / 2
	var small = make([]int,0) //当满足条件时，将连续的数记录
	var ans = make([][]int,0) //保存所有结果
	var tempCount = 0 //临时和，用来判断是否与target相等
	for i:=1;i<=mid;i++{ //最少两位，若存在则target必为奇数，[target/2,target/2 +1]
		for j:=i;j<=mid+1;j++{ //mid+1满足上面的注释中 target/2 + 1
			var tempEnd = j 
			if tempCount < target{
				tempCount = tempCount + j //小于则继续加下一位
			}
			if tempCount == target{ //i为起始点，j为终止点，向small里append即可
				for s:=i; s<= tempEnd;s++{
					small = append(small,s)
				}
				ans = append(ans,small)//存放
				small = make([]int,0) //small清零
				tempCount = 0 //tempCount清零
				break
			}
			if tempCount > target{
				tempCount = 0 //tempCount 清零
				break
			}

		}

	}
	return ans
}
```