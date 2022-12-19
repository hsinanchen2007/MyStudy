类型转换和unsafe，一言难尽
```
impl Solution {
    pub fn convert_to_title(n: i32) -> String {
        let mut n = n;
        let mut ans = String::new();
        while((n-1)/26!=0){
            let tmp = (n-1)%26;
            n = (n-1)/26;
            ans.push(('A' as i32 + tmp) as u8 as char);
        }    
        let tmp = (n-1)%26;
        ans.push(('A' as i32 + tmp) as u8 as char);
        /* 
        unsafe{
            ans.as_mut_vec().reverse();
        }
        ans
        */
        ans.chars().rev().collect()
    }
}
```