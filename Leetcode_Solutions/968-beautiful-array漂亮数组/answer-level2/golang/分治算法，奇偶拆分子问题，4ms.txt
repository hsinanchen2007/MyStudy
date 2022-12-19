```
// 分治算法，思路参考官方解题方案一
func beautifulArray(N int) []int {
    // 递归结束条件
	if N == 1 {
		return []int{1}
	}
	// 根据奇偶进行映射
    odds := beautifulArray((N+1)/2) // 1~N的值中取出全部奇数，通过(a+1)/2映射得到的1~（N+1)/2范围的连续值，
	evens := beautifulArray(N/2) // 返回右侧已排序切片
    
	// 根据奇偶进行反射
    for i, v := range odds { 
		odds[i] = 2*v -1
	}
	for i, v := range evens {
		evens[i] = 2*v
	}
    // 将左右子问题答案进行拼接
	sli := append(odds, evens...) // cap不足则产生新的地址返回，保证不同递归层互不影响

	return sli
}
```