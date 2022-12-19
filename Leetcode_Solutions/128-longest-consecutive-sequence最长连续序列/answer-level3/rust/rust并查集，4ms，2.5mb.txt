好像还没有rust的并查集解法，来补充一个。


```rust
use std::cmp::max;
use std::collections::HashMap;
impl Solution {
    pub fn longest_consecutive(nums: Vec<i32>) -> i32 {

        struct UnionFind {
            mapper: HashMap<i32, i32>,
            nums: Vec<i32>
        }

        impl UnionFind {

            fn new(_nums: &Vec<i32>) -> UnionFind {
                UnionFind{
                    mapper: HashMap::new(),
                    nums: _nums.to_vec()
                }
            }

            fn add(&mut self, num: &i32) {
                self.mapper.insert(*num, *num);
            }

            fn contains(&self, num: &i32) -> bool {
                self.mapper.contains_key(num)
            }

            fn find(&self, num: &i32) -> i32 {
                let mut _num = *num;
                while _num != self.mapper[&_num] {
                    _num = self.mapper[&_num];
                }
                _num
            }

            fn union(&mut self, x: &i32, y: &i32) {
                let root_x = self.find(x);
                let root_y = self.find(y);
                if root_x != root_y {
                    self.mapper.insert(root_x, root_y);
                }
            }

            fn get_max_root(&self) -> i32 {
                let mut size_mapper: HashMap<i32, i32> = HashMap::new();
                for key in self.mapper.keys() {
                    let root = self.find(&self.mapper[key]);
                    if let Some(s) = size_mapper.get(&root) {
                        size_mapper.insert(root, s + 1);
                    } else {
                        size_mapper.insert(root, 1);
                    }
                }
                let mut max_root = 1;
                if self.nums.len() == 0 {
                    max_root = 0;
                }
                for key in size_mapper.keys() {
                    max_root = max(size_mapper[key], max_root);
                }
                max_root
            }
        }

        let mut uf = UnionFind::new(&nums);
        for num in nums {
            if uf.contains(&num) {
                continue;
            }
            uf.add(&num);
            if uf.contains(&(num - 1)) {
                uf.union(&num, &(num - 1));
            }
            if uf.contains(&(num + 1)) {
                uf.union(&num, &(num + 1));
            }
        }
        uf.get_max_root()

    }
}
```