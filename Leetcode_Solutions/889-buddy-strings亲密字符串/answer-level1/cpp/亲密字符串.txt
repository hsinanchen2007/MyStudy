### 解题思路
这是我对一位大佬写的题解的理解，望各位指教！！！谢谢

### 代码

```cpp
class Solution {
public:
    bool buddyStrings(string A, string B) {
        if(A.size() != B.size())
            return false;
        //若两字符串长度不一样则首先被排除
        //统计不同的字母的个数   0 或者 2
      //0必须使得A为重复字符，由两个及两个以上的相同字母组成
        vector<int> index;//记录下标
        for(int i=0;i<A.size();i++){
            if(A[i] != B[i]){
                index.push_back(i);
                if(2<index.size())    return false;
            }
        }
        if(index.size()==0){
    return set<char>(A.begin(),A.end()).size()<A.size();//set集合能够筛选出相同还是不相同
        }else if(index.size()==2){
            return A[index[0]]==B[index[1]] &&
                     A[index[1]]==B[index[0]];
        }
        return false;
    }
};
```