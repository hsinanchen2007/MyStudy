![搜狗截图19年11月22日1532_1.png](https://pic.leetcode-cn.com/72346b6d0b5785c0f72e23e74051e91d2a51f319bf3eeca0cee7177b626f269a-%E6%90%9C%E7%8B%97%E6%88%AA%E5%9B%BE19%E5%B9%B411%E6%9C%8822%E6%97%A51532_1.png)
func countPrimeSetBits(L int, R int) int {
	prime := make(map[int]bool)
	//因为[1, 10^6]没到20位,所以写到19就行
	prime[2] = true
	prime[3] = true
	prime[5] = true
	prime[7] = true
	prime[11] = true
	prime[13] = true
	prime[17] = true
	prime[19] = true
	ans := 0
	for i := L; i <= R; i++ {
		//这个函数bits.OnesCount可以直接计算置位...其他题看到的
		if prime[bits.OnesCount(uint(i)^0)] {
			ans++
		}
	}
	return ans
}