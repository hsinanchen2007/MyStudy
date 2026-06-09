先求两个数组的和，把每个和的次数存起来，再求另外两个数组元素的和，0-这两个数的和，在map中查找是否有对应的key，有的话对应的value是对应的次数，所有value相加即总个数
```
func fourSumCount(A []int, B []int, C []int, D []int) int {
    m := map[int]int{}
	for _, a := range A {
		for _, b := range B {
			sum := a+b
			m[sum]++
		}
	}
	r := 0
	for _, c := range C {
		for _, d := range D {
			sum := 0-(c+d)
			r += m[sum]
		}
	}
	return r 
}
```
