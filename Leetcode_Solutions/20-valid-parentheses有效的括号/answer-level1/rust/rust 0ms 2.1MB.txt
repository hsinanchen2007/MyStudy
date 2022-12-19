```rust
    pub fn is_valid(s: String) -> bool {
		let s = s.as_bytes().iter();
		let mut stack = vec![];
		for &c in s {
			let c = c as char;
			if c == '(' || c == '{' || c == '[' {
				stack.push(c);
			} else if let Some(last) = stack.pop() {
				if (c == ')' && last == '(')
					|| (c == '}' && last == '{')
					|| (c == ']' && last == '[')
				{
					continue;
				} else {
					return false;
				}
			} else {
				return false;
			}
		}
		stack.len() == 0
	}
```