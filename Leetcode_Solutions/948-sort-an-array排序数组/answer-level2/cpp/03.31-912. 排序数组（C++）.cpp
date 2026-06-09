### 解题思路
炫耀一下吧
![image.png](https://pic.leetcode-cn.com/0b617bd2f3be11cfe1d8a812c2cebed0d9f5e0d9c5b600dfe51ef93e9fd99e3a-image.png)

### 代码

```cpp
#include <vector>
class Solution {
public:
    vector<int> mergeSort(vector<int> left, vector<int> right) {
        int left_Length = left.size();
        int right_Length = right.size();
        vector<int> res(left_Length+right_Length);
        int index = 0;
        int left_index = 0;
        int right_index = 0;
        while (left_index < left_Length && right_index < right_Length) {
            if (left[left_index] >= right[right_index]) {
                res[index] = right[right_index++];
            } else {
                res[index] = left[left_index++];
            }
            index++;
        }
        if (left_index == left_Length) {
            while (right_index < right_Length) {
                res[index++] = right[right_index++];
            }
        }
        if (right_index == right_Length) {
            while (left_index < left_Length) {
                res[index++] = left[left_index++];
            }
        }
        return res;

    }

    vector<int> quickSort(vector<int> &vec, int start, int end) {
        if(end - start == 0) {
            vector<int> res(1,vec[start]);
            return res;
        }
        int mid = (start + end) / 2;
        vector<int> left = quickSort(vec,start,mid);
        vector<int> right = quickSort(vec,mid+1,end);
        vector<int> res = mergeSort(left,right);
        return res;
    }

    vector<int> sortArray(vector<int>& nums) {
        vector<int> res = quickSort(nums,0,nums.size()-1);
        return res;
    }
};
```