思路很简单：
1. 用 `HashMap` 存储 `域名->数量` 对；
2. 对于每个输入的字符串，分割并解析其中的数量和域名，添加到哈希表里；
3. 遍历输出哈希表即可。

优化思路：
1. 一般分割字符串，都会用 `split(/* pattern */).collect::<Vec<_>>()` 把结果存为 `Vec<&str>`，但这里的字符串非常简单，完全可以用 `find(/* pattern */)` 找到对应的位置再手动分割，这样就不需要给 `Split` 和 `Vec` 分配内存了。
2. `HashMap` 的 key 应该用 `&str` 而非 `String`，减少不必要的内存分配。

代码：
```Rust
use std::collections::HashMap;

pub fn subdomain_visits(cpdomains: Vec<String>) -> Vec<String> {
    let mut domain_counts = HashMap::new(); // HashMap<&str, usize>
    for cpdomain in &cpdomains {
        // 使用 find + slice 取代 split
        let space_idx = cpdomain.find(' ').unwrap();
        let count = &cpdomain[..space_idx].parse::<usize>().unwrap();
        let mut domain = &cpdomain[space_idx + 1..];

        // 每次把 domain 和对应的数量添加到 domain_counts 之后，
        // 都需要让 domain 指向下一个域名，即最左边的 '.' 后面的字符串；
        // 如果没有找到 '.'，就将 domain 置为空字符串，以结束循环。
        while !domain.is_empty() {
            *domain_counts.entry(domain).or_insert(0) += count;
            domain = domain.find('.').map_or("", |idx| &domain[idx + 1..]);
        }
    }

    domain_counts
        .into_iter()
        .map(|(domain, count)| format!("{} {}", count, domain))
        .collect()
}
```