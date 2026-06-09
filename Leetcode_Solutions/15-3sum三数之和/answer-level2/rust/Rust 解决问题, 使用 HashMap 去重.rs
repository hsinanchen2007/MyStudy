// 首先简单(用能想到的最直接的方法, 不考虑性能)的方法正确地得到答案:

// ```rust
fn three_sum(nums: Vec<i32>) -> Vec<Vec<i32>> {
    // 不够三个数, 直接返回空数组
    if nums.len() < 3 {
        return vec![];
    }
    
    // 找不到头绪, 先排个序吧
    let mut nums = nums.clone();
    nums.sort();
    
    // 题目最后特别强调不能由重复的答案, 那就用 HashSet 来装它们
    let mut result = std::collections::HashSet::new();
    
    // 遍历, 先选定三数中的第一个数的坐标 a
    let mut a = 0;
    loop {
        // a 最多只能是整个数组里的倒数第三个数
        if a == nums.len()-2 {
            break;
        }
        // 三数中的第二个数的坐标 b, 从 a 后面开始
        let mut b = a + 1;
        loop {
            // b 最多是倒数第二数
            if b == nums.len()-1 {
                break;
            }
            // c 从 b 后面开始
            let mut c = b + 1;
            loop {
                // c 最多到倒数第一
                if c == nums.len() {
                    break;
                }
                // 如果三数相加得到 0, 就把 它们加到结果里. 注意 a, b, c 只是坐标
                if nums[a] + nums[b] + nums[c] == 0 {
                    let t = vec![nums[a], nums[b], nums[c]];
                    result.insert(t);
                }
                c += 1;
            }
            b += 1;
        }
        a += 1;
    }
    // 从 HashSet 转成 Vec, 满足题目
    result.into_iter().collect::<Vec<_>>()
}

// ```

// 我从官方最长的测试用例里面截取了一段(因为实在太长了), 跑出来的结果是 237ms.

// 现在我们看看能做哪些优化, 先从三数的取值范围开始吧. 于是我们有了第二版, 只是在
// 三次遍历的 break 条件上添加了一些.

// ```rust
fn three_sum(nums: Vec<i32>) -> Vec<Vec<i32>> {
    // 不够三个数, 直接返回空数组
    if nums.len() < 3 {
        return vec![];
    }
    
    // 找不到头绪, 先排个序吧
    let mut nums = nums.clone();
    nums.sort();
    
    // 题目最后特别强调不能由重复的答案, 那就用 HashSet 来装它们
    let mut result = std::collections::HashSet::new();
    
    // 遍历, 先选定三数中的第一个数的坐标 a
    let mut a = 0;
    loop {
        // a 最多只能是整个数组里的倒数第三个数. 
        // 要满足 nums[a]+nums[b]+nums[c]==0 的话, nums[a] 一定小于等于 0
        if a == nums.len()-2 || !(nums[a] <= 0) {
            break;
        }
        // 三数中的第二个数的坐标 b, 从 a 后面开始
        let mut b = a + 1;
        loop {
            // b 最多是倒数第二数
            // 要满足 nums[a]+nums[b]+nums[c]==0 的话,
            // nums[a]+nums[b] 一定小于等于 0
            if b == nums.len()-1 || !((nums[a] + nums[b]) <= 0) {
                break;
            }
            // c 从 b 后面开始
            let mut c = b + 1;
            loop {
                // c 最多到倒数第一
                // 要满足 nums[a]+nums[b]+nums[c]==0 的话, nums[c] 一定大于等于 0
                if c == nums.len() || !(nums[c] >= 0) {
                    break;
                }
                // 如果三数相加得到 0, 就把 它们加到结果里
                if nums[a] + nums[b] + nums[c] == 0 {
                    let t = vec![nums[a], nums[b], nums[c]];
                    result.insert(t);
                }
                c += 1;
            }
            b += 1;
        }
        a += 1;
    }
    // 从 HashSet 转成 Vec, 满足题目
    result.into_iter().collect::<Vec<_>>()
}
// ```

// 这样, 只是修改了取值范围, 我们的程序执行时间就减少到了 50ms.

// 让我们想想还能怎么优化. 对于第三个数, 前两个数确定的话, 第三个数也就唯一确定
// 了, 所以可以在找到第三个数之后就 break.

// ```rust
...
                // 如果三数相加得到 0, 就把 它们加到结果里
                if nums[a] + nums[b] + nums[c] == 0 {
                    let t = vec![nums[a], nums[b], nums[c]];
                    result.insert(t);
                    break;
                }
...
// ```

// 这一改动减少了 4ms.

// 又想到, 我们前两个数是从左往右遍历, 那么第三个数从右往左遍历, 会不会更容易匹配
// 到呢, 试着改动一下第三个数的遍历方向:

// ```rust
            // c 从最后开始, 一直到 b + 1
            let mut c = nums.len()-1;
            loop {
                // c 最多到 b 右边
                if c == b || !(nums[c] >= 0) {
                    break;
                }
                // 如果三数相加得到 0, 就把 它们加到结果里
                if nums[a] + nums[b] + nums[c] == 0 {
                    let t = vec![nums[a], nums[b], nums[c]];
                    result.insert(t);
                    break;
                }
                // 从右往左
                c -= 1;
            }
// ```

// 结果出人意料, 时间增加到了 100ms. 看来这个方法没用, 我们改回去.

// 我们现在最耗时间的应该就是找到第三个数的过程了, 事实上, 对于任意的前两个数, 我们
// 都能确定第三个数, 不确定的只是这第三个数在不在集合里面. 判断一个数在不在一个集合
// 里面, 就是典型的查询问题. 

// 翻出 https://doc.rust-lang.org/std/collections/index.html , 即 Rust 文
// 档里对于不同集合类型的性能比较, 我们看到 HashMap 有着媲美 Vec 的查询性能, 而且
// HashMap 可以使用任意的值作为 key.(Vec只能用从0递增的 usize 作为key). 

// 结果很让人惊喜, 只花了 9.6ms.

// 最终完整代码:

// ```rust
fn three_sum(nums: Vec<i32>) -> Vec<Vec<i32>> {
    // 不够三个数, 直接返回空数组
    if nums.len() < 3 {
        return vec![];
    }
    
    // 找不到头绪, 先排个序吧
    let mut nums = nums.clone();
    nums.sort();
    
    let mut thirds = std::collections::HashMap::new();
    {
        let mut c = nums.len()-1;
        loop {
            // 注意这里我们要一直获取到 0 位置的值, 但 usize 是没有负数的
            if c == usize::max_value() || !(nums[c] >= 0) {
                break;
            }
            let entry = thirds.entry(nums[c]).or_insert(0);
            *entry += 1;
            c -= 1;
        }
    }
    
    // 题目最后特别强调不能由重复的答案, 那就用 HashSet 来装它们
    let mut result = std::collections::HashSet::new();
    
    // 遍历, 先选定三数中的第一个数的坐标 a
    let mut a = 0;
    loop {
        // a 最多只能是整个数组里的倒数第三个数
        if a == nums.len()-2 || !(nums[a] <= 0) {
            break;
        }
        // 三数中的第二个数的坐标 b, 从 a 后面开始
        let mut b = a + 1;
        loop {
            // b 最多是倒数第二数
            if b == nums.len()-1 || !((nums[a] + nums[b]) <= 0) {
                break;
            }
            // 看看能和前两个数配对的第三个数, 在不在集合里面
            let third = -(nums[a] + nums[b]);
            match thirds.get(&third) {
                // 每个数出现的次数不能超过其在集合里面总数
                Some(&n) => {
                    let mut t = vec![nums[a], nums[b], third];
                    t.sort();
                    if t.clone().into_iter().filter(|&x| x == third).count() <= n {
                        result.insert(t);
                    }
                },
                None => (),
            }
            b += 1;
        }
        a += 1;
    }
    // 从 HashSet 转成 Vec, 满足题目
    result.into_iter().collect::<Vec<_>>()
}
// ```

// 最终提交后, 跑完全部测试用例用时 534ms. 还是比较慢的.

// # （看了大神的提交之后找到的）终极优化方案， 采用双指针查找第二和第三数， 顺便去重

// ```rust

fn three_sum(nums: Vec<i32>) -> Vec<Vec<i32>> {
    // 不够三个数, 直接返回空数组
    if nums.len() < 3 {
        return vec![];
    }
    
    // 找不到头绪, 先排个序吧
    let mut nums = nums.clone();
    nums.sort();
    
    let mut result = vec![];
    
    // 遍历, 先选定三数中的第一个数的坐标 a
    let mut a = 0;
    loop {
        // a 最多只能是整个数组里的倒数第三个数
        if a == nums.len()-2 || !(nums[a] <= 0) {
            break;
        }
        if a > 0 && nums[a] == nums[a-1] {
            //重复的数字， 继续
            a += 1;
            continue;
        }
        // 双指针对撞， 回到两数之和的问题
        let mut b = a + 1;
        let mut c = nums.len()-1;
        loop {
            if b >= c {
                // 相撞，找不到能和a组合的b，c， 结束循环
                break;
            }
            let sum = nums[a] + nums[b] + nums[c];
            if sum == 0 {
                // 找到了, 加到结果里
                result.push(vec![nums[a], nums[b], nums[c]]);
                // 跳过重复的结果
                while b < c && nums[b] == nums[b+1] {
                    b += 1;
                }
                while b < c && nums[c] == nums[c-1] {
                    c -= 1;
                } 
                // 寻找别的组合
                b += 1;
                c -= 1;
                continue;
            } else if sum < 0 {
                // 太小了, b 👉 移动
                b += 1;
                continue;
            } else {
                // 太大， c 👈 移动
                c -= 1;
                continue;
            }
        }
        a += 1;
    }
    result
}
// ```

// 这个方案跑完全部测试用例只需要 24ms 。