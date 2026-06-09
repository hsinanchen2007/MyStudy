### 解题思路
此处撰写解题思路

### 代码

```cpp
class Solution {
public:
    vector<int> replaceElements(vector<int>& arr) {
        vector<int> result(arr.size(),-1);
        for(int i=arr.size()-2;i>=0;i--)
        {
            if(arr[i+1]>result[i+1])
                result[i]=arr[i+1];
            else
                result[i]=result[i+1];
        }
        return result;
    }
};
```