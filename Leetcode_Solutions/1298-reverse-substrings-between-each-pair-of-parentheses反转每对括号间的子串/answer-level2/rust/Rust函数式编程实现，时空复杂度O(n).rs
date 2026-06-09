```rust
use std::collections::VecDeque;

enum StackElement{
    Char(char),
    Deque(VecDeque<char>)
}
impl Solution {
    pub fn reverse_parentheses(s: String) -> String {
        let mut  stack = VecDeque::new();
        s 
        .chars()
        .fold(false, |acc,cur|match cur{
            ')' =>  {
                let mut  d = VecDeque::new();
                loop{ 
                    match stack.pop_back().unwrap(){
                        StackElement::Char('(')=>{
                            if d.len()>0 {stack.push_back(StackElement::Deque(d))}

                            break;
                        },
                        StackElement::Deque(v)=>{
                            if !acc { v.iter().rev().for_each(|e|d.push_front(*e))}
                            else {  d.append(&mut v.clone()); }
                        },
                        StackElement::Char(e)=>{
                            if !acc {d.push_front(e); }
                            else{d.push_back(e); }
                        }
                    };
                }
                !acc
            },
            _ =>{
                stack.push_back(StackElement::Char(cur)); 
                match cur{ '('=>!acc, _=>acc   }
            },
        });

        stack.iter()
                .fold(String::from(""),|acc,cur|{
                    match cur{
                        StackElement::Deque(d)=> [acc,d.iter().collect::<String>()].concat() ,
                        StackElement::Char(e)=> [acc,e.to_string()].concat() ,
                    }
                })

    }
}
```