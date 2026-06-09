### 解题思路
枚舉法和使用find解題。
思路為遍歷數組，找到另一個相加為target的數則返回存儲了下標的ans向量。
### 代码

```cpp
//使用find優化：
class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
       int n = nums.size();
       vector<int> ans;
       for(int i=0;i<n-1;i++){
        vector<int>::iterator it = find(nums.begin()+i+1,nums.end(),target-nums[i]);
        //用find尋找互補的數是否在vector中，若無則返回ans.end()。
        //ans.end()指向的是下一個還未插入元素的位置
        if(it!=nums.end()){
            ans.push_back(i);
            int index = (&*it-&nums[0]);//得到index的方法
            ans.push_back(index);
            return ans;    
          };
       };
       return ans;
    };
};

//枚舉解法
/*class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        int n = nums.size(),i=0,j;
        vector<int> ans;
        for(i=0;i<n;i++)
            for(j=i+1;j<n;j++)
                if(nums[i]+nums[j]==target){
                ans.push_back(i);
                ans.push_back(j);
                return ans;    
                };
     return ans;      
    };
};*/ 
```