// 如果为0 则!(n==0) 为false  整个结果为false
// 如果不为0 则 !(n==0) 为true ， 主要看后面的
// 如果为2的幂 则二进制表示必为 10000 形式， 那么 n-1 的二进制为01111
// 则进行异或运算必为0
func isPowerOfTwo(n int) bool {
	return !(n==0) && 0 == (n & (n-1))
}