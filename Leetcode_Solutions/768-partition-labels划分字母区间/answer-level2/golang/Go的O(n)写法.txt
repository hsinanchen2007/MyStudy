这题难度肯定是不高的，但贪心的原则如果使用暴力的算法，那么时间复杂度还是会很高的。
于是我的思路变成，如何在时间复杂度上尽可能的少？
根据观察可以发现，对于字符串中出现的每一个元素，我们只需要它第一次出现的位置和最后一次出现的位置。
那么两次遍历即可。
第一次遍历，将所有字母的第一次出现和最后一次出现记录下来
第二次遍历，可以使用第一遍历的数据进行计算。
这题最后的执行在时间复杂度上达到了100%

```golang
func partitionLabels(S string) []int {
	var res []int
	arr:=make([][]int,26)
	used:=make([]int,26)
	for i:=0;i<len(S);i++{
		temp:=S[i]-'a'
		if len(arr[temp])<=1{
			arr[temp]=append(arr[temp], i)
		}else{
			arr[temp][1]=i
		}
	}
	for i:=0;i<len(S);i++{
		temp:=S[i]-'a'
		used[temp]=1
		if len(arr[temp])==1 {
			res=append(res,1)
		}else{
			span:=[]int{arr[temp][0],arr[temp][1]}
			for j:=span[0];j<=span[1];j++{
				temp2:=S[j]-'a'
				if used[temp2]==0{
					used[temp2]=1
					if len(arr[temp2])>1&&arr[temp2][1]>span[1]{
						span[1]=arr[S[j]-'a'][1]
					}
				}
			}
			res=append(res,span[1]-span[0]+1)
			i=span[1]
		}
	}
	return res
}
```