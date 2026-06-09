分别为奇偶长度处理。且一开始就为结果字符串申请好空间，利用模的数学性质得出目前需要处理的字符串下标，需要添加的字符种类。最后过滤不合法的数字。

48ms，7.8MB，双百分百；如果对字符串进行原位处理，空间可能更小

```rust
const CENTER_CHAR_SIZE: usize = 3;
const PAIR_CHAR_SIZE: usize = 5;
const CENTER_CHARS: [char; CENTER_CHAR_SIZE] = ['1', '8', '0'];
const PAIR_CHARS: [(char,char); PAIR_CHAR_SIZE] = [
    ('0','0'),
    ('6','9'),
    ('9','6'),
    ('1','1'), 
    ('8','8')];

impl Solution {
    #[allow(clippy::needless_range_loop)]
    pub fn find_strobogrammatic(n: i32) -> Vec<String> {
        if n<=0 {
            return vec![];
        }
        let mid = (n/2) as usize;
        let size = if n & 1==1 {
            usize::pow(PAIR_CHAR_SIZE,mid as u32) * CENTER_CHAR_SIZE
        } else {
            usize::pow(PAIR_CHAR_SIZE,mid as u32)
        };
        let mut result: Vec<Vec<char>> = vec![
           vec![' '; n as usize]; size];
        for i in 0..size {
            let mut k = i;
            for j in 0..mid {
                let kind = k % PAIR_CHAR_SIZE;
                result[i][j]=PAIR_CHARS[kind].0;
                result[i][n as usize - 1 - j] = PAIR_CHARS[kind].1;
                k /= PAIR_CHAR_SIZE;
            }
            if n & 1==1 {
                let kind = k % CENTER_CHAR_SIZE;
                result[i][mid]=CENTER_CHARS[kind];
            }
        }
        result.iter()
            .filter(|s| s.len()==1 || s[0]!='0')
            .map(|s| 
                s.iter()
                .collect::<String>()
            )
            .collect()
    }
}
```

