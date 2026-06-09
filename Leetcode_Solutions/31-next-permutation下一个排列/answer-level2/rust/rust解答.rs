### 解题思路
常规做法，判断An-1<An调换最后两个元素的位置，如果An-1>An,比较An-1和An-2，以此类推，直到存在前一个数比后一个数小的情况。此时调换此较小的数（假设此数索引为ｉ）和位置在ｉ之后的且比Ai大的最小的数。i后面的数从小到大排序。如果不存在，说明是字典序的最后排列，将全数组排序。此题为生成组合的变种。

### 代码

```rust
impl Solution {
    pub fn next_permutation(nums: &mut Vec<i32>) {
    if nums.len()<=1{
        return;
    }
    let mut max = i32::min_value();
    let mut len = nums.len();
    if nums[len -1] > nums[len -2]{
        nums.swap(len -1, len -2)
    }
    else {
        let mut index = len - 2;
        let mut i = 0;
        let mut is_break = false;
        while index > 0{
            if nums[index] > nums[index-1]{
                let mut min = index;
                for j in index..len{
                    if nums[j] > nums[index-1] && nums[j] < nums[min]{
                        min = j
                    }
                }
                nums.swap(index -1, min);
                nums[index..len].sort();
                is_break = true;
                break
            }
            else {
                index = index - 1
            }
        }
        if is_break == false{
            nums.sort();
        }
    }
}
}
```