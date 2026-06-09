### 代码

```cpp
class Solution {
public:
    void rotate(vector<int>& nums,int k){
        int n = nums.size();
        k = k%n;
        int t = k;
        int j = 0;
        int num = n;
        while(num--){
            if(t==0){
                j++;
                t = k;
                continue;	
            } 
            swap(nums[j],nums[j+t]);
            t = (t+k)%n;
        }
    }
};
```