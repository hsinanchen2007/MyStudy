理解动态规划法求解，重点在于理解下面的for循环遍历所代表的意义：
1. 首先明确最重要的一点，这个遍历法是从当前的点（即当前index，i）往前看sum最大的值，这里有两种可能：
a. 之前的sum（即sum[i-1]，意为不包括当前节点i的累加和）小于零；
b. 之前的sum大于零；
由此，从当前节点看，如果是情况a，那么sum就是累赘被抛弃，最大sum就是当前节点值，即nums[i]
对应代码中的if...else...

2. ans记录的是整个遍历的过程中的最大sum。因为上面的最大sum是以当前节点为视角的，他只顾及自身利益，看别人是否累赘，而不管自己是否累赘都往上加（nums[i]为负）。ans不断去比较记录遍历过程中的最大累加和sum。

```
func maxSubArray(nums []int) int {

	var sum int
	var ans = nums[0]

	for i:=range nums{
		if sum>0{ //或写成sum+num>num更好理解
			sum=sum+nums[i]
		}else{
			sum=nums[i]
		}
		ans=int(math.Max(float64(ans),float64(sum)))
	}
	return ans
}
```
