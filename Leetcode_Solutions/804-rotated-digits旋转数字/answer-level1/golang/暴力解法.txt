### 解题思路
此处撰写解题思路

### 代码

```golang
func rotatedDigits(N int) int {
	count:=0

	for i:=1;i<=N;i++{
		nums:=make([]int,0)
		tmp:=i
		flag:=true
		for tmp>0{
			switch tmp%10 {
            case 0:
                nums= append(nums,0)
			case 1:
				nums= append(nums,1)
			case 2:
				nums= append(nums,5)
			case 5:
				nums= append(nums,2)
			case 6:
				nums= append(nums,9)
			case 8:
				nums= append(nums,8)
			case 9:
				nums= append(nums,6)
			default:
				flag=false
				break
			}
			tmp/=10
		}
		if flag{
			y:=0
			for j:=0;j< len(nums);j++{
				y+=nums[j]*int(math.Pow10(j))
			}
			if y!=i{
				count++
			}
		}
	}
	return count
}

```