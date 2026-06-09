### 解题思路
此处撰写解题思路

### 代码

```cpp
class Solution {
public:
    vector<vector<int>> v;
    vector<int> a;
    void generateX(int index,int index1,int n,int k){
        if(index>=k)
        {
            v.push_back(a);
            return;
        }
        if(index1>n)
            return;
        for(int i=index1;i<=n;++i){
                a.push_back(i);
                generateX(index+1,i+1,n,k);
                a.pop_back();
        }
    }
    vector<vector<int>> combine(int n, int k) {
        generateX(0,1,n,k);
        return v;
    }
};
```