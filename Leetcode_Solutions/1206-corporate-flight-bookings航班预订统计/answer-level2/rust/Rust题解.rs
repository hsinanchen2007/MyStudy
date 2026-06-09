前缀和一把过
这题不应该有中等难度吧
```
impl Solution {
    pub fn corp_flight_bookings(bookings: Vec<Vec<i32>>, n: i32) -> Vec<i32> {
        let (mut v, mut res, mut sum) = (vec![0; n as usize + 2], vec![], 0);
        for i in &bookings {
            v[(*i)[0] as usize] += (*i)[2];
            v[(*i)[1] as usize + 1] -= (*i)[2];
        }
        for i in 1 .. n + 1 {
            sum += v[i as usize];
            res.push(sum);
        }
        res
    }
}
```
