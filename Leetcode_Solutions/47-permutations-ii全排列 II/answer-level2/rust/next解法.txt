思路比较简单，用next函数获取下一个vec

```rust
impl Solution {
    pub fn next(nums:&Vec<i32>) -> Option<Vec<i32>> {
        let mut num1 = nums.clone();
        let mut nums_iter = nums.iter().enumerate().rev().peekable();
        while let Some((i,ref c)) = nums_iter.next() {
            if let Some((j, n)) = nums_iter.peek() {
                if n < c {
                    num1[i..].sort();
                    for k in i..num1.len() {
                        if num1[k] > num1[*j] {
                            num1.swap(*j,k);
                            return Some(num1);
                        }
                    }
                }
            }
        }
        None
    }
    pub fn permute_unique(nums: Vec<i32>) -> Vec<Vec<i32>> {
        let mut nums = nums;
        nums.sort();
        let mut res:Vec<Vec<i32>> = vec![nums.clone()];
        while let Some(n) = Solution::next(res.last().unwrap()) {
            res.push(n);
        }
        res
    }
}
```
