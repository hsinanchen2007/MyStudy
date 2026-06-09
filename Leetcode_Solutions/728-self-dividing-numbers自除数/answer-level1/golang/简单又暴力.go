### 解题思路
此处撰写解题思路

### 代码

```golang
func selfDividingNumbers(left int, right int) []int {
	nums:=make([]int,0,right-left+1)
	HAHA:
	for i:=left;i<=right;i++{
		s:=strconv.Itoa(i)
		for j:=0;j< len(s);j++{
			if s[j]=='0'{
				continue HAHA
			}
		}
		n:=make([]int,0)
		tmp:=i
		for tmp>0{
			n= append(n, tmp%10)
			tmp/=10
		}
		flag:=true
		for k:=0;k< len(n);k++{
			if i%n[k]!=0{
				flag=false
			}
		}
		if flag{
			nums= append(nums, i)
		}
	}
	return nums
}

```