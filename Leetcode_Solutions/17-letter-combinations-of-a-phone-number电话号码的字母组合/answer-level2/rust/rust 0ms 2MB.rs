rust 写法简单飘逸,应该还有很大优化空间

```rust
impl Solution {
 	fn num_to_letter(number: u32) -> Vec<char> {
		match number {
			2 => vec!['a', 'b', 'c'],
			3 => vec!['d', 'e', 'f'],
			4 => vec!['g', 'h', 'i'],
			5 => vec!['j', 'k', 'l'],
			6 => vec!['m', 'n', 'o'],
			7 => vec!['p', 'q', 'r', 's'],
			8 => vec!['t', 'u', 'v'],
			9 => vec!['w', 'x', 'y', 'z'],
			_ => vec![],
		}
	}

	pub fn letter_combinations(digits: String) -> Vec<String> {
		let mut result: Vec<String> = vec![];
		let mut nums = digits.chars().map(|c: char| c.to_digit(10).unwrap());
		match nums.next() {
			Some(head) => {
				for c in Self::num_to_letter(head) {
					let mut s = String::new();
					s.push(c);
					result.push(s);
				}
			}
			None => return result,
		}

		while let Some(num) = nums.next() {
			let mut new_result = vec![];
			for value in result.iter() {
				for c in Self::num_to_letter(num) {
					let mut clone = value.clone();
					clone.push(c);
					new_result.push(clone);
				}
			}
			result = new_result;
		}
		result
	}
}
```