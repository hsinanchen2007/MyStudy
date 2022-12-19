### 解题思路

使用两个指针，存储最左边栈的下标和最右边栈的下标

首先使用数组形式来存储栈，方便根据下标提取

重点解决的问题就是左右两个指针如何更新：
- 左指针：1、push时当前栈满了，向后遍历  2、popAtStack时，如果当前栈有值，pop之后会出现空缺，取min(index,左指针)
- 右指针：1、push时取max(左指针，右指针) 2、pop时，如果当前栈为空，向前遍历

### 代码

```java
class DinnerPlates {
    Stack<Integer>[] stacks = new Stack[100001];
    int size;
    int min_index = 0;
    int max_index = 0;
    public DinnerPlates(int capacity) {
        this.size = capacity;
    }
    
    public void push(int val) {
        
        if(stacks[min_index]==null){
            stacks[min_index] = new Stack<>();
        }
        Stack<Integer> stack = stacks[min_index];
        if(stack.size()==size){
            //向后遍历，直到栈不为满
            while(stacks[min_index]!=null && stacks[min_index].size()==size){
                ++min_index;
            }
            if(stacks[min_index]==null){
                stacks[min_index]= new Stack<>();
            }
        }
        stacks[min_index].push(val);
        //比较更新max_index
        if(max_index<min_index){
            max_index = min_index;
        }
    }
    
    public int pop() {
        if(max_index==-1) return -1;
        //向前遍历，直到栈不为空
        if(stacks[max_index]==null || stacks[max_index].size()==0){
            while(max_index>=0 && (stacks[max_index]==null || stacks[max_index].size()==0)){
                --max_index;
            }
        }
        if(max_index==-1){
            return -1;
        }
        return stacks[max_index].pop();
    }
    
    public int popAtStack(int index) {
        if(stacks[index]==null || stacks[index].size()==0){
            return -1;
        }
        //比较更新min_index
        if(index<min_index){
            min_index = index;
        }
        return stacks[index].pop();
    }
}

/**
 * Your DinnerPlates object will be instantiated and called as such:
 * DinnerPlates obj = new DinnerPlates(capacity);
 * obj.push(val);
 * int param_2 = obj.pop();
 * int param_3 = obj.popAtStack(index);
 */
```