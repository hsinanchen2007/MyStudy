### 解题思路
学习[@jyd](/u/jyd/)大佬的python3写法的golang写法
[大佬解法地址](https://leetcode-cn.com/problems/jian-sheng-zi-lcof/solution/mian-shi-ti-14-i-jian-sheng-zi-tan-xin-si-xiang-by/)

### 代码

```golang
func cuttingRope(n int) int {
    if n <= 3 {
        return n - 1
    }

    a, b, p := n / 3, n % 3, 1000000007
    if b == 0 {
        rem := remainder(3,a,p)
        return rem % p
    }
    if b == 1 {
        rem := remainder(3, a-1,p)
        return (rem * 4) % p  // 2 * 2 > 1 * 3: 少一个3，多一个2
    }
    // b == 2的情况
    rem := remainder(3,a,p)
    return (rem * 2) % p
}

// 求 (x^a) % p —— 循环求余法
// 大数越界情况下的求余问题
func remainder(x , a, p int) int {
	rem := 1
	for i:=0; i<a; i++ {
		rem = (rem * x) % p
	}
	return rem
}

// 主函数
func main() {
	n := 10
	fmt.Println(cuttingRope2(n))
}
```