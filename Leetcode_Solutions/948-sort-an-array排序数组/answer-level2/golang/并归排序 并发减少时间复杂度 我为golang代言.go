### 解题思路
并发 完成o（n）时间复杂度  我为golang代言

### 代码

```golang
func sortArray(nums []int) []int {
    ret := []int{}
    arr := make(chan int, len(nums))
    Sort(nums, arr)
    for i := 0; i < len(nums); i++ {
		ret = append(ret,<-arr)
	}
    return ret
}

func Sort(arr []int, ch chan int) {
	defer close(ch)
	if len(arr) <= 1 {
		if len(arr) == 1 {
			ch <- arr[0]
		}
		return
	}
	mid := len(arr) / 2
	s1 := make(chan int, mid)
	s2 := make(chan int, len(arr)-mid)
	go Sort(arr[:mid], s1)
	go Sort(arr[mid:], s2)
	Merge(s1, s2, ch)
}

func update(s chan int, ch chan int, c *int, ok *bool) {
	ch <- *c
	*c, *ok = <-s
}

func Merge(s1, s2, ch chan int) {
	v1, ok1 := <-s1
	v2, ok2 := <-s2
	for ok1 && ok2 {
		if v1 < v2 {
			ch <- v1
			v1, ok1 = <-s1
		} else {
			ch <- v2
			v2, ok2 = <-s2
		}
	}
	for ok1 {
		ch <- v1
		v1, ok1 = <-s1
	}
	for ok2 {
		ch <- v2
		v2, ok2 = <-s2
	}
}
```