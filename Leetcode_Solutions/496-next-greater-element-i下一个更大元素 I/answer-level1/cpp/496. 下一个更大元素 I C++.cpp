### 解题思路
1.使用单调栈。
2.遍历nums2数组，当栈为空就压入栈，若后续数字大于栈顶元素则将栈顶元素作为key，后续数字作为此key的value，并出栈不断重复2步骤直到栈为空或者是栈顶元素大于后续数字。
3.遍历完nums2数组后，循环查看栈内是否有元素，若有元素则出栈元素作为key，对应value写作-1。
4.遍历nums1数组，将其中元素对照map找key将其对应value压入result容器中返回。

### 代码

```cpp
class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        int nums1_size = nums1.size();
        int nums2_size = nums2.size();
        
        stack<int> monotonic_stack;
        unordered_map<int,int> monotonic_map;
        unordered_map<int,int>::iterator monotonic_map_iter;
        vector<int> result(nums1_size,0);
        
        for(int i = 0;i < nums2_size;i++){
            while(!monotonic_stack.empty() && nums2[i] > monotonic_stack.top()){
                monotonic_map[monotonic_stack.top()] = nums2[i];
                monotonic_stack.pop();
            }
            monotonic_stack.push(nums2[i]);
        }
        
        while(!monotonic_stack.empty()){
            monotonic_map[monotonic_stack.top()] = -1;
            monotonic_stack.pop();
        }
        
        for(int i = 0; i < nums1_size;i++){
            monotonic_map_iter = monotonic_map.find(nums1[i]);
            result[i] = monotonic_map_iter->second;
        }
        return result;
    }
};
```