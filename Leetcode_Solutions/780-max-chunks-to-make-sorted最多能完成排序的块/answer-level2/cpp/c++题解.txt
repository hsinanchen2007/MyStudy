### 解题思路
判断到当时位置的最大数组值大不大于标号，若大于，继续循环，小于，则分出来一个块，res++


### 代码

```cpp
class Solution {
public:
    int maxChunksToSorted(vector<int>& arr) {
        int res=1;
        int premax=0;
        for(int i=0;i<arr.size()-1;i++)
        {
            premax=max(premax,arr[i]);
            if(premax==i){
                res++;
            }
        }
        return res;
    }
};
```