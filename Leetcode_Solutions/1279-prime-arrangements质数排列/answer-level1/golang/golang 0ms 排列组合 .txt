这题主要是考察数学中的排列组合
判断一个数是质数很简单，这里不赘述。

n个数表示一共有n个坑位，需要在里面填数字。其中质数只能填在质数位上，我们需要计算n中质数的个数

1.使用排列组合的分组分堆，把这个大坑分成两小坑，第一个坑是质数， 第二坑是非质数。
2.排列组合解题思路，有序排列，无序组合， 显然每个坑的数字是有序的，所以A(n, n)即可


顺便科普一下排列组合小公式
![image.png](https://pic.leetcode-cn.com/531d460e7514e83e5cbd3865a176d47319a81296d9145ba8ba70989494a1eb50-image.png)


```
var mod = 1000000007

func numPrimeArrangements(n int) int {
	prims := []int{2,3,5,7,11,13,17,19,23,29,31,37,41,43,47,53,59,61,67,71,73,79,83,89,97}
	count := 0
	for i := 0; i < len(prims); i++ {
		if prims[i] <= n {
			count++
		} else {
			break
		}
	}
	return (A(count) * A(n - count))%mod
}

func A(x int) int {
	sum := 1
	for i := 2; i <= x; i++ {
		sum = (sum * i)%mod
	}
	return sum
}

```
