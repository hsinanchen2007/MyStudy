我实在强迫症，很喜欢用 unsafe，看看就好。
```rust
const LETTERS: [&[u8]; 8] = [b"abc", b"def", b"ghi", b"jkl", b"mno", b"pqrs", b"tuv", b"wxyz"];
pub fn letter_combinations(digits: String) -> Vec<String> {
    let len = digits.len();
    if len == 0 { return Vec::new(); }
    let mut res = Vec::with_capacity(3usize.pow(len as u32));
    let mut buf = Vec::with_capacity(len);
    unsafe { buf.set_len(len); }
    recursive_push(&mut buf, &mut res, 0, digits.as_bytes());
    res
}
fn recursive_push(buf: &mut Vec<u8>, res: &mut Vec<String>, i: usize, digits: &[u8]) {
    for &b in LETTERS[(digits[i] - b'2') as usize] {
        buf[i] = b;
        if i == buf.len() - 1 {
            res.push(unsafe { String::from_utf8_unchecked(buf.clone()) })
        } else {
            recursive_push(buf, res, i + 1, digits)
        }
    }
}
```
