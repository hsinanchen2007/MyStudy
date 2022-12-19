### 解题思路

(1)整个数组的和必须能被3整除，才能分为三部分。
(2)设这三部分每部分和为tmp，用flag来计算当前累加和cur_sum达到tmp的次数，每达到一次cur_sum	    置为0，flag+1。
(3)若最后flag == 3，则说明可以被分为三部分。
(4)当原数组和为0的时候，只要flag >= 3,即可被分成三部分。

### 代码

```golang
func canThreePartsEqualSum(A []int) bool {
	sum,tmp,cur_sum,flag := 0,0,0,0
	for i := 0;i < len(A);i++ {
		sum += A[i]
	}
	if sum % 3 != 0 {
		return false
	}
	tmp = sum / 3
	for j := 0;j < len(A);j++ {
		cur_sum += A[j]
		if cur_sum == tmp {
			flag++
			cur_sum = 0
		}
	}
    if sum == 0 {
	return flag >= 3
    }
    return flag == 3

	
}
```