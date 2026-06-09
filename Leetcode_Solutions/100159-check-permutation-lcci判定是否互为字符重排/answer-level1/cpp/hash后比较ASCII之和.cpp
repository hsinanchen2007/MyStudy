### 解题思路
构造一个hash函数，计算每个字符的值
判断两个字符是否相同
可能取巧，可能hash 值会冲突
### 代码

```cpp
class Solution {
public:
    bool CheckPermutation(string s1, string s2) {
        if(s1.size()!=s2.size()) return false;
       int sum=0;
        for(int i=0;i<s1.size();++i){
            sum+=hash(s1[i]);
            sum-=hash(s2[i]);
        }
        if(!sum) return true;
        return false;
    }
    
    int hash(char a){
        return a/2+4+a;
    }
};
```