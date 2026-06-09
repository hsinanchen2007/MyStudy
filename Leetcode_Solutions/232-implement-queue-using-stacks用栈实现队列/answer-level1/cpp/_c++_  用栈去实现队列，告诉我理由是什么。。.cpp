### 解题思路
假设有一大瓶糖果，想取最底下最好吃的那个。

1. 把糖全倒出来。
2. 拿到想要的糖果。
3. 再把倒出来的糖原封不动的装回去。

真*脱裤子放屁。。

### 代码

```cpp
class MyQueue {
public:
    stack<int> push_stack;
    stack<int> pop_stack;

    void push(int x) { push_stack.push( x ); }

    void pour(stack<int>& s1, stack<int>& s2){
        while( !s1.empty() ){ 
            s2.push( s1.top() ); 
            s1.pop(); 
        }
    }
    
    int help( bool is_pop ){
        
        // 把糖果都倒出来
        pour( push_st, pop_st );

        // 拿到最想吃的那个
        int output = pop_stack.top();

        if(is_pop) pop_stack.pop();
        
        // 然后把导出来的糖有原封不动的放回去。
        pour( pop_st, push_st );

        return output;
    }

    int pop() { return help( true ); }
    
    int peek(){ return help( false ); }
    
    bool empty() { return push_stack.empty(); }
};

```