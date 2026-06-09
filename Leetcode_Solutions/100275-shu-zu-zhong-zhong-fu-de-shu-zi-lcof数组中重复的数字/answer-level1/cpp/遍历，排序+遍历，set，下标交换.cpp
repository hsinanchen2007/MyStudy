### 代码
#### 1.遍历

```cpp
// 遍历
    int findRepeatNumberV1(vector<int>& nums) {
        for(unsigned i = 0; i < nums.size()-1; i++){
            for(unsigned j = i+1; j < nums.size(); j++){
                if(nums[i] == nums[j]){
                    return nums[i];
                }
            }
        }
        return -1;
    }
```
提交超时了，没通过。
#### 2.排序+遍历

```cpp
class Solution {
public:
    int findRepeatNumber(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int pre = nums[0];

        for(vector<int>::iterator it = nums.begin()+1; it != nums.end(); ++it){
            if(*it == pre){
                return pre;
            }
            pre = *it;
        }
        return -1;
        }
};
```
#### 3.set
```cpp
    int findRepeatNumberV3(vector<int>& nums) {

        set<int> s;
        for(unsigned i = 0; i < nums.size(); i++){
            if(!s.count(nums[i])){
                s.insert(nums[i]);
            }
            else{
                return nums[i];
            }
        }
        return -1;
    }
```
#### 4.下标交换
```cpp
    int findRepeatNumber(vector<int>& nums) {
        for(unsigned i = 0; i <nums.size(); i++){
            while(nums[i] != i){
                if(nums[i] == nums[nums[i]]){
                    return nums[i];
                }
                else{
                    mySwap(nums, i, nums[i]);
                }
            }
        }
        return -1;
    }
    void mySwap(vector<int>& nums, int index1, int index2){
        int tmp = nums[index1];
        nums[index1] = nums[index2];
        nums[index2] = tmp;
    }
```