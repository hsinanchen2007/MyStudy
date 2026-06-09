### 解题思路
一开始想复杂了，直接将数组进行排序然后和原数组每个位置做比较，找到不行同的元素值的坐标，最右边减去最左边

### 代码

```cpp
#include<vector>
#include<algorithm>
class Solution {
public:
    int findUnsortedSubarray(vector<int>& nums) {
        int n=nums.size();
        vector<int> temp=nums;
        sort(temp.begin(),temp.end());

        int left=10005;
        int right=-1;
        for(int i=0;i<n;i++){
            if(temp[i]!=nums[i]){
                if(left>i){
                    left=i;
                }
                if(right<i){
                    right=i;
                }
            }
        }

        if(left==10005||right==-1){
            return 0;
        }
        return right-left+1;
    }
};
```