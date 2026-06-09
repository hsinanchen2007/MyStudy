# Rust
## 思路
有限状态机
考虑一个最平凡的例子:`"-123.456e-789"`
将其中可能包含的符号分为:
- 正负号:op
- 数字:dig
- 指数符号:exp
- 小数点:dot
- 其他字符:other

其中要注意一下几个有点坑的判例:
|判例|合法|
|:----:|:--:|
|"."|×|
|"1."|√|
|".1"|√|
|"+.1"|√|
`"1."`这样的判例居然合法, 我也是很震惊, 这就要求我们把前面没有数字的小数点单独提出来作为一个状态(也就是下图状态9)

![isnum_DFA.jpg](https://pic.leetcode-cn.com/24be1f8ddd46d4d5bed0a3911ff305baa8636da1cbde15a800008156c700c689-isnum_DFA.jpg)

其中, 2, 3, 4, 7, 是可以接受的状态
实际代码中, 由于读取到Other就会转移到状态8:Fail, 之后不可能转移出去了, 我们人为的在match到Other的时候, 用break跳出循环, 直接判定不匹配.
## Code
``` rust
const TRANS_TABLE: [[usize;5];10] = [
    //[Op, Dig, Dot, Exp, Other]
    [1, 2, 9, 8, 8],//0
    [8, 2, 9, 8, 8],//1
    [8, 2, 3, 5, 8],//2:A
    [8, 4, 8, 5, 8],//3:A
    [8, 4, 8, 5, 8],//4:A
    [6, 7, 8, 8, 8],//5
    [8, 7, 8, 8, 8],//6
    [8, 7, 8, 8, 8],//7:A
    [8, 8, 8, 8, 8],//8
    [8, 4, 8, 8, 8],//9
];
const ACCEPT_STATE:[bool;10] = [false, false, true, true, true, false, false, true, false, false];
enum Code {
    Op = 0,
    Dig = 1,
    Dot = 2,
    Exp = 3,
    Other = 4,
}
impl Solution {
    pub fn is_number(s: String) -> bool {      
        let mut code = Code::Other;
        let mut state:usize = 0;
        let mut chars = s.trim().chars();
        loop {
            match chars.next() {
                Some('+')|Some('-') => { code = Code::Op; },
                Some('.') => { code = Code::Dot; },
                Some('e') => { code = Code::Exp; },
                Some(d) if d.is_digit(10) => { code = Code::Dig; },
                None => { break; },
                _ => { state = 8; break; },
            }
            state = TRANS_TABLE[state][code as usize];
        }
        ACCEPT_STATE[state]
    }
}
```

# JavaScrip
## 思路
反正写js, 我写的快就行了, 管它跑起来怎么样, 用正则表达式就行
## code
```javascript
const re = /^[\u002b|\u002d]?(\d*[\u002e]\d+|\d+|\d+[\u002e]\d*)(e[\u002b|\u002d]?\d+)?$/
var isNumber = function(s) {
    return re.test(s.trim())
};
```
