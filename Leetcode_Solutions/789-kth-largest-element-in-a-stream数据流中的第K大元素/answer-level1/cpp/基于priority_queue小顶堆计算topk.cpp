```
class KthLargest {
public:
    priority_queue<int, vector<int>, greater<int>> sq;
    int k;
    KthLargest(int k, vector<int>& nums) {
        this->k = k;
        for(int n:nums)
            add(n);
    }
    
    int add(int val) {
        if(sq.size()==k)
        {
            if(val > sq.top())
            {
                sq.pop();
                sq.push(val);                   
            }
        }
        else
        {
            sq.push(val);
        }
        return sq.top();
    }
};
```
