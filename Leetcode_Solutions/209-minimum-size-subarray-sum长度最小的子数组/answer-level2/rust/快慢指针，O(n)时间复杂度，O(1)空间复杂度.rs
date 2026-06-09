```
// 输入: s = 7, nums = [2,3,1,2,4,3]
// 输出: 2
// 解释: 子数组 [4,3] 是该条件下的长度最小的连续子数组。
pub fn min_sub_array_len(s: i32, nums: Vec<i32>) -> i32 {
    let mut right = 0;
    let mut sum = 0;
    let mut min = 0;
    let len = nums.len();

    for i in 0..len {
        sum += nums[i];
        if sum >= s {
            right = i;
            break;
        }
    }
    if sum < s{
        return 0;
    }
    min = right + 1;

    'outer: for i in 1..len {
        sum = sum - nums[i - 1];
        while sum < s {
            right += 1;
            if right >= len {
                continue 'outer;
            }
            sum = sum + nums[right];
        }

        min = if min < right - i + 1 {
            min
        } else {
            right - i + 1
        };
    }

    min as i32
}
```
