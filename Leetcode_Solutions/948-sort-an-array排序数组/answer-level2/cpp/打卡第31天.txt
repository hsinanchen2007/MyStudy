桶排序
```
class Solution {
public:
    vector<int> sortArray(vector<int>& nums) {
        int n = nums.size();
        int m[100000] = {0};
        for(int i=0;i<n;i++) {
            m[nums[i]+50000]++;
        }
        int index = 0;
        vector<int> z(n, 0);
        for(int i=0;i<100000;i++){
            for(int j=0;j<m[i];j++){
                z[index+j] = i - 50000;
            }
           
           index += m[i];
        }
        return z;
        
    }
};
```
