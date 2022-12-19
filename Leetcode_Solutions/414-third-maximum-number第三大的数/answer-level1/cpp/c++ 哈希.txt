### 解题思路
此处撰写解题思路
![image.png](https://pic.leetcode-cn.com/22e27c25bd27ca8664ccd985b4d88e05030ddb62fe313321c026aa44537b08ff-image.png)


### 代码

```cpp
class Solution {
public:
 
    int thirdMax(vector<int>& nums) {
        set<int> hash;//建立哈希表，目的是为了去掉数组中重复的元素
        for(int i =0;i<nums.size();i++){
            hash.insert(nums[i]);
        }
        //如果哈希表中的元素数量小于3，则返回最后的一个元素
        if(hash.size()<3){
            return *hash.rbegin();
        }
        //如果数量大于等于3，则删掉最后两个，此时最后的元素为第三大的元素
        int k =2;
        while(k){
            hash.erase(*hash.rbegin());
            k--;
        }
        return *hash.rbegin();
    }
};
```