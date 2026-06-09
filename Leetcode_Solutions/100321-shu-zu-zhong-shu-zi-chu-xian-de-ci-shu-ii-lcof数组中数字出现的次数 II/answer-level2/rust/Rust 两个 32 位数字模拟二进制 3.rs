0 ms; 2.2 MB

加法运算的优先级比位运算更高, 这个是俺没料到的, 折腾了好长时间, 加上括号就好了.

a 和 b 分别表示二进制的高位和低位, 组合起来可以表示从 0 到 2 三种状态.

最后 b 就表示只出现 1 次的那个数的所有比特位, 因为出现 3 次的数的比特位都清 0 了.

```rs
impl Solution {
    pub fn single_number(nums: Vec<i32>) -> i32 {
        // ab ab ab ab
        // 00 01 11 00
        let mut a = 0;
        let mut b = 0;
        for n in nums {
            let t = a;
            a = (n & !a & b) + (!n & a);
            b = (n & !t) + (!n & b);
            // println!("{:?}", (n, a, b));
        }
        b
    }
}
```