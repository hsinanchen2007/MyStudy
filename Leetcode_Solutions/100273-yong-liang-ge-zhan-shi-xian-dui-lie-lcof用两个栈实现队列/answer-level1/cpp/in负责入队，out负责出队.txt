建立两个栈，in，out
in负责进入队列
out负责出队
出队时，out不为空直接弹栈，为空，先将所有的in，弹出，并压入out，最后弹出out的栈顶

```
class CQueue {
	int v;
    stack<int> in;
    stack<int> out;
public:
    CQueue() {}
    
    void appendTail(int value) {
        in.push(value);
    }
    
    int deleteHead() {
        if(in.empty() && out.empty())
        	return -1;
        if(out.empty() && !in.empty())
        {
        	while(!in.empty())
        	{
        		out.push(in.top());
        		in.pop();
        	}
        }
        v = out.top();
    	out.pop();
    	return v;
    }
};
```
