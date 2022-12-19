### 解题思路
======面向目标解题======
我们从最后往前反向思考此题。我们从数组最后一个元素len-1出发， 这个点肯定是能到达终点的对吧，我们现在就可以将注意点转向倒数第二个元素也就是len-2，看len-2是否能到达len-1，
也就是nums[len-2]+len-2>=len-1 是否为true，如果为true，此时我们就可以将关注点转移到别的0...len-3的点是否能到达len-2了，我们可以看len-3这个位置的元素是否满足nums[len-3]+len-3 >= len-2 是否为true，如果为false，那么继续向前探索len-4，，如果nums[len-4]+len-4 >= len-2 is true，此时说明我从len-4位置可以到达len-2，此时我们就可以将注意点转移到len-4，简单说起来，就是目标点的转移。。
### 代码

```golang
func canJump(nums []int) bool {
	num := len(nums)
	curNeedToArrive := num - 1
	for i := num - 1; i >= 0; i-- {
		if nums[i]+i >= curNeedToArrive {
			curNeedToArrive = i
		}
	}
	return curNeedToArrive == 0
}
```