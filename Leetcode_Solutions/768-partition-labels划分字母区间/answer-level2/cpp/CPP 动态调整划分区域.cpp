### 解题思路
start记录当前区间的起始下标
len为当前区间的长度
遍历字符串，通过查找当前元素最后出现的位置，判断在不在区间内来调整长度

### 代码

```cpp
class Solution {
public:
    vector<int> partitionLabels(string S) {
        int start=0;
        int len=1;
        vector<int> res;
        for(int i=start;i<S.length();i++){
            if(S.find_last_of(S[i])>start+len-1){   //如果最后出现的位置在当前区间的后面（起始位置+区块长度）
                len=S.find_last_of(S[i])-start+1;   //调整区间长度到最后出现的位置
            }
            if(i==start+len-1){                     //如果当前下标到了当前区间的最后一个，意味着区间内的字母仅出现在当前区间
                res.push_back(len);                 //将区间长度添加到答案中
                start+=len;                         //起始位置调整到下一个区间的开头
                len=1;                              //默认下一个区间的长度为1
            }
        }
        return res;
    }
};
```