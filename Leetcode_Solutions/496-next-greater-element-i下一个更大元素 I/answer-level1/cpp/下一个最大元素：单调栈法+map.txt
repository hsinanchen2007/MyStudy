### 解题思路
此处撰写解题思路
原方法：
（1）对nums1中的每个元素，在nums2中线性扫描一遍，找到则返回值，没有则-1；
（2）时间复杂度为O(n^2)

新方法：
借鉴学习了leetcode官方题解
(1) 先把nums2中所有数的下一个更大元素找到（单调栈法），并把这个pair insert入一个map中；  时间复杂度O(m)
(2) nums1中的元素依次作为map find的参数，找到对应位置；  时间复杂度O(n)
效能：100%执行时间，55.83%内存消耗

单独说明单调栈法：
（1）原数入栈前看栈顶元素是否更小，最小的话栈顶元素的“下一个最大元素”找到，栈顶pop，并与最大元素形成pair; 待入栈元素接着比较下一个栈顶；
（2）若入栈元素更小，则直接入栈。



### 代码

```cpp
#include <map>
#include <vector>
#include <stack>
class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        //单调栈法：只考虑nums2,得到数组中每一个元素的下一个最大元素
        //         注意意外情况，没找到时为-1的处理
        //         将找到的对应关系存入map中
        //采用map映射：考虑nums1，用map匹配每一个元素

        stack<int> oneDirectStk;
        map<int,int> resMap;
        vector<int> resVec;

        for(int i = 0; i < nums2.size(); i++){
            while((!oneDirectStk.empty()) && nums2[i] > oneDirectStk.top()){
                resMap.insert(pair<int, int>(oneDirectStk.top(),nums2[i]));
                oneDirectStk.pop();
            }
            oneDirectStk.push(nums2[i]);
        }

        while(!oneDirectStk.empty()){
            resMap.insert(pair<int,int>(oneDirectStk.top(),-1));
            oneDirectStk.pop();
        }

        for(int i = 0; i < nums1.size(); i++){
            resVec.push_back(resMap.find(nums1[i])->second);
        }

        return resVec;

    }
};
```