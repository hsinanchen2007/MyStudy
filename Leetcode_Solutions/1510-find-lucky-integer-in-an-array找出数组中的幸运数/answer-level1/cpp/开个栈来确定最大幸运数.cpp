### 解题思路
关键就是能否找出最大幸运数了吧

### 代码

```cpp
class Solution {
public:
    int findLucky(vector<int>& arr) {
        if(arr.size()==1||arr.size()==0)
        {
            return -1;
        }
        stack<int> maxq;
        maxq.push(-1);
        int temp;
        for(int i = 0; i<arr.size();i++)
        {
            int num = 0;
            temp = arr[i];
            for(int k = 0 ;k<arr.size();k++)
            {
                if(arr[k]==temp) num++;                
            }
            if(temp == num)
            {
                if(temp>maxq.top())
                {
                    maxq.pop();
                    maxq.push(temp);
                }
            }                    
        }
        if(!maxq.empty()) return maxq.top();       
        return -1;       
    }
};
```