### 解题思路
1.插入排序+二分查找（通过）
2.插入排序+遍历查找（超时）
3.2层for循环暴力方法（超时）


方法1：插入排序+二分查找（通过）
原理：
1）从后往前找。
2）每找到1个，进行二分查找，依据找到的位置进行插入排序。构建有序序列

### 代码

```cpp
class Solution {
public:
    vector<int> countSmaller(vector<int>& nums) {
        vector<int>counts(nums.size(),0);
        vector<int>temp;//插入排序数组
        for(int i=nums.size()-1;i>=0;i--)
        {
            vector<int>::iterator it=lower_bound(temp.begin(),temp.end(),nums[i]);
            counts[i]=it-temp.begin();
            temp.insert(it,nums[i]);
        }
        return counts;
    }
};
```

方法2：插入排序+遍历查找（超时）
```cpp
class Solution {
public:
    vector<int> countSmaller(vector<int>& nums) {
        vector<int> result = vector<int>(nums.size(),0) ;
        deque<int> tmp;
        for(int i = nums.size()-1;i>=0;i--){
            int index = 0;
            for(int j =0 ;j<tmp.size();j++){
                if(nums[i]>tmp.back()){
                    index = tmp.size();
                    break;
                }

                if(nums[i]<tmp.front()){
                    index = 0;
                    break;
                }


                if(nums[i]>tmp[j]){
                    continue;
                }else{
                    index = j;
                    break;
                }
            }
            tmp.insert(tmp.begin()+index,nums[i]);


            result[i] = index;

        }

        return result;
    }
};
```
方法3：2层for循环暴力方法（超时）
```cpp
class Solution {
public:
    vector<int> countSmaller(vector<int>& nums) {
        vector<int> result;
        for(int i = 0;i<nums.size();i++){
            int count = 0;
            for(int j = i+1;j<nums.size();j++){
                if(nums[i]>nums[j]){
                    count++;
                }
            }
            result.push_back(count);
        }

        return result;
    }
};
```
