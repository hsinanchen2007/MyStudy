使用map记录出现次数和位运算异或方法,leetcode的性能图.让我大吃一惊
![image.png](https://pic.leetcode-cn.com/d0ac816bd0c1e69c9b159e1a053c7569d8a9558fa751dd2467f3d19012a2b1e0-image.png)

- map
```go
func SingleNumber2x(nums []int) int {
	var (
		map1 = make(map[int]int8)

	)
	for _, value := range nums {
		map1[value]  ++
	}
	for key,v := range map1 {
		if v == 1 {
			return key
		}

	}
	return 0
}
```
- 位运算
```go
func SingleNumber2(nums []int) int {
    a,b := 0,0
    for _,v := range nums {
        a = (a^v) & ^b
        b = (b^v) & ^a
    }
    return a
}
```
位运算的性能比map性能差??? @leetcode
```go
func BenchmarkSingleNumber2(b *testing.B) {
	var a = []int{1,1,1,3,3,3,5,5,5,2,6,6,6,8,8,8}
	b.ResetTimer()
	for i := 0; i <= b.N; i++ {
		SingleNumber2(a)
	}
}

func BenchmarkSingleNumber2x(b *testing.B) {
	var a = []int{1,1,1,3,3,3,5,5,5,2,6,6,6,8,8,8}
	b.ResetTimer()
	for i := 0; i <= b.N; i++ {
		SingleNumber2x(a)
	}
}
```

自己随便写了一个测试用例.测试相关性能
```tap
$ go test -bench=. -benchmem -run=none
goos: windows
goarch: amd64
pkg: gogs.wangke.co/go/algo/leetcode
BenchmarkSingleNumber2-4        63165872                24.6 ns/op             0 B/op          0 allocs/op
BenchmarkSingleNumber2x-4        2542356               472 ns/op              64 B/op          2 allocs/op
PASS
ok      gogs.wangke.co/go/algo/leetcode 3.508s

```
性能对比一览无遗~~
