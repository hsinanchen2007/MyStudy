
### python 交换

```python []
class Solution:
    def findRepeatNumber(self, nums: List[int]) -> int:
        for i, j in enumerate(nums):
            if nums[i] == nums[j] and i != j:
                return nums[j]
            nums[i], nums[j] = nums[j], nums[i]
```

### python 集合

```python []
class Solution:
    def findRepeatNumber(self, nums: List[int]) -> int:
        d = set()
        for i in nums:
            if i in d:
                return i
            d.add(i)  
```

### rust 交换

```rust []
impl Solution {
    pub fn find_repeat_number(mut nums: Vec<i32>) -> i32 {
        for i in 0..nums.len() {
            let j = nums[i] as usize;
            if nums[i] == nums[j] && i != j {
                return nums[j];
            }
            nums.swap(i, j);
        }
        -1
    }
}
```

### rust 集合

```rust []
use std::collections::HashSet;
impl Solution {
    pub fn find_repeat_number(nums: Vec<i32>) -> i32 {
        let mut d = HashSet::new();
        for i in nums.iter(){
            if d.contains(i){
                return *i;
            }
            d.insert(*i);
        }
        -1
    }
}
```

### rust 数组

```rust []
impl Solution {
    pub fn find_repeat_number(nums: Vec<i32>) -> i32 {
        let mut v = vec![false; nums.len()];
        for i in nums.iter(){
            if v[*i as usize] == true{
                return *i;
            }
            v[*i as usize] = true;
        }
        -1
    }
}
```
