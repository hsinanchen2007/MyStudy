### 解题思路
此题利用map自动排序的特性，以arr[i]为键，mymap.second存放着以mymap.first为值的数组下标。
从前往后遍历mymap，使用一个计数器count计算当前数字是第几，根据mymap.second存放的数组下标将计数放入对应的位置

### 代码

```cpp
class Solution {
public:
    vector<int> arrayRankTransform(vector<int>& arr) {
        map<int,vector<int>> mymap;
        int count = 1;
        for(auto i = 0;i < arr.size();i++){
            mymap[arr[i]].push_back(i);
        }
        for(auto x:mymap){
            for(auto y:x.second){
                arr[y] = count;
            }
            count++;
        }
        return arr;
    }
};
```