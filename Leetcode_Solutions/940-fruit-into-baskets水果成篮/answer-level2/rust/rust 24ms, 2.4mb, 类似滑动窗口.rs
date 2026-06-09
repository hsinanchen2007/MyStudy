## 思路
当我们扫描整个数组的时候, 我们记录如下内容
- 当用的两种水果`fruit1, fruit2`
- 现在连续出现的水果`continuing_fruit`

当我们读下一个水果的时候, 我们策略如下
- 是正在连续出现的水果
    - 更改连续出现的水果数量
- 不是正在连续出现的水果
    - 是当用水果
        - 调整计数
    - 不是当用水果
        - 遵循先进先出的原则, `fruit2 => fruit1; fruit_new => fruit2`
    - 更改连续出现的水果
## 代码
这里要注意给Fruit实现Copy, 不然在for循环内`continuing_fruit `会与原有的数据解绑.
```rust
#[derive(Copy, Clone)]
struct Fruit {
    tp: i32,
    count: i32,
}
impl Solution {
    pub fn total_fruit(tree: Vec<i32>) -> i32 {
        let len = tree.len();
        let mut fruit1 = Fruit { tp: len as i32, count: 0, };
        let mut fruit2 = Fruit { tp: len as i32, count: 0, };
        let mut continuing_fruit = Fruit { tp: len as i32, count: 0, };

        let mut max_count = 0;
        
        for fruit_tp in tree {
            // first in first out
            if fruit_tp == fruit1.tp { fruit1.count += 1; }
            else if fruit_tp == fruit2.tp { fruit2.count += 1; }
            else {
                fruit1 = continuing_fruit;
                fruit2.tp = fruit_tp;
                fruit2.count = 1;
            }
            let total_count = fruit1.count + fruit2.count;
            if max_count < total_count { max_count = total_count; }

            if fruit_tp == continuing_fruit.tp { 
                continuing_fruit.count += 1; 
            } else {
                continuing_fruit.tp = fruit_tp;
                continuing_fruit.count = 1;
            }
        } 
        max_count
    }
}
```
