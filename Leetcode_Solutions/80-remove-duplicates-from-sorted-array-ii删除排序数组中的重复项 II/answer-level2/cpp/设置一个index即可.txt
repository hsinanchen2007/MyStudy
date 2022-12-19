### 解题思路
貌似前面有一道类似的题，通过设置一个index控制需要添加的元素即可，这里注意不需要交换，替换即可。

### 代码

```cpp
class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        if(nums.size()<=1){
            return nums.size();
        }
        bool first = true;
        int index = 0;
        for(int i=1;i<nums.size();i++){
            if(nums[i]==nums[index]){
                if(first){
                    nums[index+1] = nums[i];
                    index++;
                    first = false;
                }
                else{
                    for(int j=i+1;j<nums.size();j++){
                        if(nums[j]!=nums[index]){
                            nums[index+1] = nums[j];
                            first = true;
                            index++;
                            i=j;
                            break;
                        }
                    }
                }
            }
            else{
                nums[index+1] = nums[i];
                index++;
                first = true;
            }
            
        }
        return index+1;
    }
};

```