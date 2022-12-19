```
use std::collections::{HashMap, VecDeque};

impl Solution {
    pub fn min_window(s: String, t: String) -> String {
        // store_t<letter :char, 0>
        let (mut map_t, mut deque_s, mut cnt) = (HashMap::new(), VecDeque::new(), 0);
        let (mut res, mut res_len) = (String::new(), std::usize::MAX);
        let (mut left, mut right, mut not_init) = (0, 0, true);

        for c in t.chars() {
            map_t.entry(c).or_insert(0);
            *map_t.get_mut(&c).unwrap() += 1;
            cnt += 1;
        }

        for c in s.chars() {
            if map_t.contains_key(&c) {                
                deque_s.push_back(right);
                if not_init {
                    not_init = false;
                    left = deque_s.pop_front().unwrap();   
                }

                let mut map_c = map_t.get_mut(&c).unwrap();
                if *map_c > 0 {
                    cnt -= 1;
                }    
                *map_c -= 1;
              
                if cnt == 0 {
                    if left == right {
                        res.push(c);
                        break;
                    }
                    while deque_s.front() != None {
                        // let mut left_char = s.chars().nth(left).unwrap(); //Don't do this!!!
                        let mut left_char = s[left..left+1].to_string().chars().next().unwrap();
                        map_c = map_t.get_mut(&left_char).unwrap();
                        *map_c += 1;
                        if *map_c > 0 {
                            let sub = s[left..right+1].to_string();
                            if res_len > sub.len() { res = sub; res_len = res.len();}     
                            left = deque_s.pop_front().unwrap();
                            cnt += 1;   
                            break;
                        }
                        left = deque_s.pop_front().unwrap();
                    }
                }
            }
            right += 1;
        }
        res
    }
}
```

![image.png](https://pic.leetcode-cn.com/544e1161c25770231b6445363677446d2a82d258513ec030b8ce3abae599280e-image.png)


