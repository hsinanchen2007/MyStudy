### 解题思路
因为房子[1]和房子[n]相邻，所以不能一起抢劫。因此，问题变成抢劫房屋[1]-房屋[n-1]或房屋[2]-房屋[n]，这取决于哪个选择提供更多的钱。现在，这个问题已经退化为抢劫房屋的人，这个问题已经解决了。

所以，状态还是跟上边相同，但是状态转移有变化

我选择的是使用两个dp

```
dp1[i] : 从第一间抢到n - 1间
```

所以初始化时是：

```
dp[0] = 0
dp[1] = nums[0]//抢第一间
```

但是不抢最后一间:所以是nums[i - 1]

```go
	for i := 2;i <len(nums);i++{
		dp1[i] = int(math.Max(float64(dp1[i - 2] + nums[i - 1]),float64(dp1[i - 1])))
	}
```

第二个dp

```
dp2[i]:从第二间到第 n 间
```

初始化：

```
dp2[0] = 0 //不抢第一间
dp2[1] = nums[1] //抢第二间
```

最后一间也抢

```
	for i := 2;i <len(nums);i++{
		dp2[i] = int(math.Max(float64(dp2[i - 2] + nums[i]),float64(dp2[i - 1])))
	}
```

最终代码

### 代码

```golang
func rob(nums []int) int {
    if len(nums) == 0{
		return 0
	}
	if len(nums) == 1{
		return nums[0]
	}
	if len(nums) == 2{
		return int(math.Max(float64(nums[0]),float64(nums[1])));
	}
	dp1 := make([]int, len(nums))
	dp1[0] = 0
	dp1[1] = nums[0]
	for i := 2;i <len(nums);i++{
		dp1[i] = int(math.Max(float64(dp1[i - 2] + nums[i - 1]),float64(dp1[i - 1])))
	}

	dp2 := make([]int, len(nums))
	dp2[0] = 0
	dp2[1] = nums[1]
	for i := 2;i <len(nums);i++{
		dp2[i] = int(math.Max(float64(dp2[i - 2] + nums[i]),float64(dp2[i - 1])))
	}
	return int(math.Max(float64(dp2[len(nums) - 1]),float64(dp1[len(nums) - 1])))
}
```