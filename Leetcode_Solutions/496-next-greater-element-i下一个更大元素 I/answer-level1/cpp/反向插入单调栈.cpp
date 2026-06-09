执行用时 :16 ms, 在所有 C++ 提交中击败了87.59%的用户
内存消耗 :9.5 MB, 在所有 C++ 提交中击败了27.13%的用户


```
class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        
        
        vector<int> output;//保存答案
        map<int,int> mp;//元素为数组2的元素，值为数组2内比该元素更大的元素（如不不存在则为-1）
        stack<int> s;//单调栈
        
        for(int i=nums2.size()-1; i>=0; i--){//倒序插入
            
            int temp = -1;
            
            //把栈中比当前指向的元素较小的元素都pop掉（栈中存在的元素只会是数组2中当前所指向的元素右边的元素）
            while(!s.empty() && s.top() < nums2[i])
                s.pop();
            
            if(!s.empty() && s.top()>nums2[i])//如果栈中此时存在比当前所指向元素更大的元素，保存它
                temp = s.top();
            
            s.push(nums2[i]);//把所指向的当前元素压入栈
            mp[nums2[i]] = temp;//在地图中建立当前元素与数组2中下一个比它更大元素（不存在则为-1）的对应关系
        }
        
        for(int i=0; i<nums1.size(); i++){
            
            output.push_back(mp[nums1[i]]);
        }
        
        return output;
    }
};
```
