```rust
impl Solution {
    pub fn find_min_difference(time_points: Vec<String>) -> i32 {
        let mut min=time_points.iter().map(|e|e.split(':').zip(vec![60,1].iter())
            .fold(0,|a,c|a+(c.0.parse::<i32>().unwrap()*c.1))).collect::<Vec<_>>();
        min.sort();
        min.push(min[0]+1440);
        min.iter().take(min.len()-1).zip(min.iter().skip(1)).map(|e|e.1-e.0).fold(i32::max_value(),|a,c| if c < a{c} else {a})
    }
}
```