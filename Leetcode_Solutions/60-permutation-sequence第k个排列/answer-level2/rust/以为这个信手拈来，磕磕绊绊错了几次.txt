```
impl Solution {
    fn n_factorial(n: usize) -> usize {
       (1..(n + 1)).fold(1, |acc, x| acc * x)
   }
   fn recur(order: &mut Vec<usize>, k: usize, ans: &mut Vec<usize>) {
       let choose = Self::n_factorial(order.len() - 1);
       let mut n = k / choose;
       let m = k % choose;
       if m != 0 {
           n += 1;
       }
       ans.push(order.remove(n - 1));
       if m == 0 {
           order.reverse();
           ans.extend_from_slice(&order[..]);
       } else {
           Self::recur(order, m, ans);
       }
   }
   fn tostr(order: &Vec<usize>) -> String {
        return unsafe {
            String::from_utf8_unchecked(order.iter().map(|&x| x as u8 + b'0').collect())
        };
   }
    pub fn get_permutation(n: i32, k: i32) -> String {
        let n = n as usize;
        let k = k as usize;
        let mut order: Vec<usize> = (1..(n + 1)).collect();
        let mut ans: Vec<usize> = vec![];
        Self::recur(&mut order, k, &mut ans);
        Self::tostr(& ans)
    }
}
```
