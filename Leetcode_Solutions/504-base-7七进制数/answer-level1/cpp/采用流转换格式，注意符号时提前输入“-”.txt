### 解题思路
此处撰写解题思路

### 代码

```cpp
class Solution {
public:
    string convertToBase7(int num) {
        if (num==0) return "0";
        stringstream s;if(num<0) s<<"-";
        vector<int> res;
        while(num!=0){
            res.push_back(num%7);
            num=num/7;
        }
        
        for(auto i=res.rbegin();i!=res.rend();i++){
            s<<abs(*i);
            
        }
        return s.str();
    }
};
```