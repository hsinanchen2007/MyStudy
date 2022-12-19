### 解题思路
两个难度，一个是解决数据的去重问题，这里用到了 HashSet。一个是循环终止问题，这里是通过两个 while 来实现的。

### 代码

```rust

use std::collections::HashSet;
impl Solution {
    pub fn powerful_integers(x: i32, y: i32, bound: i32) -> Vec<i32> {
        if bound < 2 {
            return vec![];
        }
        let mut set = HashSet::new();
        let mut temp = 2;
        let mut i = 0;
        let mut j = 0;
        while temp <= bound {
            while temp <= bound {
                set.insert(temp);
                temp = x.pow(i) + y.pow(j);
                j += 1;
                if y == 1 && j > 1 {
                    break;
                }
            }
            i += 1;
            j = 0;
            temp = x.pow(i) + y.pow(j);
            if x == 1 && i > 1 {
                break;
            }
        }
        let res = set.iter().map(|x| *x).collect();
        res
    }
}

```