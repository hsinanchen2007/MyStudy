原理上都是先对数组排序，然后再去根据排序的情况求值
我这边根据题目条件列了个数组arr，长度为100
对每个dominoes[i][0]和dominoes[i][1]进行比较，比如[2,3]，那么就让arr[23]++，[3,2]也是让arr[23]++,这样在对dominoes遍历完成后，就可以直接遍历arr，每当arr[i]>1时，就更新一次sum
当然，这个方法在dominoes数组较短的情况下，时间复杂度会比较高，但我个人认为，当dominoes数组长度很大时，这样的时间复杂度应该会更好一些。
以下是代码：
```
func numEquivDominoPairs(dominoes [][]int) int {
	res:=make([]int,100)
	max,min,temp:=0,0,0
	for i:=0;i<len(dominoes);i++{
		if dominoes[i][0]<dominoes[i][1] {
			min,max=dominoes[i][0],dominoes[i][1]
		}else{
			min,max=dominoes[i][1],dominoes[i][0]
		}
		temp=min*10+max
		res[temp]++
	}
	sum:=0
	for i:=11;i<len(res);i++{
		if res[i]!=0 {
			sum+=res[i]*(res[i]-1)/2
		}
	}
	return sum
}
```
