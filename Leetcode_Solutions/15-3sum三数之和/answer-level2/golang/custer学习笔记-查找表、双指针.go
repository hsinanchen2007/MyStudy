
# Python实现

## 思考

1. 暴力解法，三重循环O(N^3)
1. 因为a+b+c=0，所以枚举完a和枚举完b之后，c=-(a+b)是否存在于数组中。把整个数组放入set中，查询只需要O(1)，枚举a和b是两层循环，去set查询-（a+b）是否存在，总共O(N^2)，需要额外的set所以空间时间复杂度是O(N)

没有通过AC
```python
class Solution(object):
    def threeSum(self, nums):
        """
        :type nums: List[int]
        :rtype: List[List[int]]
        """
        if len(nums) < 3:
            return []
        nums.sort()
        res = set()
        for i, v in enumerate(nums[:-2]):
            if v>=1 and v==nums[i-1]:
                continue
            d = {}
            for x in nums[i+1:]:
                if x not in d:
                    d[-v-x] = 1
                else:
                    res.add((v, -v-x, x))
        return map(list, res)
```

3. 先排序再查找nlogn快排，第一层循环从起点位置开始枚举a，从剩余数组中查找b和c。因为先排序了，所以b和c可以向中间靠拢。如果a+b+c>0，则c从最右端向左移动一位。如果a+b+c<0，则b从最左端向右移动一位。看是否等于0的情况。因为b和c都是线性的往中间移动的，所以时间复杂度是O(N^2)。但是就地查找，没有新开辟set空间，所以空间复杂度是O(1)。

```python
class Solution(object):
    def threeSum(self, nums):
        """
        :type nums: List[int]
        :rtype: List[List[int]]
        """
        res = []
        nums.sort()
        for i in xrange(len(nums)-2):
            if i>0 and nums[i]==nums[i-1]:
                continue
            l, r = i + 1, len(nums) - 1
            while l < r:
                s = nums[i] + nums[l] + nums[r]
                if s<0: l+=1 # 左边界向右移动一步
                elif s >0: r -=1 # 右边界向左移动一步
                else:
                    res.append((nums[i], nums[l], nums[r]))
                    # 过滤重复的结果
                    while l < r and nums[l]==nums[l+1]:
                        l+=1
                    while l<r and nums[r]==nums[r-1]:
                        r -=1
                    l+=1;r-=1
        return res
```

# Go实现

```go
func threeSum(nums []int) [][]int {
    res := [][]int{}
    // 1. 排序
    sort.Ints(nums)
    // 2. 枚举
    for i := 0; i < len(nums)-2; i++ {
        if i > 0 && nums[i] == nums[i-1] {
            continue
        }
        left, right := i+1, len(nums)-1
        for left < right {
            s := nums[i] + nums[left] + nums[right]
            if s < 0 {
                left++
            } else if s > 0 {
                right--
            } else {
                res = append(res, []int{nums[i], nums[left], nums[right]})
                // 过滤重复的结果
                for left < right && nums[left] == nums[left+1] {
                    left++
                }
                for left < right && nums[right] == nums[right-1] {
                    right--
                }
                left++
                right--
            }
        }
    }
    return res
}
```


## 代码优化 

学习自[@aQuaYi](/u/aquayi)

```go
func threeSum(nums []int) [][]int {
        // 排序后，可以按规律查找
    sort.Ints(nums)
    res := [][]int{}

    for i := range nums {
        // 避免添加重复的结果
        // i>0 是为了防止nums[i-1]溢出
        if i > 0 && nums[i] == nums[i-1] {
            continue
        }

        l, r := i+1, len(nums)-1

        for l < r {
            s := nums[i] + nums[l] + nums[r]
            switch {
            case s < 0:
                // 较小的 l 需要变大
                l++
            case s > 0:
                // 较大的 r 需要变小
                r--
            default:
                res = append(res, []int{nums[i], nums[l], nums[r]})
                // 为避免重复添加，l 和 r 都需要移动到不同的元素上。
                l, r = next(nums, l, r)
            }
        }
    }

    return res
}

func next(nums []int, l, r int) (int, int) {
    for l < r {
        switch {
        case nums[l] == nums[l+1]:
            l++
        case nums[r] == nums[r-1]:
            r--
        default:
            l++
            r--
            return l, r
        }
    }

    return l, r
}
```

## 查找表实现
```go
// Using Hash Table to store all the numbers
// Time Complexity: O(n^2) Space Complexity: O(n)
func threeSum(nums []int) [][]int {
    var res [][]int
    counter := make(map[int]int)
    for _, value := range nums {
        counter[value]++
    }

    var uniqNums []int // Remove duplications
    for key := range counter {
        uniqNums = append(uniqNums, key)
    }
    sort.Ints(uniqNums)

    for i := 0; i < len(uniqNums); i++ {
        if uniqNums[i]*3 == 0 && counter[uniqNums[i]] >= 3 {
            res = append(res, []int{0, 0, 0})
        }
        for j := i + 1; j < len(uniqNums); j++ {
            if uniqNums[i]*2+uniqNums[j] == 0 && counter[uniqNums[i]] >= 2 {
                res = append(res, []int{uniqNums[i], uniqNums[i], uniqNums[j]})
            }
            if uniqNums[i]+uniqNums[j]*2 == 0 && counter[uniqNums[j]] >= 2 {
                res = append(res, []int{uniqNums[i], uniqNums[j], uniqNums[j]})
            }
            c := 0 - uniqNums[i] - uniqNums[j]
            if c > uniqNums[j] && counter[c] > 0 {
                res = append(res, []int{uniqNums[i], uniqNums[j], c})
            }
        }
    }
    return res
}
```

## 双指针实现
```go
// Using two pointers technique
// Time Complexity: O(n^2) Space Complexity: O(n)
func threeSum(nums []int) [][]int {
    sort.Ints(nums)
    var res [][]int
    index := 0
    for index < len(nums) {
        if nums[index] > 0 {
            break
        }
        bindex, cindex := index+1, len(nums)-1
        for bindex < cindex {
            if nums[bindex]+nums[cindex] == -nums[index] {
                res = append(res, []int{nums[index], nums[bindex], nums[cindex]})
                // continue to look for other pairs
                bindex = nex_num_index(nums, bindex)
                cindex = pre_num_index(nums, cindex)
            } else if nums[bindex]+nums[cindex] < -nums[index] {
                bindex = nex_num_index(nums, bindex)
            } else { // nums[bindex] + nums[cindex] > -nums[index]
                cindex = pre_num_index(nums, cindex)
            }
        }
        index = nex_num_index(nums, index)
    }
    return res
}

func nex_num_index(nums []int, cur int) int {
    for i := cur + 1; i < len(nums); i++ {
        if nums[i] != nums[cur] {
            return i
        }
    }
    return len(nums)
}

func pre_num_index(nums []int, cur int) int {
    for i := cur - 1; i >= 0; i-- {
        if nums[i] != nums[cur] {
            return i
        }
    }
    return -1
}
```