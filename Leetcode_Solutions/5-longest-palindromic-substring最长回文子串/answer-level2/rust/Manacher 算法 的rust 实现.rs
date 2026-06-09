```
impl Solution {
    pub fn longest_palindrome(s: String) -> String {
        let mut max_sub_str = "".to_string();
		if s.len() < 1 {
			return max_sub_str;
		}
		let mut str_ary = vec!['#'];
		for c in s.chars(){
			str_ary.push(c);
			str_ary.push('#');
		}
		let str_ary_len = str_ary.len() as i32;
		let mut radius = vec![0;str_ary_len as usize];
		let (mut r, mut c , mut max) = (-1, -1, 0);
		for i in 0..str_ary_len {
			let mut k = if r > i {
				radius[ (2 * c - i) as usize].min(r - i + 1)
			}else{
				1
			};
			while i + k < str_ary_len && i - k > -1  && str_ary[(i - k) as usize] == str_ary[(i + k) as usize]{
				k += 1;
			}
			if i + k > r {
				r = i + k - 1;
				c = i;
			}
			max = max.max(k);
			radius[i as usize] = k;
		}
		for (key, &val) in radius.iter().enumerate() {
			if val == max {
				max_sub_str = str_ary[key-(max as usize -1)..key+max as usize].iter()
									.filter(|&x| *x != '#').collect::<String>();
			}
		}
		max_sub_str
    }
}
```
