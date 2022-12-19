class CQueue {
public:
    CQueue() {}
    
    void appendTail(int value) 
    {
        s1.push(value);
    }
    
    int deleteHead()
    {
        if(s1.empty() && s2.empty())
            return -1;
        
        if(s2.empty())
        {
            while(!s1.empty())
            {
                int num = s1.top();
                s2.push(num);
                s1.pop();
            }
        }
        
        int res = s2.top();
        s2.pop();
            
        return res;
    }
    
private:
    stack<int> s1;
    stack<int> s2;
};