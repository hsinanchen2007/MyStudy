### 解题思路


### 代码

```golang
func asteroidCollision(asteroids []int) []int {

	stack := make([]int, 0, len(asteroids))
	for _, num := range asteroids {
		if len(stack) == 0 {
			stack = append(stack, num)
		} else {
			win := true
			for len(stack) > 0 &&  stack[len(stack)-1] > 0 && num < 0 {
				left := stack[len(stack)-1]
				right := -num
				if left < right {
					stack = stack[:len(stack)-1]
				} else {
					if left == right {
						stack = stack[:len(stack)-1]
					}
					win = false
					break
				}
			}
			if win {
				stack = append(stack, num)
			}
		}
	}
	return stack
}

```