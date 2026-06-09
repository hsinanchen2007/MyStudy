### 解题思路
此处撰写解题思路

### 代码

```cpp
class Solution {
public:
    vector<int> relativeSortArray(vector<int>& arr1, vector<int>& arr2) {
        // 思路：为了保持 arr1 中排序的数组和 arr2中的元素有相同的相对位置，在排序比较时，对于两个都在arr2中的元素，按照其在arr2中的下标排序，一个在一个不在按照题意 在的小于不在的，如果两个都不在 按照大小比较
        if (arr1.empty()) return arr1;

        // 为了方便查找下标，使用hash 记录一下 arr2中每个元素的值和下标
        vector<int> indexs(1002, -1); // 0 <= arr1[i], arr2[i] <= 1000
        for (int i=0; i<arr2.size(); i++) {
            indexs[arr2[i]] = i;
        }

        sort(arr1.begin(), arr1.end(), [&](int a, int b) {

            // 判断
            // 如果两个都在arr2中，按照下标大小排序(相对位置)
            if ((indexs[a]!=-1) && (indexs[b]!=-1)) {
                return indexs[a] < indexs[b];
            }

            // 如果一个在 一个不在
            if (indexs[a] != -1) {
                return true; // 小于不在的
            }

            if (indexs[b] != -1) {
                return false;
            }

            // 如果两个都不在，按照值的大小
            return a < b;
        });
        return arr1;
    }

};
```