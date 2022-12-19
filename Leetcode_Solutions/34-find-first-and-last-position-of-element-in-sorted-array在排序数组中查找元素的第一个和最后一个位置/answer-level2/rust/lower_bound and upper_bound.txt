```rust
/**
 *   (L + R) >> 1 偏向左边，所以每次循环L一定要 + 1否则死循环，比如说L = 1, R = 2, mid此时也等于L
 *   (L + R + 1) >> 1 偏向右边，所以每次循环R一定要 - 1
 *   lower_bound因为结果偏向左边，所以mid永远不会真正达到R， 所以R应当比实际最大index多1也即nums.len()
 *   upper_bound因为结果偏向右边，所以mid永远不会达到L，所以L应当比实际最小index少1，也就是-1
 *   但是负数不能作为usize，所以代码里upper_bound的L和R实际上是有一个1的offset。所以mid也比真正的mid大1，所以取真正的下标的时候需要mid - 1
 */
// @lc code=start
impl Solution {
    fn lower_bound(nums: &Vec<i32>, target: i32) -> Option<usize> {
        let (mut L, mut R) = (0, nums.len());
        let mut index = None;
        while L < R {
            let mid = (L + R) >> 1;
            if nums[mid] < target {
                L = mid + 1;
            } else {
                if nums[mid] == target {
                    index = Some(mid);
                }
                R = mid;
            }
        }
        index
    }

    fn upper_bound(nums: &Vec<i32>, target: i32) -> Option<usize> {
        let (mut L, mut R) = (0, nums.len());
        let mut index = None;
        while L < R {
            let mid = (L + R + 1) >> 1;
            if nums[mid - 1] > target {
                R = mid - 1;
            } else {
                if nums[mid - 1] == target {
                    index = Some(mid - 1);
                }
                L = mid;
            }
        }
        index
    }
    pub fn search_range(nums: Vec<i32>, target: i32) -> Vec<i32> {
        if let Some(left) = Self::lower_bound(&nums, target) {
            if let Some(right) = Self::upper_bound(&nums, target) {
                return vec![left as i32, right as i32];
            }
        }
        vec![-1, -1]
    }
}
```