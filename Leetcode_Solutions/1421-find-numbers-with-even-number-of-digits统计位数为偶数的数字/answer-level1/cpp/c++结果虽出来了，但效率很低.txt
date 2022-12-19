### 解题思路
此处撰写解题思路

### 代码

```cpp
class Solution {
public:
    int findNumbers(vector<int>& nums) {
        int count = 0;
        for(int i=0;i<nums.size();i++){
            int n = nums[i];
            for(int j=5;j>0;--j){
                int a = pow(10,j);
                if(n/a > 0) {//如果>0则代表最高位第j为
                    if((j+1)%2 == 0){
                        count += 1;
                        break;
                    }
                    break;
                }           
            }
        }
        return count;

    }
};
```