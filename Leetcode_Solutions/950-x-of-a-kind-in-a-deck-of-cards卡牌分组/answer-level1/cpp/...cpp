### 解题思路
此处撰写解题思路

### 代码

```cpp
class Solution {
public:
   int count[100000];
    bool hasGroupsSizeX(vector<int>& deck) {
     int n=deck.size();
     
     for(auto x :deck)
     {
       count[x]++;
     }
     vector<int>value;
     for(int i=0;i<10000;i++)
     {
         if(count[i]>0)
         value.emplace_back(count[i]);
     }
     for(int i=2;i<=n;i++)
     {
         if(n%i==0){
             bool falge=1;
             for(auto v:value)
             {
                 if(v%i!=0)
                 {
                     falge=0;
                     break;
                 }

             }
             if(falge) return true;
         }
     }
     return false;
    }
};
```