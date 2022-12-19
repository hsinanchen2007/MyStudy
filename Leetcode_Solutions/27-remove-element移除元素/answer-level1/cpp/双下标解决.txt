### 解题思路
此处撰写解题思路
### 代码
双下标，下标1指向不等于val的位置，下标2循环遍历整个数组
最后返回下标1
```cpp
class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        cout<<nums.size()<<endl;
        int k=0;
        for(int i=0;i<nums.size();i++){
           
            if(nums[i]!=val){
                nums[k++]=nums[i];
            }
        }
        cout<<k<<endl;
        return k;
    }
};
```