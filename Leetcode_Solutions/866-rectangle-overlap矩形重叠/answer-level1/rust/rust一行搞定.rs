### 解题思路
此处撰写解题思路

### 代码

```rust
impl Solution {
    pub fn is_rectangle_overlap(rec1: Vec<i32>, rec2: Vec<i32>) -> bool {
        return (rec1.get(0).unwrap() < rec2.get(2).unwrap()) && (rec1.get(1).unwrap() < rec2.get(3).unwrap()) && (rec1.get(2).unwrap() > rec2.get(0).unwrap()) && (rec1.get(3).unwrap() > rec2.get(1).unwrap())
    }
}
```