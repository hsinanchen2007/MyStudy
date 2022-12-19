Rust：hashmap用于统计次数，heap用于按次数排序

执行用时 : 8 ms, 在Top K Frequent Elements的Rust提交中击败了100.00% 的用户

内存消耗 : 2.2 MB, 在Top K Frequent Elements的Rust提交中击败了100.00% 的用户

```
pub fn top_k_frequent(nums: Vec<i32>, k: i32) -> Vec<i32> {
    use std::collections::{BinaryHeap, HashMap};
    let len = nums.len();
    if len == 0 {
        return Vec::new();
    }
    if len == 1 {
        return nums;
    }
    let mut map: HashMap<i32, i32> = HashMap::new();
    for i in nums {
        let count = map.e***y(i).or_insert(0);
        *count += 1;
    }
    let mut heap = BinaryHeap::new();
    for v in map.iter() {
        heap.push((v.1, v.0));
    }
    let mut ret: Vec<i32> = Vec::new();

    for _ in 0..k {
        ret.push(heap.pop().unwrap().1.to_owned());
    }

    ret
}
```