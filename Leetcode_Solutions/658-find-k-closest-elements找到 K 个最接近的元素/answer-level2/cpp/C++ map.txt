### 解题思路
利用map。
时间复杂度O(nlogn),空间复杂度O(n).

### 代码

```cpp
class Solution {
public:
    vector<int> findClosestElements(vector<int>& arr, int k, int x) {
        multimap<int,int> my_map;
        vector<int> my_vec;
        for(int i=0;i<arr.size();++i)
            my_map.insert(pair<int,int>(abs(arr[i]-x),i));
        auto iter=my_map.begin();
        for(int j=0;j<k;++j){
            my_vec.push_back(arr[(*iter).second]);
            ++iter;
        }
        sort(my_vec.begin(),my_vec.end());
        return my_vec;
    }
};
```