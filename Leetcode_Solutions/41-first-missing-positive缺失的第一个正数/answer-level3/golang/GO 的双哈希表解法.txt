### 代码

```golang
func firstMissingPositive(nums []int) int {
    // m1 is used to store existing numbers
    m1 := map[int]bool{}

    // m2 is used to store anwsers
    m2 := map[int]bool{
        1: true,
    }

    for i := 0; i < len(nums); i++ {
        // if number < 1, ignore
        if nums[i] > 0 {
            // save number to m1
            m1[nums[i]] = true

            // remove number from answers
            if _, ok := m2[nums[i]]; ok {
                delete(m2, nums[i])
            }

            // bottom border
            if nums[i] - 1 > 0 {
                if _, ok := m1[nums[i] - 1]; !ok {
                    m2[nums[i] - 1] = true
                }
            }

            // top border
            if _, ok := m1[nums[i] + 1]; !ok {
                m2[nums[i] + 1] = true
            }
        }
    }

    r := 0

    // find the minimum value from m2
    for v := range m2 {
        if r == 0 || r > v {
            r = v
        }
    }

    return r
}
```