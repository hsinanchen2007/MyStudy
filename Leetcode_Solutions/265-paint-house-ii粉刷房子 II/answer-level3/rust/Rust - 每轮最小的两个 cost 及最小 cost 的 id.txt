记录每轮最小的 cost 和第二小的 cost，以及最小 cost 的 id。

下一轮中，对每个 color，当前 id 和上一轮最小 cost 的 id 不同时，则以第二小 cost 为基础，否则以最小 cost 为基础。

时间复杂度 O(nk) 空间复杂度 O(1)

![image.png](https://pic.leetcode-cn.com/73b683f571698ff4e3bd7b434f9316ad9e57d3e2bd27a798272b3efe2d95e3f3-image.png)


```rust
struct CostRecord {
    min_cost: i32,
    second_min_cost: i32,
    min_id: usize,
}

impl CostRecord {
    pub fn new(init_cost: i32) -> Self {
        Self {
            min_cost: init_cost,
            second_min_cost: init_cost,
            min_id: usize::max_value()
        }
    }

    pub fn add(&mut self, last_record: &CostRecord, id: usize, cost: i32) {
        let new_all_cost = (if id==last_record.min_id {
            last_record.second_min_cost
        } else {
            last_record.min_cost
        }) + cost;
        if new_all_cost < self.min_cost {
            self.second_min_cost = self.min_cost;
            self.min_cost = new_all_cost;
            self.min_id = id;
        } else if new_all_cost < self.second_min_cost {
            self.second_min_cost = new_all_cost;
        }
    }
}

impl Solution {
    pub fn min_cost_ii(costs: Vec<Vec<i32>>) -> i32 {
        if costs.len() == 0 {
            return 0;
        }
        let mut record = CostRecord::new(0);
        for i in 0..costs.len() {
            let mut new_record = CostRecord::new(i32::max_value());
            for j in 0..costs[i].len() {
                new_record.add(&record, j, costs[i][j]);
            }
            record = new_record;
        }
        record.min_cost
    }
}
```