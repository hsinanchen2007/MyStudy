python直接闭包递归，迭代也成。

```python []
class Solution:
    def generateParenthesis(self, n: int) -> List[str]:
        ans = []
        def f(l, r, s):
            l == r == n and ans.append(s)
            l < n and f(l + 1, r, s + '(')
            r < l and f(l, r + 1, s + ')')
        f(0, 0, '')
        return ans
```
```python []
class Solution:
    def generateParenthesis(self, n: int) -> List[str]:
        ans = []
        stack = [(0, 0, '')]
        while stack:
            l, r, s = stack.pop()
            l == r == n and ans.append(s)
            r < l and stack.append((l, r + 1, s + ')'))
            l < n and stack.append((l + 1, r, s + '('))
        return ans
```

```python []
class Solution:
    def generateParenthesis(self, n: int) -> List[str]:
        ans, s = [], []
        def f(l, r):
            l == r == n and ans.append(''.join(s))
            if l < n:
                s.append('(')
                f(l + 1, r)
                del s[-1]
            if r < l:
                s.append(')')
                f(l, r + 1)
                del s[-1]
        f(0, 0)
        return ans
```


rust不能闭包递归，好坑。

```rust []
impl Solution {
    pub fn generate_parenthesis(n: i32) -> Vec<String> {
        let mut ans = Vec::new();
        f(0, 0, String::new(), n, &mut ans);
        ans
    }
}
fn f(l: i32, r: i32, mut s: String,  n: i32, ans: &mut Vec<String>) {
    if l == n && r == n {
        ans.push(s.to_string());
    }
    if l < n {
        f(l + 1, r, s.to_owned() + "(", n, ans);
    }
    if r < l {
        f(l, r + 1, s + ")", n, ans);
    }
}
```
```rust []
impl Solution {
    pub fn generate_parenthesis(n: i32) -> Vec<String> {
        let (mut ans, mut stack) = (Vec::new(), vec![(0, 0, String::new())]);
        while let Some((l, r, mut s)) = stack.pop() {
            if l == n && r == n {
                ans.push(s.to_string());
            }
            if r < l {
                stack.push((l, r + 1, s.to_owned() + ")"));
            }
            if l < n {
                stack.push((l + 1, r, s + "("));
            }
        }
        ans
    }
}
```
