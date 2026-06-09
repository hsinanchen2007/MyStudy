### 解题思路
此处撰写解题思路
### 代码

```cpp
class Solution {
public:
    vector<int> relativeSortArray(vector<int>& arr1, vector<int>& arr2) {
        vector<int>ar;
        for(int i=0;i<arr2.size();i++){
            for(int j=0;j<arr1.size();j++){
                if(arr2[i]==arr1[j]&&arr1[j]!=INT_MAX){
                    ar.push_back(arr2[i]);
                    arr1[j]=INT_MAX;//对arr1中的元素进行标记
                }
            }
        }
        sort(arr1.begin(),arr1.end());
        for(int i=0;arr1[i]!=INT_MAX;i++){
                ar.push_back(arr1[i]);
        }
        return ar;
    }
};
```