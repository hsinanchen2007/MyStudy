这个问题可以泛化为

**在长度至少为 N（N >= 1）的有序数组（由小到大排序）`nums` 中，找出 N 个元素，它们的和最接近目标数 target，返回这 N 个数的和 sum**。

我们把这个问题记为 `closest_n_sum(nums, target, N)`。

算法：

1. 当 `N = 1` 时，通过二分法找到最接近的数，返回它；

2. 当 `N > 1` 时，从前到后遍历这个数组，对于在 `i` 处的元素 `num`：

    1. 计算 `num + closest_n_sum(nums[i+1:], target - num, n - 1)`，记为 `sums[i]`；

    2. 取 `sums` 的最小值，即为需要的结果 `sum`。

代码：

```Rust
pub fn three_sum_closest(mut nums: Vec<i32>, target: i32) -> i32 {
    nums.sort_unstable();
    closest_n_sum(&nums, target, 3)
}

fn closest_n_sum(nums: &[i32], target: i32, n: usize) -> i32 {
    if n == 1 {
        closest_num(nums, target)
    } else {
        let mut closest_sum: Option<i32> = None;
        for i in 0..=nums.len() - n {
            let num = nums[i];
            let sum = num + closest_n_sum(&nums[i + 1..], target - num, n - 1);
            if sum == target {
                return target;
            }
            let cs = closest_sum.get_or_insert(sum);
            if (*cs - target).abs() > (sum - target).abs() {
                *cs = sum;
            }
        }
        closest_sum.unwrap()
    }
}

fn closest_num(nums: &[i32], target: i32) -> i32 {
    let mut i = 0;
    let mut j = nums.len() - 1;

    if target < nums[i] {
        return nums[i];
    } else if target > nums[j] {
        return nums[j];
    }

    while j - i > 1 {
        let mid = (i + j) / 2;
        if target > nums[mid] {
            i = mid;
        } else if target < nums[mid] {
            j = mid;
        } else {
            return target;
        }
    }
    if target - nums[i] > nums[j] - target {
        nums[j]
    } else {
        nums[i]
    }
}
```