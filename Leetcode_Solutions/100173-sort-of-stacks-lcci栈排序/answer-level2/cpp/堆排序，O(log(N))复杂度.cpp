### 解题思路
题里有个坑，栈空时peek返回-1。
借用堆排序的思想，每次push时更新堆顶元素，每次pop时也更新堆顶元素，保证一定是的最小堆。
其他的和普通的栈一样。

### 代码

```cpp
class SortedStack {
public:
    int Stack[5001];
    int top;
    SortedStack() {
        top=0;
    }
    
    void up(int top){
        int temp=Stack[top];
        while(top > 0 && Stack[(top-1)/2] > temp){
            Stack[top] = Stack[(top-1)/2];
            top = (top-1)/2;
        }
        Stack[top]=temp;
    }

    void down(){
        int index=0,index1,temp=Stack[0];
        while(index < top){
            if(2*index+2 < top){
                index1 = Stack[2*index+1]<Stack[2*index+2] ? 2*index+1:2*index+2;
                if(Stack[index1]<temp){
                    Stack[index]=Stack[index1];
                    index=index1;
                }else
                    break;
            }else if(2*index+1 < top){
                index1 = 2*index+1;
                if(Stack[index1]<temp){
                    Stack[index]=Stack[index1];
                    index=index1;
                }
                break;
            }else
                break;
        }
        Stack[index]=temp;
    }

    void push(int val) {
        Stack[top]=val;
        up(top);
        top++;
    }
    
    void pop() {
        if (top){
            Stack[0]=Stack[--top];
            down();
        }
    }
    
    int peek() {
        if(top)
            return Stack[0];
        else
            return -1;
    }
    
    bool isEmpty() {
        return top==0;
    }
};

/**
 * Your SortedStack object will be instantiated and called as such:
 * SortedStack* obj = new SortedStack();
 * obj->push(val);
 * obj->pop();
 * int param_3 = obj->peek();
 * bool param_4 = obj->isEmpty();
 */
```