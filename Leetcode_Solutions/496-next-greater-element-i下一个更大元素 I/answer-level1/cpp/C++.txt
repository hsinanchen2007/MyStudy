- 开一个map将小数组中的数字存进去，方便后续查找。空间换时间的思路
- 然后遍历大数组，同时维持一个栈
- 如果当前这个数比栈顶大，就将当前栈pop出来，同时就代表当前pop的这个数在右侧最大的就是当前这个数
```
class Solution {
    public:
        vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
            map<int,int> mp;
            stack<int> stack;
    
            for(int value: nums1) {
                mp[value] = -1;
            }
            
            for(int i=0;i<nums2.size();i++) {
                while (!stack.empty()&&stack.top()<nums2[i]) {
                    mp[stack.top()] = nums2[i];
                    stack.pop();
                }
                stack.push(nums2[i]);
            }
            
            for(int i=0;i<nums1.size();i++) {
                nums1[i] = mp[nums1[i]];
            }
            return nums1;
        }
    };
```

执行用时 : 20 ms, 在Next Greater Element I的C++提交中击败了90.06% 的用户
内存消耗 : 9.5 MB, 在Next Greater Element I的C++提交中击败了25.23% 的用户