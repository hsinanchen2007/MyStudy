### 解题思路
一次遍历

### 代码

```rust
impl Solution {
    pub fn roman_to_int(s: String) -> i32 {
        fn get_value(c: char) -> i32 {
        match c {
            'I' => 1,
            'V' => 5,
            'X' => 10,
            'L' => 50,
            'C' => 100,
            'D' => 500,
            'M' => 1000,
            _ => 0,
        }
    }
    if s.is_empty(){
        return 0;
    }
    let mut sum = 0;
    let mut iter = s.chars().into_iter();
    let mut pre = get_value(iter.next().unwrap());
    iter.for_each(|v|{
        let cur = get_value(v);
        if pre < cur{
            sum -=pre;
        }else { 
            sum +=pre;
        }
        pre = cur;
    });
    sum+pre
    }
}
```