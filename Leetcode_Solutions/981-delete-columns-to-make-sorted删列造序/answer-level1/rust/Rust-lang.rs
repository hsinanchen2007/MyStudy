### 运行结果

![image.png](https://pic.leetcode-cn.com/e71b47c1333a38e219533706f131d035490b83d772276e3362cc4cc7d18d3b21-image.png)

### 代码

```rust
impl Solution {
    pub fn min_deletion_size(a: Vec<String>) -> i32 {
        let str_len = a[0].len();
        let arr_len = a.len();
        let mut count = 0i32;
        let mut str_arr = vec![];

        for item in a { // Rust的String与C/C++等语言不同，需要先转为bytes或者chars
            let tmp = item.bytes().collect::<Vec<_>>(); // 这里使用item.bytes()效率比item.chars()高
            str_arr.push(tmp);
        }

        for i in 0..str_len {
            for j in 1..arr_len {
                // if a[j as usize].chars().nth(i).unwrap() < a[j as usize - 1].chars().nth(i).unwrap() { // 这种方式访问效率太低了，平均下来800ms，故不采用
                //     count += 1;
                //     break;
                // }

                if str_arr[j as usize][i] < str_arr[j as usize - 1][i] { // 效率较前者高了200倍
                    count += 1;
                    break;
                }
            }
        }

        (count)
    }
}
```

### 算法复杂度

**空间复杂度：O(n*length)**

**时间复杂度：O(n*length)**
(length为单个字符串长度)