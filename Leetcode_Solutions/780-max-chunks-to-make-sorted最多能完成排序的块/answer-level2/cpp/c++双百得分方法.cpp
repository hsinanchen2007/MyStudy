### 解题思路
此处撰写解题思路

### 代码

```cpp
class Solution {
public:
    int maxChunksToSorted(vector<int>& arr) {
        //当前数组最大值等于下标，则为一个完整的子数组
        int res=0;
        int max_cur=arr[0];
        for(int i=0;i<arr.size();i++)
        {
            if(arr[i]>max_cur)
            {
                max_cur=arr[i];
            }
            if(i==max_cur)
            {
                res++;
            }
        }
        return res;
    }
};
```