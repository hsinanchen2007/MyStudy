### 解题思路
此处撰写解题思路

### 代码

```rust
impl Solution {
    pub fn gcd(a: usize,b: usize) -> usize {
        if a % b==0 {
            return b;
        }else{
            return Solution::gcd(b,a % b);
        }
    }
    pub fn gcd_of_strings(str1: String, str2: String) -> String {
        let mut s1 = str1.clone();
        s1.push_str(&str2);
        let mut s2 = str2.clone();
        s2.push_str(&str1);
       
        if s1 != s2 {
            return String::from("");
        }
       
        let ls1 = str1.len() as usize;
        let ls2 = str2.len() as usize;
        let n = Solution::gcd(ls1,ls2);
        
        s1.truncate(n);
        s1
    }
}

 //if (str1 + str2 != str2 + str1) return "";
   //     return str1.substr(0, __gcd((int)str1.length(), (int)str2.length()));

```