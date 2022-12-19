44ms, 9MB
![截屏2020-03-12下午10.26.31.png](https://pic.leetcode-cn.com/c1a076d2d992251099d00b8b113004937245f4b1664ea4a71e190934fe5f4650-%E6%88%AA%E5%B1%8F2020-03-12%E4%B8%8B%E5%8D%8810.26.31.png)


```
use std::collections::HashMap;

impl Solution {
    pub fn four_sum_count(a: Vec<i32>, b: Vec<i32>, c: Vec<i32>, d: Vec<i32>) -> i32 {
        let mut hashmap: HashMap<i32, i32> = HashMap::new();
        for i in &a {
            for j in &b {
                let score = hashmap.entry(*i + *j).or_insert(0);
                *score += 1;
            }
        }
        let mut res: i32 = 0;
        for i in &c {
            for j in &d {
                let score = hashmap.get(&(0 - *i - *j));
                if let Some(value) = score {
                    res += value;
                }
            }
        }
        res
    }
}
```
