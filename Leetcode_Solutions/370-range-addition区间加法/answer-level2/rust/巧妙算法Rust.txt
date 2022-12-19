这道题有个很巧妙的算法：

假设数组长度为n，那么把区间i..j全部加上k，等价于两步：
1. 把i..n全部加上k
2. 把j+1..n全部减去k（加上负k）

因此，我们用`arr[i]`表示从i开始到最后每个元素都要加上的值。对于每次Update，`arr[i] += k,   arr[j+1] -= k`。
最终，从左到右直接累加即可求出最终数组:

```rust
impl Solution {
    pub fn get_modified_array(length: i32, updates: Vec<Vec<i32>>) -> Vec<i32> {
        let mut arr = vec![0; length as usize+1];
        for update in updates {
            let (i,j,k) = (update[0] as usize, update[1] as usize, update[2]);
            arr[i] += k;
            arr[j+1] -= k;
        }
        for i in 1..length as usize {
            arr[i] += arr[i-1];
        }
        arr.pop();
        arr
    }
}
```