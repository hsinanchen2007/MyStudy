```
impl Solution {
    pub fn large_group_positions(s: String) -> Vec<Vec<i32>> {
        let mut res: Vec<Vec<i32>> = Vec::new();
        let s:Vec<char> = s.chars().collect(); // 先转换成字符数组方便处理
        println!("{:?}", s);
        
        let mut min = 0; // 从第0个开始
        let mut max;
        for i in 1..s.len()+1 { // 注意右边界 len+1，最后保证几个满足条件的情况，比如 "xxaaaa"
            if i == len || s[i] != s[i-1] {
                max = (i-1) as i32;
                if max - min >= 2 {
                    res.push(vec![min,max]);
                }
                min = max + 1;
            }
        }
        res
    }
}
```
