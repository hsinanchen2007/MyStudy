![image.png](https://pic.leetcode-cn.com/3ea00d27ec4649eb568cb8e7c7a26682d4e9768abb5897f53c743762807d919b-image.png)

```
impl Solution {
    pub fn find_continuous_sequence(target: i32) -> Vec<Vec<i32>> {
        let mut mid: f32 = 1.0;
        let mut res = Vec::new();
        loop {
            let num_f32 = target as f32 / mid;
            if (num_f32 as i32 as f32 == num_f32 && num_f32 >= 2.0) {
                let num = num_f32 as i32;
                let mut v = Vec::new();
                if (mid - mid as i32 as f32 == 0.5) && (num & 1 == 0) && ((mid - 0.5) as i32 - num / 2 >= 0) {
                    for i in ((mid + 0.5) as i32 - num / 2) as i32..((mid + 0.5) as i32 + num / 2) {
                        v.push(i);
                    }
                    res.push(v);
                } else if (mid - mid as i32 as f32 == 0.0) && (num & 1 == 1) && (mid as i32 - num / 2 >= 1) {
                    for i in (mid as i32 - num / 2) as i32..(mid as i32 + num / 2 + 1) {
                        v.push(i);
                    }                
                    res.push(v);
                }
            }
            mid += 0.5;
            if mid * 2 as f32 > target as f32 {
                break;
            }
        }
        res
    }
}
```
