### 解题思路
![2.png](https://pic.leetcode-cn.com/823343af45255b364833fbb31b7a9d1664b0bd4273b60c8fa39eeac0b30e906d-2.png)

**回溯法**是我来lc之后才知道的名字，我们原来比较喜欢称之为DFS，这个算法我也是第一次用Go实现它，果然问题还是出现了。
首先面临的是深浅拷贝的问题，不可以直接赋值，而需要将值拷贝出来在append进ans。
其次呢就是我脑残，不小心把num写成了nums，一直疯狂错，错的我莫名其妙orz

反正大致思想就是深度优先搜索，每次的参数就是去掉当前位之后的数组，一直到传进去的参数长度为0，那必然是把所有数用完了，就是我们需要的一个排序序列，我们把这个值copy出来，然后填进ans。

### 代码

```golang
func permute(nums []int) [][]int {
    temp:= []int{} //设计的排列缓存数组
	ans := [][]int{}	//最后的答案数组
	var dfs func(num []int)
	dfs = func(num []int) {
		if len(num) == 0 {	//决定将缓存写入答案的判断条件是参数数组长度为00
			tmp := make([]int,len(nums))
			copy(tmp,temp)	//必须copy出来，不然随着temp改变，ans也会改变
			ans = append(ans, tmp)
			return
		}else{
			for i := 0; i < len(num); i++ {
				temp = append(temp, num[i])	//把当前位加入缓存

				num1 := make([]int,len(num)-1)	//生成剩余位数组
				copy(num1[:i],num[:i])
				copy(num1[i:],num[i+1:])

				dfs(num1)	//对剩余位继续深搜

				temp = temp[:len(temp)-1]	//把之前加入缓存的去掉，这样下一次才能不重复
			}
		}
	}
	dfs(nums)	//对原始数组深搜
	return ans
}
```