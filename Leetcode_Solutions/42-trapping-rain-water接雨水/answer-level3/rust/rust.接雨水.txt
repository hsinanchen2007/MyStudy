### 解题思路
此处撰写解题思路

### 代码

```rust
impl Solution {
    pub fn trap(height: Vec<i32>) -> i32 {
        if (height.len()==0){
            return 0;
        }
        let mut stack:Vec<usize>=Vec::new();
        let mut ans = 0;
        for i  in 0..height.len(){
            while !stack.is_empty() && height[*stack.last().unwrap()]<height[i]{
                let curIdx = stack.pop().unwrap();
                while(!stack.is_empty() && height[*stack.last().unwrap()]==height[curIdx]){
                    stack.pop();
                }
                if(!stack.is_empty()){
                    let &stackTop = stack.last().unwrap();
                    ans += (height[stackTop].min(height[i])-height[curIdx])*((i-stackTop-1) as i32);
                }
            }
            stack.push(i);
        }
        ans
    }
}
```