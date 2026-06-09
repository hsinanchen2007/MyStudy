这道题如果是要打印具体的走法的话，很适合用回溯来做（虽然提名只要求算结果数），以下是一个回溯算法的思路，因为用到了递归所以性能很差，但是不失为一个思路

```rust
pub fn unique_paths(m: i32, n: i32) -> i32 {
    // using backtrack
    let l = (m+n-2) as usize;
    let mut steps: Vec<String> = vec![];
    backtrack(m, n, &mut steps, String::new(), l);
    // println!("{:?}", steps);
    return steps.len() as i32;
}

fn backtrack(m: i32, n: i32, steps: &mut Vec<String>, cur_steps: String, total_steps: usize) {
    // println!("backtrack: {}, {}, {:?}, {}", m, n, steps, cur_steps);
    if cur_steps.len() == total_steps {
        steps.push(cur_steps);
        return;
    }
    if m > 1 {
        let cur_steps = format!("{}d", cur_steps);
        backtrack(m-1, n, steps, cur_steps, total_steps);
    }
    if n > 1 {
        let cur_steps = format!("{}r", cur_steps);
        backtrack(m, n-1, steps, cur_steps, total_steps);
    }
}
```

把向右走定义为r,想下走定义为d，当走满了m+n-2步之后添加到结果集，否则继续往下走