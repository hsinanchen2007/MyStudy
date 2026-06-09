```cpp []
class DinnerPlates {
public:
    DinnerPlates(int capacity) :n(capacity){
        data.push_back(stack<int>());
        left=right=data.begin();
    }
    
    void push(int val) {
        if(left->empty()){
            right=max(left,right);
        }
        left->push(val);
        if(left->size()==n){
            for(auto e=data.end();left<e;++left){
                if(left->size()<n){
                    return;
                }
            }
            data.push_back(stack<int>());
            left=data.end()-1;
            right=left-1;
        }
    }
    
    int pop() {
        if(right->empty()){
            return -1;
        }
        int res=right->top();
        right->pop();
        if(right->size()==0){
            for(auto b=data.begin();right>=b;--right){
                if(right->size()>0){
                    left=min(left,right);
                    return res;
                }
            }
            left=right=data.begin();
        }
        return res;
    }
    
    int popAtStack(int index) {
        if(0<=index && index<data.size() && !data[index].empty()){
            auto temp=data.begin()+index;
            int res=temp->top();
            temp->pop();
            left=min(left,temp);
            if(temp->empty() && right==temp){
                for(auto b=data.begin();right>=b;--right){
                    if(right->size()>0){
                        left=min(left,right);
                        return res;
                    }
                }
                left=right=data.begin();
            }
            return res;
        }
        return -1;
    }
private:
    vector<stack<int>> data;
    int n;
    vector<stack<int>>::iterator left,right;
};

/**
 * Your DinnerPlates object will be instantiated and called as such:
 * DinnerPlates* obj = new DinnerPlates(capacity);
 * obj->push(val);
 * int param_2 = obj->pop();
 * int param_3 = obj->popAtStack(index);
 */
```
```python []
class DinnerPlates:

    def __init__(self, capacity: int):
        self.data=[[]]
        self.n=capacity
        self.left=0
        self.right=0

    def push(self, val: int) -> None:
        if not self.data[self.left]:
            self.right=max(self.left,self.right)
        self.data[self.left].append(val)
        if len(self.data[self.left])==self.n:
            for i in range(self.left,len(self.data)):
                if len(self.data[i])<self.n:
                    self.left=i
                    return
            self.data.append([])
            self.left+=1

    def pop(self) -> int:
        if not self.data or not self.data[self.right]:
            return -1
        res=self.data[self.right].pop()
        if len(self.data[self.right])==0:
            self.data.pop()
            for i in range(self.right-1,-1,-1):
                if len(self.data[i])>0:
                    self.right=i
                    self.left=min(self.left,self.right)
                    return res
            self.right=0
            self.left=0
        return res

    def popAtStack(self, index: int) -> int:
        if 0<=index<len(self.data) and self.data[index]:
            res=self.data[index].pop()
            self.left=min(self.left,index)
            if not self.data[index] and self.right==index:
                self.data.pop()
                for i in range(self.right-1,-1,-1):
                    if len(self.data[i])>0:
                        self.right=i
                        self.left=min(self.left,self.right)
                        return res
                self.right=0
                self.left=0
            return res
        else:
            return -1


# Your DinnerPlates object will be instantiated and called as such:
# obj = DinnerPlates(capacity)
# obj.push(val)
# param_2 = obj.pop()
# param_3 = obj.popAtStack(index)
```
不得不说c++的iterator写这个特别舒服