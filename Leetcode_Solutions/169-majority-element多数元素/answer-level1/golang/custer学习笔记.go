# 思考

1. 暴力，第一个循环枚举每个x，第二个循环对每个x进行计数，O(N^2)
1. 涉及到计数，一般会想到map数据结构，key就是元素x，value就是x出现的次数时间空间都是O(N)
1. sort排序，重复的次数大于n/2就是解，排序时间复杂度是O(NlogN)
1. 分治：数组一份为2，分别找众数，如果left==right就是该值，如果不相同比较谁count最大O(NlogN)

# Go实现
## 方法二

```go
func majorityElement(nums []int) int {
    hash:=make(map[int]int)
    for i:=0; i< len(nums); i++{
        hash[nums[i]]++
    }
    key, value := 0, 0
    for k, v := range hash{
        if v > value {
            key = k 
            value = v
        }
    }
    return key
}
```

## 方法三

```go
func majorityElement(nums []int) int {
	sort.Slice(nums, func(i, j int) bool {
		return nums[i] < nums[j]
	})
	return nums[len(nums)/2]
}
```

## 方法五
摩尔投票算法-我们就先从数组的第一个元素开始，假定它代表的群体的人数是最多的，那么根据数组中出现次数超过一半的数只有一个的特质，如果我们设置一个计数器count，在遍历时遇到不同于这个群体的人时就将计数器-1，遇到同个群体的人时就+1，只要在计数器归0时就重新假定当前元素代表的群体为人数最多的群体再继续遍历，那么到了最后，计数器记录的那个群体必定是人最多的那个群体。这里就使得元素排序是不会造成任何影响的，只关心元素的个数所带来的对于计数器+1或-1的影响。

```go
func majorityElement(nums []int) int {
	current, count := 0, 0
	for _, v := range nums {
		if count == 0 {
			current = v
			count++ // 计算当前的数字出现的次数
		} else if current == v {
			count++
		} else {
			count--
		}
	}
	return current
}
```