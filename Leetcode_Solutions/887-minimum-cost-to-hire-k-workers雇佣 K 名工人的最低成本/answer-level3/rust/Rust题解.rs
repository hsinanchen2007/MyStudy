思路同官方，用了以前做的堆（kthLargest）

执行用时 8 ms, 在所有 Rust 提交中击败了 100.00% 的用户
内存消耗 2.3 MB, 在所有 Rust 提交中击败了 100.00% 的用户

```
//#[derive(Debug)]
pub struct Heap {
    heap:           Vec<i32>,
    size:           usize,
    heap_maxsize:   usize,
}

impl Heap {
    pub fn new(k: i32, nums: Vec<i32>) -> Self {
        let mut New_Heap = Heap {
            heap            :   vec![-1],
            size            :   0,
            heap_maxsize    :   k as usize,
        };
        for i in &nums {
            New_Heap.add(*i);
        }
        New_Heap
    }

    pub fn add(&mut self, val: i32) -> i32 {
        if self.size < self.heap_maxsize {
            self.heap.push(val);
            self.size += 1;
            self.up(self.size);
        } else if self.heap[1] < val {
            self.heap[1] = val;
            self.down(1);
        }
        self.heap[1]
    }

    fn up(&mut self, location: usize) {
        if (location >> 1 > 0) && (self.heap[location >> 1] > self.heap[location]) {
            self.adjust(location >> 1, location);
            self.up(location >> 1);
        }
    }

    fn down(&mut self, location: usize) {
        if ((location << 1) + 1 <= self.size) && (self.heap[(location << 1) + 1] <= self.heap[(location << 1)]) && (self.heap[(location << 1) + 1] < self.heap[location]) {
            self.adjust((location << 1) + 1, location);
        } else if ((location << 1) == self.size) && (self.heap[(location << 1)] < self.heap[location]) || ((location << 1) + 1 <= self.size) && (self.heap[(location << 1) + 1] >= self.heap[(location << 1)]) && (self.heap[(location << 1)] < self.heap[location]) {
            self.adjust(location << 1, location);
        }
    }

    fn adjust(&mut self, i: usize, j: usize) {
        self.heap.swap(i, j);
        self.down(i);
    }
}

pub struct Efficiency {
    location    :   usize,
    value       :   f64,
}

impl Solution {
    pub fn mincost_to_hire_workers(quality: Vec<i32>, wage: Vec<i32>, k: i32) -> f64 {
        let mut values = Vec::new();
        let mut cnt: usize = 0;
        let mut res: f64 = 0 as f64;

        for i in &quality {
            values.push(Efficiency{
                location    :   cnt,
                value       :   wage[cnt] as f64 / *i as f64,
            });
            cnt += 1;
        }
        values.sort_by(|a, b| {
            a.value.partial_cmp(&b.value).unwrap()
        });
        let mut heap = Heap::new(k, vec![]);
        let mut sum: i32 = 0;
        for i in 0..k {
            heap.add(- quality[values[i as usize].location]);
            sum += quality[values[i as usize].location];
        }
        res = sum as f64 * (values[(k - 1) as usize].value);
        //println!("{:?}, {}, {}, {}", heap, res, sum, values[(k - 1) as usize].value);
        for i in k..cnt as i32 {
            if quality[values[i as usize].location] < - heap.heap[1] {
                sum = sum + heap.heap[1] + quality[values[i as usize].location];
                heap.add(- quality[values[i as usize].location]);
            }            
            if res > sum as f64 * (values[i as usize].value) {
                res = sum as f64 * (values[i as usize].value)
            }
            //println!("{:?}, {}, {}, {}", heap, res, sum, values[i as usize].value);
        }
        res
    }
}
```
