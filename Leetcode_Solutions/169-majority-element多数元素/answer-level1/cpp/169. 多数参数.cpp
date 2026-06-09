### 解题思路
利用multimap中map[]如果不存在自动创建，对数组进行遍历，将数组中的值作为key值存放于map容器中，因为key值在multimap是可以重复的，所以可以计算出每个元素出现的次数

### 代码

```cpp
class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int n = nums.size();
        multimap<int,int>temp;
        int a;
        for(int i = 0;i<n;i++){
            temp[nums[i]]++;
            if(temp[nums[i]]>n/2)
                a = nums[i];
        }
        return a;
    }
};
```