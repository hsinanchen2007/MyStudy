![image.png](https://pic.leetcode-cn.com/2077a799edfe5f609951ff133a531c4f8d09462ba782f0e221169e1bc9acd46a-image.png)

```
impl Solution {
    pub fn exchange(nums: Vec<i32>) -> Vec<i32> {
        if nums.len() == 0 {
            return nums;
        }
        let (mut res, mut l, mut r) = (nums.clone(), 0, nums.len() - 1);
        'a: while l < r {
            while res[l] & 1 == 1 {
                l += 1;
                if l >= r {
                    break 'a;
                }
            }
            while res[r] & 1 == 0 {
                r -= 1;
                if l >= r {
                    break 'a;
                }
            }
            res.swap(l, r);
            l += 1;
            r -= 1;
        }
        res
    }
}
```
