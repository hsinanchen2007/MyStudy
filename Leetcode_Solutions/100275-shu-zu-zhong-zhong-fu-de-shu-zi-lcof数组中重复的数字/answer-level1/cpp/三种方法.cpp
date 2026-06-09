### 解题思路
方法一：先将数组进行排序，然后依次扫描，判断相邻元素是否一样；

### 代码
```cpp
class Solution {
public:
    int findRepeatNumber(vector<int>& nums) {
        int size=nums.size();
        sort(nums.begin(),nums.end());
        int i=1,j;
        while(i<size){
            j=i-1;
            if(nums[i]==nums[j]){
                return nums[i];
            }
            i++;
        }
        return nums[i]; 
    }
};
```
方法二：利用哈希表，查找该元素是否存在，若不存在，将其添加入哈希表；若已存即是重复元素；

### 代码
```cpp
class Solution {
public:
    int findRepeatNumber(vector<int>& nums) {
        map<int,int> m;
        int i=0;
        while(i<nums.size()){
            if(m[nums[i]]){
                return nums[i];
            }
            m[nums[i]]=1; 
            i++;
        }
        return -1;
    }
};
```
方法三：若数组有没有重复数字，则其下标与其元素是一致的。现在从头开始比较每一个元素nums[i]与其下标i是否对应，若对应，i++，进入下一次循环；若不符合，比较该元素nums[i]与其应该对应位置上的元素nums[nums[i]]，若两个元素相等，则其是重复元素；若这两个元若数组元素不相等，则将其位置互换。然后进入下一次循环（注意此时i的值没有+1）。

### 代码
```cpp
class Solution {
public:
    int findRepeatNumber(vector<int>& nums) {
        int i=0;
        while(i<nums.size()){
            if(nums[i]==i){
                i++;
            }
            else if(nums[i]==nums[nums[i]]){
                return nums[i];
            }
            else{
                int temp;
                temp=nums[i];
                nums[i]=nums[nums[i]];
                nums[temp]=temp;
            }
        }
        return -1;
    }
};
```