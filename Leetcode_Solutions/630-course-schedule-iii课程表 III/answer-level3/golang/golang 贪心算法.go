主要思路： 记录课程数使用的最短时间


首先根据结束时间排序，如果结束时间相同，课时短的在前，这样计算下一个课的时候就不用考虑上一个课的结束时间

举例： 有3个课程 [9, 10], [3, 12], [7, 17]

初始化所有课数最短时间为maxInt, 增加0课程数，方便计算。根据当前结束时间和总课长判断是否可以增加

[0, max, max, max]
1. [9, 10]: 只可以上一节课，即 [0, 9, max, max]
2. [3, 12]: 可以上一节课，也可以上两节课，上两节课的时候为12， 因为3 < 9， 所以上一个节的时间最小为3 [0, 3, 12, max]
3. [7, 17]:  [0, 3, 10, max]

再根据代码应该很好理解，具体代码：
```
func scheduleCourse(courses [][]int) int {
	sort.Slice(courses, func(i, j int) bool {
		if courses[i][1] == courses[j][1] {
			return courses[i][0] < courses[j][0]
		}
		return courses[i][1] < courses[j][1]
	})
	max := 0
	tl := make([]int, len(courses) + 1)
	for i := 0; i < len(courses); i++ {
		t, d := courses[i][0], courses[i][1]
		tl[i+1] = 2 << 31 // 初始化为最大值
		for j := i; j >= 0; j-- { //  注意：这里需要从最后一节课开始计算，防止修改前面的，对后面的造成影响
			tmp := t + tl[j]
			if tmp <= d && tmp < tl[j+1] { // 如果这节课可以在结束时间上完，并且时长小于之前的，优化
				tl[j+1] = tmp
				if max < j + 1 {
					max = j + 1
				}
			}
		}
	}
	return max
}
```
