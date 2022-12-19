### 解题思路
    打卡学习 ~ ~ ~
### 代码

```cpp
class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        stack<int> s;
        vector<int> res;
        unordered_map<int,int> map;
        
        for(int i = 0;i < nums2.size();i++){
            //将栈顶元素逐个弹出，直至栈空 或者 栈顶元素大于 nums2[i]
            while(!s.empty() && s.top() < nums2[i]) {   
                map.insert(make_pair(s.top(),nums2[i]));   //nums2[i]作为每一个弹出元素的 "下一个更大元素"
                s.pop();
            }
            s.push(nums2[i]);
        }
        //处理栈中剩余元素
        while(!s.empty()){
            map.insert(make_pair(s.top(),-1));
            s.pop();
        }

        for(int i = 0;i < nums1.size();i++)
            res.push_back(map[nums1[i]]);
        return res;
    }
};

```