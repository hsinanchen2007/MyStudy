### 解题思路
此处撰写解题思路
这个题依照归并排序的合并算法即可。首先分配一个长度为m的数组用来存储数组a的元素，然后开始合并即可。
### 代码

```rust
impl Solution {
    pub fn merge(a: &mut Vec<i32>, m: i32, b: &mut Vec<i32>, n: i32) {
        let mut tmp = Vec::with_capacity(m as usize);
        for idx in 0..m {
            tmp.push(a[idx as usize]);
        }
        let mut a_idx = 0;
        let mut b_idx = 0;
        let mut ans_idx = 0;
        while a_idx != m && b_idx != n {
            if tmp[a_idx as usize] > b[b_idx as usize] {
                a[ans_idx as usize] = b[b_idx as usize];
                b_idx += 1;
                ans_idx += 1;
            } else {
                a[ans_idx as usize] = tmp[a_idx as usize];
                a_idx += 1;
                ans_idx += 1;
            }
        } 
        if a_idx == m {
            while b_idx != n {
                a[ans_idx as usize] = b[b_idx as usize];
                ans_idx += 1;
                b_idx += 1;
            }
        } else {
            while a_idx != m {
                a[ans_idx as usize] = tmp[a_idx as usize];
                ans_idx += 1;
                a_idx += 1;
            }
        }
    }
}
```