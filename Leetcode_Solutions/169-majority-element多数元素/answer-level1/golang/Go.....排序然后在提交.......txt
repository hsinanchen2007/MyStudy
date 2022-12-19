func majortyElement(num []int) int {
	sort.Ints(num)
	return num[len(num)/2]
}
![题解.png](https://pic.leetcode-cn.com/63bc6b37f5e6cf44d3158802cae277069ae44151ab869a2de2bcabb85e5d4102-%E9%A2%98%E8%A7%A3.png)
