### 解题思路
因为是排序之后的，所以可以依次查看元素的后继元素是否大于自己，是的话就将之放到自己身后的位置（nums[i] = nums[j]），这样就可以将紧挨着的重复元素全移到后面去。
另外需要注意当临近元素已经大于自己了，就不需要再次赋值（见 if i!=j ）了，可以节约不少时间。
额外需要注意的是以上的思路适用于长度大于 1 的数组，所以需要判断一次长度，如果长度只有 1 或者 0，直接返回原本数组与长度即可。

### 代码

```rust
impl Solution {
    pub fn remove_duplicates(nums: &mut Vec<i32>) -> i32 {
        let len = nums.len();
        if len<2{
            return len as i32;
        }

        let mut i = 0;
      
        for j in 1..len{
            if nums[j]>nums[i]{
                i+=1;
                if i!=j{
                    nums[i] = nums[j];
                }
            }
        }

        (i+1) as i32
    }
}
```