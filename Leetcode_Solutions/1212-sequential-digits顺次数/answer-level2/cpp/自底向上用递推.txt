### 解题思路
此处撰写解题思路

### 代码

```cpp
class Solution {
public:
    string s="123456789";
    vector<int> sequentialDigits(int low, int high) {
          vector<int> v;
          for(int len=1;len<=9;++len){
             int sum;
             for(int j=0;j+len-1<9;++j){
                 sum=stoi(s.substr(j,len));
                 if(sum>=low&&sum<=high)
                     v.push_back(sum);
                 if(sum>high)
                     break;
             }
             if(sum>high)
                break;
          } 
          return v;   
    }
};
```