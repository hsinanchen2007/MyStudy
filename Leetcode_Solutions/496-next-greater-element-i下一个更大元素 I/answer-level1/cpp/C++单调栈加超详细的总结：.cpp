/*递增栈：(从栈顶到栈底递增)
  1.元素入栈之后，其下面元素一定是其左边第一个比它大的数；(可用来求每个元素左边更大的第一个元素)
  2.若在元素插入之前，栈顶元素比插入元素小，那么栈顶元素一定是插入元素左边第一个比它小的数
  3.若在元素插入之前，栈顶元素比插入元素小，那么待插入元素是所有需要出栈的元素右边第一个更大的数； (可用来求每个元素右边更大的第一个元素)
  4.最后一定会留下最大的数（对较大的数更有利）


  递减栈：(从栈顶到栈底递减)
  1.元素入栈之后，其下面的元素一定是其左边第一个比它小的数；(可用来求每个元素左边更小的第一个元素)
  2.若在元素插入之前，栈顶元素比插入元素更大，那么栈顶元素一定是待插入元素左边一个更大的数
  3.若在元素插入之前，栈顶元素比插入元素更大，那么栈顶元素一定是所有需要出栈的元素右边更小的数；(可用来求每个元素右边更小的第一个元素)
  4.最后一定会留下最小的数（对较小 的数更有利）
*/
```C++ []
/*1.正向用递增栈*/
/*class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        map<int,int> PMap;
        stack<int> UpStack;
        vector<int> result;
        for(int i=0;i<nums2.size();i++){
            if(UpStack.empty()||UpStack.top()>nums2[i])
                UpStack.push(nums2[i]);
            else{
                while(!UpStack.empty()&&UpStack.top()<nums2[i]){
                    PMap.insert({UpStack.top(),nums2[i]});
                    UpStack.pop();
                }
                UpStack.push(nums2[i]);
            }
        }
        while(!UpStack.empty()){
            PMap.insert({UpStack.top(),-1});
            UpStack.pop();
        }
        for(int i=0;i<nums1.size();i++){
            result.push_back(PMap[nums1[i]]);   //map的下标操作返回值是和value的类型一样的
        }
        return result;
    }
};*/

/*2.反向使用递增栈*/
class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        map<int,int> PMap;
        stack<int> DStack;
        vector<int> result;
        for(int i=nums2.size()-1;i>=0;i--){
            if(DStack.empty()){
                PMap.insert({nums2[i],-1});
                DStack.push(nums2[i]);
            }
            else if(DStack.top()>nums2[i]){
                PMap.insert({nums2[i],DStack.top()});
                DStack.push(nums2[i]);
            }
            else{
                while(!DStack.empty()&&DStack.top()<nums2[i])
                   DStack.pop();
                if(DStack.empty())
                   PMap.insert({nums2[i],-1});
                else
                   PMap.insert({nums2[i],DStack.top()}); 
                DStack.push(nums2[i]);
            }
        }
        for(int i=0;i<nums1.size();i++)
            result.push_back(PMap[nums1[i]]);   //map的下标操作返回值是和value的类型一样的
        return result;
    }
};
```

