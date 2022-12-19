### 解题思路
1.看根据数组元素返回索引，立即想到用map方法；
2.本提的一个难点在于数组内没有的元素怎么办，因为在建立map的过程中，将下标索引加1，所以没有的元素为非1.解决了这个就没什么问题了。

### 代码

```cpp
class Solution {
public:
    int search(vector<int>& nums, int target) {
          map<int,int> node_map;
          vector<int> tmp = nums;
          if(nums.size()==0) return -1;
          for(int i=1;i<=nums.size();i++){
              node_map[nums[i-1]] = i;
          }
          sort(nums.begin(),nums.end());
          if(!node_map[target]){
             return -1;
          }
          return node_map[target]-1;
    }
};
```