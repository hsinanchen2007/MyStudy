use std::cmp::min;
fn two_common(str1: &String, str2: &String ) -> String {
        let len = min(str1.len(), str2.len());
        if len == 0 {return "".to_string();}
        for i in 0..len {
            if str1[i..i+1] != str2[i..i+1] {
                return str1[0..i].to_string();
            }
        }
        str1[..len].to_string()
    }
impl Solution {
    pub fn longest_common_prefix(strs: Vec<String>) -> String {
        let len = strs.len();
        if len == 0 {return "".to_string();}
        let mut tmp = strs[0].clone();
        for x in strs.iter() {
            tmp = two_common(&tmp, x);
        }
        tmp
    }    
}