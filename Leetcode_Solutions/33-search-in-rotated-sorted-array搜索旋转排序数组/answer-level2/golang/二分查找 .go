当对着正中央，对这个有序数组来一刀时

```
  start     mid      end
  * * * *   |   * * *
  [   有序 ]   [有序  ]
  [无序] [    有序   ]
  [     有序   ][无序]   

如果target == nums[mid]，返回
如果target 在有序一侧， nums[start] <= target < nums[mid]，就把搜索范围缩小，此时就是普通的二分查找了
如果在无序一侧，就继续一刀切，继续上两行的判断。
```


```
func search(nums []int, target int) int {
    s := 0
    e := len(nums) - 1
    var mid int
    for s <= e {
        mid = s + (e - s)>>1
        if nums[mid] == target {
            return mid
        }
        //mid的左侧有序
        if nums[s] <= nums[mid] {
            if target >= nums[s] && target < nums[mid] {
                e = mid - 1
            } else {
                s = mid + 1
            }
        } else {
            if target > nums[mid] && target <= nums[e] {
                s = mid + 1
            } else {
                e = mid - 1
            }
        }
    }
    return -1
}
```
