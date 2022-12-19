### 解题思路
核心思路：从头开始遍历，遇到未出现过的元素就加入hashmap，遇到出现过的就返回
执行用时 :64 ms, 在所有 C++ 提交中击败了49.21%的用户
内存消耗 :29.3 MB, 在所有 C++ 提交中击败了100.00%的用户
### 代码

```cpp
class Solution {
public:
    int findRepeatNumber(vector<int>& nums) {
        unordered_map<int,int>nmap;
        for(int i=0;i<nums.size();i++){
            if(nmap.find(nums[i])==nmap.end()){
                nmap[nums[i]]=i;
            }
            else{
                return nums[i];
            }
        }
        return 0;
    }
};
```