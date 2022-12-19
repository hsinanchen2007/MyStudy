对abc进行排序，假定排完序后abc依次递增
条件1：b-a=c-b=1时，最小移动步数为0
条件2：不满足条件1， 那么看下b-a或者c-b有没有小于等于2的，有，那么最小移动步数为1
条件3：不满足条件1 2，那么最小移动步数为2
最大移动步数：
注意，这里是我不太理解的。我觉得以我对题意的理解，这题最大步数不是这么算的，比如
a=0,b=4,c=14
我可以先将a移动到7的位置，移动次数为7，移动后，位置变成[4,7,14]
再将4移动到10，移动次数为6，移动后，位置变成[7,10,14]
我认为这样的移动是符合题目给的条件的，但我此时就已经移动了13次了，而0 4 14的答案是12

题目想要我们求的最大移动步数，实际上是，max(a,b,c)-min(a,b,c)-2

代码如下：
```
func numMovesStones(a int, b int, c int) []int {
	arr:=[]int{a,b,c}
	var res []int
	sort.Ints(arr)
	minstps:=2
	if arr[1]-arr[0]==1&&arr[2]-arr[1]==1 {
		minstps=0
	}else{
		for i:=1;i<len(arr);i++{
			if arr[i]-arr[i-1]<=2 {
				minstps=1
				break
			}
		}
	}
	res=append(res, minstps)
	res=append(res,arr[2]-arr[0]-2)
	return res
}
```
