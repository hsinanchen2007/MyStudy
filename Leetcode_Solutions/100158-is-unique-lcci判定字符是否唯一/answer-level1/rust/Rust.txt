执行结果：
通过
显示详情
执行用时 :
0 ms
, 在所有 Rust 提交中击败了
100.00%
的用户
内存消耗 :
2.1 MB
, 在所有 Rust 提交中击败了
100.00%
的用户
炫耀一下:
```
//code style is bad
impl Solution {
    pub fn is_unique(astr: String) -> bool {
        let cs = astr.chars();
        let mut count = vec![0; ('z' as i32 as usize) + 1];//123
        for c in cs {
            count[(c as i32) as usize] += 1;
        }
        for &c in count.iter() {
            if c > 1 {
                return false;
            }
        }
        true
    }
}
```
更多rust-LeetCode   https://github.com/jxnu-liguobin/cs-summary-reflection/tree/master/rust-leetcode
