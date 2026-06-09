### 解题思路
此处撰写解题思路

### 代码

```cpp
class Solution {
public:
    int numOfSubarrays(vector<int>& arr, int k, int threshold) {
        if(arr.size()<k) return 0;
        int move=0,count=0;
        for(int i=0;i<k;i++) move+=arr[i];  //这里造一个大小为k的窗口
        if(move>=threshold*k) count++;
        for(int i=k;i<arr.size();i++){
            move=move-arr[i-k]+arr[i];    //遍历，左边出，右边进
            if(move>=threshold*k) count++;
        }
        return count;
    }
};
```