## 思路
一句话总结，就是找出距离最近的逆序对数量。
只有最近，才有可能找到最多的。
此题中，“顺序”指的是 递增，“逆序”即递减。


利用单调栈，栈中存放的是每个逆序对中的最大值。
最终 栈中数据必然递增。栈中元素的个数即为逆序对的数量。


## 代码
``` c++
class Solution {
public:
    int maxChunksToSorted(vector<int>& arr) {
        stack<int> mono_st;
        for(int i=0;i<arr.size();i++){
            if(mono_st.empty() || mono_st.top() <= arr[i]){
                mono_st.push(arr[i]);
            }else{
                int cur_max = mono_st.top();
                mono_st.pop();
                while(!mono_st.empty() && mono_st.top()>arr[i]) 
                    mono_st.pop();
                mono_st.push(cur_max);
            }
        }
        return mono_st.size();
    }
};
```