### 解题思路
![55.png](https://pic.leetcode-cn.com/299d4102b7191bafa7f39d88a3d4d5fda6212801f376866190a1dd0412ad8fe1-55.png)
主要思路是使用vector的可变特性建立栈
注意细节即可，难度不大
cap=0的时候禁止入栈！！！

### 代码

```cpp
class StackOfPlates {
 private:
    int size;
    vector<stack<int> > stack_sets;
public:
    StackOfPlates(int cap) {
        size=cap;
    }
    
    void push(int val) {
        if(size==0)
            return;
        if(stack_sets.size()==0||stack_sets[stack_sets.size()-1].size()==size)
        {
            stack<int> tmp;
            tmp.push(val);
            stack_sets.push_back(tmp);
        }
        else
        {
            stack_sets[stack_sets.size()-1].push(val);
        }
    }
    
    int pop() {
        if(stack_sets.size()==0)
            return -1;
        int ret=stack_sets[stack_sets.size()-1].top();
        stack_sets[stack_sets.size()-1].pop();
        if(stack_sets[stack_sets.size()-1].empty())
           {
                auto it=stack_sets.end();
                it--;
            stack_sets.erase(it);
        }
        return ret;
    }
    
    int popAt(int index) {
        if(stack_sets.size()==0||index<0||index>=stack_sets.size())
            return -1;
        int ret=stack_sets[index].top();
        stack_sets[index].pop();
        if(stack_sets[index].empty())
        {
            stack_sets.erase(stack_sets.begin()+index);
        }
        return ret;
    }
};

/**
 * Your StackOfPlates object will be instantiated and called as such:
 * StackOfPlates* obj = new StackOfPlates(cap);
 * obj->push(val);
 * int param_2 = obj->pop();
 * int param_3 = obj->popAt(index);
 */
```