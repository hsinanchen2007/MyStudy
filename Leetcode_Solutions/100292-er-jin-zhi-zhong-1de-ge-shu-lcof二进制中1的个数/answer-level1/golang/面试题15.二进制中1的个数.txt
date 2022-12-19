### 解题思路
学习[@jyd](/u/jyd/)佬中佬的python3中的Golang写法
[大佬的超详细的思路分析](https://leetcode-cn.com/problems/er-jin-zhi-zhong-1de-ge-shu-lcof/solution/mian-shi-ti-15-er-jin-zhi-zhong-1de-ge-shu-wei-yun/)

### 知识点：位运算

### 代码

```golang
func hammingWeight(num uint32) int {
    res := 0
	for num!=0 {
		res += int(num & 1)	// 判断num最右一位是否为1，根据结果计数
		num >>= 1 // 讲二进制数字num无符号右移一位
	}

	return res
}

// 主函数
func main() {
	num := 15 // 15的二进制表示：1111
	fmt.Println(hammingWeight(uint32(num)))
}
```