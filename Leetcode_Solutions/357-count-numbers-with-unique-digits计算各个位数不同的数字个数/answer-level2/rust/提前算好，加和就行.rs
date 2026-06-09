```
impl Solution {
    pub fn count_numbers_with_unique_digits(n: i32) -> i32 {
        let count_per_len = 
           [1, // 0位数时的结果
            9, // 1位数时的结果
            9*9, // 2位数时的结果
            9*9*8, // 3位数时的结果
            9*9*8*7,
            9*9*8*7*6,
            9*9*8*7*6*5,
            9*9*8*7*6*5*4,
            9*9*8*7*6*5*4*3,
            9*9*8*7*6*5*4*3*2,
            9*9*8*7*6*5*4*3*2*1,
            ];
        // 求10^n之内的，只要把0-n内的加起来就行
        // 11位及以上必然重复
        if n < count_per_len.len() as i32 {
            return count_per_len[0..n as usize+1].iter().sum();
        }
        count_per_len.iter().sum()
    }
}

```
