双指针查找，对最重和最轻的人的质量求和，小于等于limit则两个人坐一个船，否则把较重的一个人放进一条船。
```
class Solution:
    def numRescueBoats(self, people: List[int], limit: int) -> int:
        people.sort()
        i, j = 0, len(people) - 1
        cnt = 0
        while i <= j:
            if people[i] + people[j] <= limit:              #放两个人，指针方别向前向后移动
                i += 1
                j -= 1
            else:                                           #放一个人，后面的指针向前移动
                j -= 1
            cnt += 1
        return cnt
```
golang版本
```
import "sort"
func numRescueBoats(people []int, limit int) int {
    sort.Ints(people)
    cnt, i, j :=0, 0, len(people) - 1
    for i <= j {
        if people[i] + people[j] <= limit {
            i++
            j--
        } else{
            j--
        }
        cnt++
    }
    return cnt
}
```

