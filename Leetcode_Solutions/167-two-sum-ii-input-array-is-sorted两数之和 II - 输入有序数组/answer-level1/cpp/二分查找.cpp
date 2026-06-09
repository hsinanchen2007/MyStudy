### 解题思路
第一次使用遍历，果不其然超时了；
第二次我改了改，将之前的第二步遍历改成二分查找，算是可以提交了
不过耗时和内存还是过大
如下是第二次的代码。

### 代码

```cpp
class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        for(int k=0;k<nums.size();k++){
            int i=k;//start
            int j=nums.size();//end
            //use the binary search
            while(i<j-1){
                int mid=(i+j)/2;
                if(nums[mid]==target-nums[k]){
                    vector<int>re{k+1,mid+1};
                    return re;
                }
                if(nums[mid]<target-nums[k])i=mid;
                if(nums[mid]>target-nums[k])j=mid;
            }
        }
        vector<int> re{-1,-1};
        return re;//just to pass the compiling
    }
};
```
### 解题思路
第三次使用了双指针，遗憾的是时间并没有减少，疑惑；

### 代码
```cpp
class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        int i=0;
        int j=nums.size()-1;
        int mid;
        while(nums[i]+nums[j]!=target){
            if(nums[i]+nums[j]>target){
                j--;
            }
            if(nums[i]+nums[j]<target){
                i++;
            }
        }
        vector<int>re{i+1,j+1};
        return re;
    }   
};
```