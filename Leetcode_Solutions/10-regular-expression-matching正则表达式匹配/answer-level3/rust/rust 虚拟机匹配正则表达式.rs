别问, 问就是魔法
参考了别人写的代码
```rust
use std::collections::HashMap;
use std::str::Chars;
#[derive(Debug,PartialEq)]
enum AstNode {
    Cons(Box<AstNode>,Box<AstNode>),
    Char(char),
    ZeroOrMany(Box<AstNode>),
    Any,
}

#[derive(Debug,Copy,Clone)]
enum Op {
    Char(char),
    Splt(usize,usize),
    Jmp(usize),
    Label(usize),
    Match,
    Any,
}

#[derive(Debug,Copy,Clone)]
struct MatchThread {
    ip:usize,
    pos:usize,
}

fn compile(ast:Box<AstNode>, idx:&mut usize)->Vec<Op>{
    let mut r:Vec<Op> = Vec::new();
    match *ast {
        AstNode::Cons(a,b) => {
            let mut v = compile(a,idx);
            r.append(&mut v);
            let mut v = compile(b,idx);
            r.append(&mut v);
        },
        AstNode::ZeroOrMany(a) => {
            let n = *idx;
            r.push(Op::Label(n));
            r.push(Op::Splt(n+2, n+1));
            r.push(Op::Label(n+1));
            *idx+=3;
            let mut v=compile(a,idx);
            r.append(&mut v);
            r.push(Op::Jmp(n));
            r.push(Op::Label(n+2));
        },
        AstNode::Char(a) => {
            r.push(Op::Char(a));
        },
        AstNode::Any => {
            r.push(Op::Any);
        },
    }
    return r;
}

impl Solution {
    pub fn is_match(s: String, p: String) -> bool {
        if p == "" { return if s == "" {true} else {false} };
        let mut chars = p.chars();
        let mut stack:Vec<Box<AstNode>> = Vec::new();
        loop {
            match chars.next() {
                Some('.') => { stack.push(Box::new(AstNode::Any)) },
                Some('*') => { 
                    let ast_node = stack.pop().unwrap();
                    stack.push(Box::new(AstNode::ZeroOrMany(ast_node)));
                },
                Some(c) => { stack.push(Box::new(AstNode::Char(c))) },
                None => break,
            }
        }
        let mut r:Box<AstNode> = stack.remove(0);
        let mut stack1:Vec<Box<AstNode>> = Vec::new();
        loop{
            if stack.len() == 0 {break;}
            let tmp:Box<AstNode> = stack.remove(0);
            r = Box::new(AstNode::Cons(r,tmp));
        }
        let ast_root = r;
        
        // 编译
        let mut idx:usize= 0;
        let mut ops = compile(ast_root,&mut idx);

        // 这里我们删除所有的 label
        let mut hm:HashMap<&usize,usize> = HashMap::new();
        let mut i:usize = 0;
        let mut r:Vec<Op> = Vec::new();
        for item in ops.iter() {
            match item {
                Op::Label(l) => {
                    hm.insert(l, i);
                },
                _=>{i+=1;},
            }
        }
        for item in ops.iter() {
            match item {
                Op::Label(_) => {
                    
                },
                Op::Jmp(l) => {
                    r.push(Op::Jmp(*(hm.get(l).unwrap())));
                },
                Op::Splt(l1,l2) => {
                    r.push(Op::Splt(*(hm.get(l1).unwrap()) ,*(hm.get(l2).unwrap()) ));
                },
                x=>{r.push(*x);},
            }
        }
        ops = r;
        ops.push(Op::Match);

        // 运行
        let mut threads:Vec<MatchThread> = Vec::new();
        let ss = s.as_bytes();
        let sslen = ss.len();
        // 线程栈
        threads.push(MatchThread{ip:0,pos:0});
        loop {
            if threads.len()==0{
                break;
            }
            let mut thread = threads.pop().unwrap();
            if thread.ip >= ops.len() {
                continue;
            }
            match ops[thread.ip] {
                // 如果没有匹配到, 栈顶弹出的线程就会被移除. 
                Op::Jmp(l) => {
                    thread.ip = l as usize;
                    threads.push(thread);
                },
                Op::Splt(l1,l2) => {
                    thread.ip = l1 as usize;
                    threads.push(thread);
                    // new 一个线程
                    threads.push(MatchThread{ip:l2 as usize,pos:thread.pos});
                },
                Op::Char(c) => {
                    if thread.pos < sslen  && c == ss[thread.pos] as char {
                        // 地址+1, 位置+1, 线程推进
                        thread.ip +=1;
                        thread.pos += 1;
                        threads.push(thread);
                    }
                },
                Op::Any  => {
                    if thread.pos < sslen {
                        thread.ip +=1;
                        thread.pos += 1;
                        threads.push(thread);
                    }
                },
                Op::Match  => { if thread.pos == sslen {return true;} },
                _=>{},
            }
        }
        return false
    }
}
```
