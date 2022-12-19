### 解题思路
这道题让我想起了下推自动机.......

### 代码

```cpp
class Solution {
public:
    int majorityElement(vector<int>& nums) {
        stack<int> s;
        for(int x:nums){
            if(s.empty() || x==s.top()){
                s.push(x);
            }
            else{
                s.pop();
            }
        }
        return s.top();
    }
};
```