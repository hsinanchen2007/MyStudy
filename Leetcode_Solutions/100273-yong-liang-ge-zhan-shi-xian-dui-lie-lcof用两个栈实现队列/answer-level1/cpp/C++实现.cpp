两个栈（st1和st2）
插入元素时，直接push进st1
删除元素时，
1.如果st1和st2都为空  return -1
2.如果st2空 st1不空  将st1的数据倒入st2
3.如果st2不空 直接pop st2的栈顶

```
class CQueue {
public:
    stack<int> st1;
    stack<int> st2;
    CQueue() {

    }
    
    void appendTail(int value) {
        st1.push(value);
    }
    
    int deleteHead() {

        if(st1.empty()&&st2.empty())
        return -1;
         if(st2.empty()){
             while(!st1.empty()){
             int temp=st1.top();
            st1.pop();
            st2.push(temp);
            }
         }
        
            int temp=st2.top();
            st2.pop();
            return temp;
        
            
      
    }
};
```
