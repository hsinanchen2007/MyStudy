```
use std::collections::HashMap;

impl Solution {    
    pub fn super_egg_drop(k: i32, n: i32) -> i32 {
        let mut dp: HashMap<(usize, usize), u64> = HashMap::new();
        let (mut left, mut right) = (1, n+1);
       
         if k == 1 {
            return n;
        }

        let t = loop {
            let mid = left + (right as f32- left as f32).log2() as i32;
            let floor = Self::drop_egg(k as usize, mid as usize, &mut dp);
            if floor > n as u64{
                right = mid;
            }else if floor < n as u64{
                left = mid+1;
            }else {
                break mid;
            }
            if left == right {
                break left;
            }
        };
        t as i32
    }

    pub fn drop_egg(k: usize, t: usize, dp: &mut HashMap<(usize, usize), u64>) -> u64 {
        if let Some(floor) = dp.get(&(k, t)) {
            return *floor;
        }
        if k == 1 || t == 1{
            return t as u64;
        }
        let floor = Self::drop_egg(k, t-1, dp) + Self::drop_egg(k-1, t-1, dp) + 1;
        dp.insert((k, t), floor);
        floor
    }
}
```
![image.png](https://pic.leetcode-cn.com/0ef4614160fa805e8051583d0fd72748a355f4156b86f8b048af17bad6ac00cd-image.png)
![image.png](https://pic.leetcode-cn.com/f593f611d979acb32b337fabd22d315e950a8a53919b0cd7e8c6199e14275898-image.png)

在labuladong大佬的第二种dp的前提下用递归做了二分(log2)，除了整数溢出的情况下基本都是0ms.
参考链接：https://leetcode-cn.com/problems/super-egg-drop/solution/ji-ben-dong-tai-gui-hua-jie-fa-by-labuladong/