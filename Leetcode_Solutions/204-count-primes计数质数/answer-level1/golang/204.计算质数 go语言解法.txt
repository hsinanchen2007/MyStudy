### 解题思路

用Eratosthenes筛选法，将不是质数的全部筛选出去，留下质数。

原理如图所示：

![23d348bef930ca4bb73f749500f664ccffc5e41467aac0ba9787025392ca207b-1.gif](https://pic.leetcode-cn.com/b09d83030b25aab1966529eb3ee19e1ebb7b71390a5357008534eefb12929509-23d348bef930ca4bb73f749500f664ccffc5e41467aac0ba9787025392ca207b-1.gif)

图片来源：wikimedia


### 代码

```golang
func countPrimes(n int) int {
	isPri := make([]bool,n)
	for i := 2;i * i <= n;i++ {
		if !isPri[i]{
			for j := i * i;j < n;j += i {
				isPri[j]= true
			}
		}
	}
	count := 0
	for k:= 2;k < n;k++ {
		if !isPri[k] {
			count++
		}
	}
	return count
}
```