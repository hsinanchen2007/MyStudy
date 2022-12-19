### 解题思路
此处撰写解题思路

### 代码

```cpp
class Solution {
public:
    vector<int> sumZero(int n) {
        vector<int> v;
        if(n%2==0){
            for(int i=1;i<=n/2;i++){
                v.push_back(i);
                v.push_back(-1*i);
            }
        }else{
            v.push_back(0);
            for(int i=1;i<=(n-1)/2;i++){
                v.push_back(i);
                v.push_back(-1*i);
            }
        }
        return v;
    }
};
```