## unsafe 来提速单个字符串反转
因为输入都是小写英文字母字符串，其编码都是 ASCII码，因此可以直接使用 `str::as_bytes_mut` 来获得 `&mut [u8]`, 然后使用 `slice::reverse` 来快速反转字符串：

```
words.iter_mut()
    .for_each(|word| {
    // use `unsafe` to fasten the reversing operation.
    // the words contain only English letters which are encoded in ASCII
    unsafe {
        word.as_bytes_mut().reverse();
    }
});
```

## 迭代器 `.windows(n)`
利用 迭代器 获取相邻两个`word`, 注意因为我们都是处理 `pre` 字符串，所以最后还需要加上最后一个 word 的长度：

```
let length = words.windows(2)
    .fold(0, |mut length, win| {
        let (pre, word) = (&win[0], &win[1]);
        if !word.starts_with(pre) {
            length += pre.len() as i32 + 1;
        }

        length
    });

length + words[words.len() - 1].len() as i32 + 1
```