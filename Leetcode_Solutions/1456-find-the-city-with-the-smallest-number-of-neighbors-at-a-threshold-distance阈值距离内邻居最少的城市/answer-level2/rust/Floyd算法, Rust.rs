## 思路
这种问题叫**求多源最短路径**
我们一开始得到的图, 并非每条边都有值, 举个4*4的例子:
```rust
[
    [0,2,?,4],
    [2,0,?,?],
    [?,?,0,1],
    [4,?,1,0],
]
```
其中?为缺少的部分.
现在, 我们给这张不完整的图把每一条边都补全.

先让所有的问号都等于inf无限
每次我们都会选取一个中转节点`node = 0..4`, 然后检查`node`相邻的两个节点`a`,`b`:
- 对于这两个节点, 是否途经`node`会更近呢?
    - 是: 那么赋值`dis(node,a) + dis(node,b) => dis(a,b)`
    - 否: 保留原来的值

也就是说, 只允许所有的距离向更小的距离更新.

对每个节点都这样做一次后, 我们实际上, 对于任意一对点`(a,b)`已经计算了这些情况:
- 在没有选择节点时候,  `a`直接到`b`的距离
- 选取第一个节点后, `a`经由`[null, node_1]`任一组合到`b`的距离(null表示直接到达)
- 选取第二个节点后, `a`经由`[null, node_1, node_2]`任一组合到`b`的距离
- ...
- a经由所有节点任意组合到b的距离

并且, 我们在这些距离中, 选择了最小值. 这样就得到每个节点到每个节点的最短路径
## Code
我把INF定义为i32类型的最大值
并且有一点要注意的, 在计算距离的时候, 使用了饱和加法
```rust
let dis_by_node = dis_a.saturating_add(dis_b);
```
这个方法保证加法不会溢出, 也就是`inf + 任意正数 = inf`
```rust
const INF:i32 = i32::max_value();
impl Solution {
    pub fn find_the_city(n: i32, edges: Vec<Vec<i32>>, distance_threshold: i32) -> i32 {
        let n = n as usize;
        let mut dis_table = vec![vec![INF;n];n];
        // init table
        for edge in edges {
            let city1 = edge[0] as usize;
            let city2 = edge[1] as usize;
            let dis = edge[2] as i32;
            dis_table[city1][city2] = dis;
            dis_table[city2][city1] = dis;
        }

        for city_index in 0..n {dis_table[city_index][city_index] = 0;}

        // Floyd
        for city_node in 0..n {
            for city_a in 0..n {
                for city_b in 0..n {
                    // from a to b by node
                    let dis_a:i32 = dis_table[city_node][city_a];
                    let dis_b:i32 = dis_table[city_node][city_b];
                    let dis_by_node = dis_a.saturating_add(dis_b);
                    if dis_table[city_a][city_b] > dis_by_node {
                        dis_table[city_a][city_b] = dis_by_node;
                        dis_table[city_b][city_a] = dis_by_node;
                    }
                }
            }
        }
        // Trust me, there`s no INF by now.

        // Stat Part
        let mut city_least_neighbor = n;
        let mut least_record = INF;
        for city in 0..n {
            let mut neighbor_count = 0;
            for dstn in 0..n {
                if dis_table[city][dstn] <= distance_threshold { neighbor_count+=1; }
            }
            if neighbor_count < least_record {
                city_least_neighbor = city;
                least_record = neighbor_count;
            } else if neighbor_count == least_record {
                if city > city_least_neighbor {city_least_neighbor = city;}
            } 
        }
        // return as i32
        city_least_neighbor as i32
    }
}
```
