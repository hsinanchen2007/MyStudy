最优：两个指针利用输入是顺序数组的条件，前后夹逼
```
impl Solution {
    pub fn two_sum(numbers: Vec<i32>, target: i32) -> Vec<i32> {
        let len = numbers.len();
        let mut res = Vec::with_capacity(2);
        let (mut i, mut j) = (0, len-1);
        loop {
            let temp = numbers[i] + numbers[j];
            if target == temp {
                break;
            } else if target < temp {
                j -= 1;
            } else {
                i += 1;
            }
        }
        res.push((i+1) as i32);
        res.push((j+1) as i32);
        res
    }
}
```
另一个暴力但是也能过的实现
```
impl Solution {
    pub fn two_sum(numbers: Vec<i32>, target: i32) -> Vec<i32> {
        let len = numbers.len();
        let mut res = Vec::with_capacity(2);
        for i in 0..len {
            for j in i+1..len {
                let temp = numbers[i]+numbers[j];
                if temp == target {
                    res.push((i+1) as i32);
                    res.push((j+1) as i32);
                } else if temp > target {
                    break;
                }
            }
        }
        res
    }
}
```