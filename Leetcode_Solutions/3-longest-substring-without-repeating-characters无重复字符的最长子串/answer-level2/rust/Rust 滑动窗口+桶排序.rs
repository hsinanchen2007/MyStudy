```
impl Solution {
    pub fn length_of_longest_substring(s: String) -> i32 {
        if(&s == ""){
            return 0 as i32;  
        }      
        let s = &s.trim();
        let (mut str_s, mut str_e, mut length, mut result) = (0, 0, 0, 0);
        let mut char_map: Vec<i32> = vec![-1;128];
        let str_len = s.len();
        if(str_len <= 1){
            return 1 as i32;  
        }            
        while(str_e < str_len){
            let mut cur_char = '0';
            // .chars将&str转化为Chars(chars的迭代器)
            for c in s[str_e..str_e+1].chars(){
                cur_char = c;
            }
            let cur_char_index = cur_char as usize - 0 as usize;
            // println!("The current char is {}, converted index is {}.", cur_char, cur_char_index);
            if(char_map[cur_char_index] >= str_s as i32){
                str_s = (char_map[cur_char_index]+1) as usize;
                length = (str_e - str_s) as i32;
            }
            char_map[cur_char_index] = str_e as i32;
            length += 1;
            str_e += 1;
            result = std::cmp::max(length, result);
            // println!("The str_e is {}, length is {}, result is {}.", str_e, length, result);
        }
        result
    }
}
```
![image.png](https://pic.leetcode-cn.com/c522ca39e5a3122bfdb19776972364f5621b1eeb6634293c5f4b0f323422253f-image.png)
