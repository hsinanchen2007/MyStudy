### 解题思路
此处撰写解题思路

### 代码

```rust
impl Solution {
    pub fn my_atoi(str: String) -> i32 {
        //0:start 1:signed 2:in_number 3:end
        let stateTable=vec![
            vec![0,1,2,3],
            vec![3,3,2,3],
            vec![3,3,2,3],
            vec![3,3,3,3]
        ];
        //
        let mut sign = 1;
        let mut ans = 0;
        let mut state = 0;
        for c in str.chars(){
            let nextState = match c{
                ' '     => 0,
                '+'|'-' => 1,
                _       =>{
                            if c.is_digit(10){
                                2
                            }else{
                                3
                            }
                        }
            };
            state = stateTable[state][nextState];
            //
            if state == 2{
                let i32c = c as i32 - '0' as i32;
                if sign==1 && ans > (i32::max_value()-i32c)/10 {
                    ans = i32::max_value();
                }else if sign==-1 && ans < (i32::min_value()-sign*i32c)/10 {
                    ans = i32::min_value();
                }else{
                    ans = ans * 10 + sign*i32c; 
                }
            } else if state == 1{
                if c=='+' {
                    sign = 1;
                } else{
                    sign = -1;
                }
            } else if state == 3{
                break;
            }
        }
        ans
    }
}


```