```
impl Solution {
    pub fn longest_common_prefix(strs: Vec<String>) -> String {
       
         let mut chr;   

         let tmp_str;
         
         let mut res = String::new();
        // println!("str is {:?}",tmp_str);
         if strs.len() == 0{
          // res.push("");
           return res;
        }else{
                tmp_str = strs[0].clone();
                'a: for i in 0 .. tmp_str.len(){
                        chr = tmp_str.chars().nth(i).unwrap();
                    'b: for j in 1 .. strs.len(){
                            if strs[j].len() > i {
                                if strs[j].chars().nth(i).unwrap() != chr{
                                    break 'a; 
                                }
                              
                        }else{
                            break 'a;
                        }
               
            }
            res.push(chr);
          }
      }
      res        
    }
}
```
