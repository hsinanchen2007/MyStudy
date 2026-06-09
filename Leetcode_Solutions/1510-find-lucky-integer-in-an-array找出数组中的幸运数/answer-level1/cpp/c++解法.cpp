### 解题思路
此处撰写解题思路
遍历数组元素存入以元素大小为key，元素个数为value的unordered_map，然后遍历unordered_map如果map项的key等于value存入一个vector<int>容器，最后根据容器size决定返回容器内vector最大值或-1。
### 代码

```cpp
class Solution {
public:
    int findLucky(vector<int>& arr) {
        unordered_map<int, int> countMap;

        for (int iVal : arr) {
          ++countMap[iVal];
        }

        vector<int> iVec;

        for (auto & item : countMap) {
          if (item.first == item.second) {
            iVec.push_back(item.first);
          }
        }

        if (iVec.size() > 0) {
          return *max_element(iVec.begin(), iVec.end());
        } else {
          return -1;
        }
    }
};
```