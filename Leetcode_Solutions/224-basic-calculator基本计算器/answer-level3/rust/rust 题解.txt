impl Solution {
    pub fn calculate(s: String) -> i32 {
        let mut operands = Vec::new();
        let mut operator = Vec::new();
        let mut ans = 0;
        let chars:Vec<char> = s.chars().collect();
        let mut index = 0;
        loop{
            if index >= chars.len(){
                break
            }
            let c = chars[index].clone();
            match chars[index]{
                '+' => {
                    operator.push(c);
                    index += 1;
                }
                '-' => {
                    operator.push(c);
                    index += 1;
                }
                '(' => {
                    operator.push(c);
                    index += 1;
                }
                ')' => {
                    for _ in 0..2 {
                        if let Some(op) = operator.pop() {
                            match op {
                                '(' => continue,
                                '+' => {
                                    let a = operands.pop().unwrap();
                                    let b = operands.pop().unwrap();
                                    operands.push(a + b);
                                    break
                                }
                                '-' => {
                                    let a = operands.pop().unwrap();
                                    let b = operands.pop().unwrap();
                                    operands.push(b - a);
                                    break
                                }
                                _ => panic!()
                            }
                        }
                    }
                    index += 1;
                }
                ' ' => {
                    index += 1;
                }
                digit=> {
                    let mut pos = index + 1;
                    loop{
                        if pos >= chars.len() {
                            break
                        }
                        if chars[pos].is_digit(10){
                            pos += 1
                        }else{
                            break
                        }
                    }
                    let mut num = 0;
                    for v in &chars[index..pos]{
                        num *= 10;
                        num += v.clone().to_digit(10).unwrap();
                    }
                    let mut num = num as i32;
                    match operator.pop(){
                        Some(op) => {
                            match op{
                                '+' => {
                                    let x = operands.pop().unwrap();
                                    num = x + num;
                                }
                                '-' => {
                                    let x = operands.pop().unwrap();
                                    num = x - num;
                                }
                                x => {

                                    operator.push(x);
                                }
                            }
                            operands.push(num);
                        }
                        None => {
                            operands.push(num as i32);
                        }
                    }
                    index = pos
                }
            }
        }
        operands[0]
    }
}