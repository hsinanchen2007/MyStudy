### 解题思路
此处撰写解题思路

### 代码

```rust
impl Solution {
    pub fn compress_string(s: String) -> String {        
        if let Some(mut ch) = s.chars().next(){
            let mut ans = String::from("");
            let mut cnt = 0;
            for ich in s.chars() {
                if ich == ch {
                    cnt+=1;
                }
                else {
                    ans.push(ch);
                    ans.push_str(&cnt.to_string());
                    cnt=1;
                    ch = ich;
                }
            }
            ans.push(ch);
            ans.push_str(&cnt.to_string());
            if ans.len() >= s.len() {
                return s; 
            }else{
                return ans;
            }
        }
        else{
            return s;
        }
        
    }
}

```