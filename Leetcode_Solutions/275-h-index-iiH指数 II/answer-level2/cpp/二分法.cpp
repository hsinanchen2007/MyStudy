### 解题思路
此处撰写解题思路

### 代码

```cpp
class Solution {
public:
    int hIndex(vector<int>& citations) {
        int low=0,high=citations.size()-1;
        while(low<=high){
            int temp=(low+high)/2;
            if(citations[temp]>=citations.size()-temp)high=temp-1;
            else{
                low=temp+1;
            }
        }
        return citations.size()-low;
    }
};
```