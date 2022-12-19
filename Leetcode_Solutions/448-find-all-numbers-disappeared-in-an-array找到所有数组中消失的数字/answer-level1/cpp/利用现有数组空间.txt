### 解题思路
利用现有数组空间，为避免数组越界和计算位置，直接增加一个0.

### 代码

```cpp
class Solution {
public:
    vector<int> findDisappearedNumbers(vector<int>& nums) {
        int tmp;
        int nsize = nums.size();
        vector <int> ans;
        if (nsize ==0 ) return ans;
        nums.push_back(0);
        for (int i = 0;i < nums.size();i++){
            while ( nums[i] != i ){
                if (nums[i] ==  nums[nums[i]]  ) break;
                else {
                    tmp=nums[i];
                    nums[i]=nums[tmp ];
                    nums[tmp ]=tmp;
                }
            }
        }
        for (int i=1;i< nums.size();i++){
            if (nums[i]!= i )
                ans.push_back(i );
        }
    return ans;
    }
};
```