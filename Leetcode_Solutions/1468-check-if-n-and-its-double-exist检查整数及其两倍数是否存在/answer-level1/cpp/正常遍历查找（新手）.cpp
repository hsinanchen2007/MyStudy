
### 代码

```cpp
class Solution {
public:
    bool checkIfExist(vector<int>& arr) 
    {
        //因为0的2倍还是0，因此如果只有一个0的话，先将0去除。
        if(count(arr.begin(),arr.end(),0)==1) arr.erase(find(arr.begin(),arr.end(),0));
        
        for(int a:arr)
            if(find(arr.begin(),arr.end(),2*a)!=arr.end())
                return true;
        return false;
    }
};
```