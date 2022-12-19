### 解题思路
此处撰写解题思路

### 代码

```rust
impl Solution {
    pub fn dfs(&self,ans:&mut Vec<String>,cur:&mut String, open:i32,close:i32,n:i32){
        if cur.len()==2*n as usize {
            ans.push(cur.clone());
            return;
        }
        if open<n{
            cur.push('(');
            Self.dfs(ans,cur,open+1,close,n);
            cur.pop();
        }
        if close<open{
            cur.push(')');
            Self.dfs(ans,cur,open,close+1,n);
            cur.pop();
        }
    }
    pub fn generate_parenthesis(n: i32) -> Vec<String> {
        let mut ans:Vec<String> = Vec::new();
        let mut cur:String=String::from("");
        Self.dfs(&mut ans,&mut cur,0,0,n);
        ans
    }
}


```