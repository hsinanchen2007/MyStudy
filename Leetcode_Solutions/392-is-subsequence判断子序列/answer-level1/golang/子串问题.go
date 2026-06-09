### 解题思路
此处撰写解题思路

### 代码

```golang
func isSubsequence(s string, t string) bool {

	if len(s)==0{
		return true
	}
	nums:=make([]int32, 0)
	tt:=[]byte(t)
	m:=0 //标记 t 子串的 标记，当 s[i] 在 t[m]处找到 对应值的时候，只需要看 m后面的 子串中是否 还存在 s[i+1]
	for i,v:=range s{
		fmt.Println("i  ",i)

		for j:=m;j< len(tt);j++{

			if v==int32(tt[j]){
				fmt.Printf("i: %d j: %d v %c tt[j] %c \n",i,j, v,tt[j])
				nums=append(nums[:],int32(j)+1)
				tt[j]='0'
				m=j+1
				break

			}
		}

	}
	fmt.Println(nums)
	if len(nums)!= len(s){
		return false
	}
	for i:=0;i< len(nums)-1;i++{

		if nums[i]>=nums[i+1]||nums[i]==0{
			fmt.Println("你好：",nums[i],nums[i+1])
			return false
		}
	}
	return true
}
```