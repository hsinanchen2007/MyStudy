### 解题思路
再重新添加一遍所有元素，此时所有元素中只有两个数字缺失一次，该题变为寻找出现次数为一次的数字，利用异或可解。

### 代码

```cpp
class Solution {
public:
    vector<int> missingTwo(vector<int>& nums) {
        vector<int>vec;
        if(nums.size()==0){
            return vec;
        }
        int res=0;
        for(int i=0;i<nums.size();i++){
            res^=nums[i];
        }
        for(int i=1;i<=nums.size()+2;i++){
            res^=i;
        }
        unsigned int flag=1;
        while(flag){
            if(res&flag){
                break;
            }
            else{
                flag=flag<<1;
            }
        }
        int num1=0;
        int num2=0;
        for(int i=0;i<nums.size();i++){
            if(flag&nums[i]){
                num1^=nums[i];
            }
            else{
                num2^=nums[i];
            }
        }
        for(int i=1;i<=nums.size()+2;i++){
            if(flag&i){
                num1^=i;
            }
            else{
                num2^=i;
            }
        }
        vec.push_back(num1);
        vec.push_back(num2);
        return vec;
    }
};
```