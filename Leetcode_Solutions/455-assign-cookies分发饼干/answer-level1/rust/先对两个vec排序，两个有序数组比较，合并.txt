先对两个vec排序；
排序后的数组，从sort s中找 >= sort g的值，找到删除；
当遍历完sort s都没有找到 >= sort g的元素，证明已经没有更大的饼干了；

时间复杂度O(n)，不算sort；


```
    pub fn find_content_children(g: Vec<i32>, s: Vec<i32>) -> i32 {
        let mut sort_g:Vec<i32> = g.clone();
        sort_g.sort();
        let mut sort_s = s.clone();
        sort_s.sort();
        let mut index = 0;
        let mut count = 0;

        'outer: for ch in sort_g.iter(){
            for ck in index..sort_s.len(){
                if sort_s[ck] >= *ch {
                    count += 1;
                    index = ck;
                    sort_s.remove(ck);
                    continue 'outer;
                }
            }
            return count;
        }

        count
    }
```
