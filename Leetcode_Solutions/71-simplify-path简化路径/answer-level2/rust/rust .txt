```rust
impl Solution {
    pub fn simplify_path(path: String) -> String {
		let mut stack: Vec<String> = vec![];
		let paths = path.split("/");
		for path in paths {
			if path == "" {
				continue;
			} else if path == "." {
				continue;
			} else if path == ".." {
				stack.pop();
			} else {
				stack.push(path.to_owned());
			}
		}
		let mut result = String::from("/");
		result.push_str(&stack.join("/"));
		result
	}
}
```