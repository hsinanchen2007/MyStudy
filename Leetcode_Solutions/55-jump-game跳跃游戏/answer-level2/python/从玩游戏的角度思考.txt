
```
def canJump(nums: List[int]) -> bool:
	length = len(nums)
	anagy = 0
	for i in range(0, length):
		anagy = max(anagy - 1, nums[i])
		if anagy <= 0 and i < length - 1:
			return False
	return True
```
 把这个问题想象成，成你每走到一个格子拿到固定的能量值（num[i]的数值），每走一步消耗一个能量值，然后看能不能到达目的地(nums的最后一个位置)的问题。

anagy = max(anagy - 1, nums[i])表示你走到i位置，能量值减一，再决定当前能量值。
满足anagy <= 0 and i < length - 1 ，表示，你在i位置(不是最后一个位置),你的能量值为空了，那么就失败了。