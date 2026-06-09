### 解题思路
第一个方法是自己写的，使用迭代器比较字符是否相等。
第二个方法是解题里的，直接调用了sort为容器中的数据排序，只需要比较第一个字符串和最后一个字符串。第一个字符串和第二个字符串都有的子字符串中间的字符串必定也有。  
如：abcc, abcd, abd, acc,  共有前缀是a

### 代码

```cpp
class Solution {
public:

    // 执行用时 :8 ms, 在所有 C++ 提交中击败了59.40% 的用户
    // 内存消耗 :6.8 MB, 在所有 C++ 提交中击败了100.00%的用户
    string longestCommonPrefix(vector<string>& strs) {
        if(strs.size()<1) return "";
        string res = strs[0];
        int index = 0;
        for(int i = 1;i<strs.size();++i){
            string::iterator iter1 = res.begin();
            string::iterator iter2 = strs[i].begin();
            while(iter1!=res.end()&&iter2!=strs[i].end()&&*iter1==*iter2){
                ++index;
                ++iter1;
                ++iter2;
            }
            if(index==0){
                return "";
            }
            res = res.substr(0,index);
            index = 0;
        }
        return res;
    }

    // 执行用时 :4 ms, 在所有 C++ 提交中击败了93.59% 的用户
    // 内存消耗 :6.8 MB, 在所有 C++ 提交中击败了100.00%的用户
    string longestCommonPrefix(vector<string>& strs) {
        if(strs.size()==0) return "";
        if(strs.size()==1) return strs[0];
        sort(strs.begin(), strs.end());//为容器中的数据排序。
        for(int i = 0;i<min(strs[0].size(), strs[strs.size()-1].size());++i){
            if(strs[0][i]!=strs[strs.size()-1][i]){
                strs[0] = strs[0].substr(0,i);//仅保留相同的数据，
            }
        }
        return strs[0].size()>strs[strs.size()-1].size() ? strs[strs.size()-1] : strs[0];//最后一个数据可能比第一个数据短，
    }
};
```