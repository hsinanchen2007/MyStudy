耗时：12ms
内存:   3MB

首先观察可以得出，从1,3,7,9是对称的，2,4,6,8也是对称的，5单独算。因此总数为4*t1+4*t2+t3。
接下来看怎么算t1 t2 t3

由于是九宫格，可以用`[3][3]bool`来表示每个格子的状态。但是更进一步可以发现，9个格子，其实可以利用位运算，把状态压缩成一个int32。第i个格子为true相当于把数字的第i位设置为1.每次走的时候判断下这种走法是否可行即可。

这道题卡了我很久，因为我认为以下这种走法是不合法的：
`2->3->1`
所以对这种场景我做了特殊处理。题目描述并没有说清楚这是否合法，或者比较牵强。但是从这道题目的测试数据来看，这种走法也是合法的…

```rust
#[derive(Copy, Clone)]
struct State(i32, i32);

impl State {
    fn new(x: i32, y: i32) -> Self {
        let p = Self::convert(x,y);
        Self(1<<p, p)
    }
    fn convert(x: i32, y: i32) -> i32 {
        match (x,y) {
            (0,0) => 1,
            (0,1) => 2,
            (0,2) => 3,
            (1,0) => 4,
            (1,1) => 5,
            (1,2) => 6,
            (2,0) => 7,
            (2,1) => 8,
            (2,2) => 9,
            _ => unreachable!()
        }
    }
    fn pos_to_loc(p: i32) -> (i32, i32) {
        match p {
            1 => (0,0),
            2 => (0,1),
            3 => (0,2),
            4 => (1,0),
            5 => (1,1),
            6 => (1,2),
            7 => (2,0),
            8 => (2,1),
            9 => (2,2),
            _ => unreachable!(),
        }
    }
    fn get_loc(&self) -> (i32, i32) {
        Self::pos_to_loc(self.1)
    }
    fn set_as_visited(&self, x: i32, y: i32) -> Self {
        let p = Self::convert(x,y);
        Self(self.0 | (1<<p), p)
    }
    fn is_visited(&self, x: i32, y: i32) -> bool {
        let p = Self::convert(x,y);
        let t = 1<<p;
        self.0 & t == t
    }
}

impl Solution {
    pub fn number_of_patterns(m: i32, n: i32) -> i32 {
        if m > n {
            return 0;
        }
        let a = 4*Self::bfs(0,0,m,n);
        let b = 4*Self::bfs(1,0,m,n);
        let c = Self::bfs(1,1,m,n);
        a+b+c
    }
    fn bfs(xx: i32, yy: i32, m: i32, n: i32) -> i32 {
        let steps = [(0,1),(0,-1),(1,0),(-1,0),(1,1),(1,-1),(-1,1),(-1,-1),(1,2),(1,-2),(-1,2),(-1,-2),(2,1),(2,-1),(-2,1),(-2,-1)];
        let steps_line = [(2,0),(0,2),(-2,0),(0,-2),(2,2),(2,-2),(-2,2),(-2,-2)];
        let mut count = 0;
        let mut q = vec![(State::new(xx,yy), 1)];
        let mut head = 0;
        while head < q.len() {
            let (state, step) = q[head];
            head += 1;
            if step >= m {
                count += 1;
            }
            if step >= n {
                continue;
            }
            let (x,y) = state.get_loc();
            for (dx,dy) in steps.iter() {
                let nx = x+*dx;
                let ny = y+*dy;
                if nx < 0 || nx > 2 || ny < 0 || ny > 2 {
                    continue;
                }
                if !state.is_visited(nx,ny) {
                    q.push((state.set_as_visited(nx,ny), step+1));
                }
            }
            for (dx,dy) in steps_line.iter() {
                let nx = x+*dx;
                let ny = y+*dy;
                if nx < 0 || nx > 2 || ny < 0 || ny > 2 {
                    continue;
                }
                let mx = x + *dx/2;
                let my = y + *dy/2;
                if !state.is_visited(nx,ny) && state.is_visited(mx,my) {
                    q.push((state.set_as_visited(nx,ny), step+1));
                }
            }
        }
        count
    }
}
```