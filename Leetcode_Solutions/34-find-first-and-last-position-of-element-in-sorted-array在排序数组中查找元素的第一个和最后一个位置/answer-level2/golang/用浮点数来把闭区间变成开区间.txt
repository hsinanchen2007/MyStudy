### 代码

```golang
func searchRange(nums []int, target int) []int {
    if len(nums) == 0 {
        return []int{-1, -1}
    }

    // 8 => 7.9 (left)
    l := float32(target) - 0.1

    // 8 => 8.1 (right)
    r := float32(target) + 0.1

    // find left
    lp, lFound := B(nums, l, "l", 0)

    // find right
    rp, rFound := B(nums, r, "r", 0)

    // if you found it on one side, just trust all results
    if lFound || rFound {
        return []int{lp, rp}
    }

    return []int{-1, -1}
}

func B(nums []int, target float32, t string, o int) (int, bool) {
    l := len(nums)

    if l == 1 {
        f := float32(nums[0])

        if t == "l" {
            sub := f - target

            // when nums[0] = 8, then 8 - 7.9 = 0.1
            // when nums[0] = 7, then 7 - 7.9 = -0.9
            // so when 0 < sub < 1, we found it
            if sub > 0 && f - target < 1 {
                return o, true
            } else {
                return o + 1, false
            }
        }

        if t == "r" {
            sub := target - f

            if sub > 0 && sub < 1 {
                return o, true
            } else {
                return o - 1, false
            }
        }
    }

    mid := int(l / 2)

    ls := nums[0:mid]
    rs := nums[mid:]

    if target < float32(ls[mid - 1]) {
        return B(ls, target, t, o)
    } else {
        return B(rs, target, t, o + mid)
    }
}
```