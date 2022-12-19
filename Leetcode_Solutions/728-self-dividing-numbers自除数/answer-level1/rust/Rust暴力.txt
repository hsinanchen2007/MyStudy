执行结果：
通过
显示详情
执行用时 :
4 ms
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
impl Solution {
    pub fn self_dividing_numbers(left: i32, right: i32) -> Vec<i32> {
        let mut result = Vec::new();
        for num in left..=right {
            if helper(num) {
                result.push(num)
            }
        }

        fn helper(n: i32) -> bool {
            for c in n.to_string().chars() {
                if ((c as i32) - 48) == 0 || n % ((c as i32) - 48) != 0 {
                    return false;
                }
            }
            return true;
        }

        result
    }
}
```
rust 实现
https://github.com/jxnu-liguobin/cs-summary-reflection/tree/master/rust-leetcode
