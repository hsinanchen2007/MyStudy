```rust
pub fn valid_mountain_array(a: Vec<i32>) -> bool {
    let mut reverse = false;

    for i in 1..a.len() {
        if a[i] == a[i - 1] {
            return false;
        }

        if !reverse {
            if a[i] < a[i - 1] {
                if i == 1 {
                    return false;
                }
                reverse = true;
            }
        } else {
            if a[i] > a[i - 1] {
                return false;
            }
        }
    }

    reverse
}
```
