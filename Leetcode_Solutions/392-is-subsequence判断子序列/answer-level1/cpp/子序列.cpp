### 解题思路
题目是一个比较经典的问题，判断子序列
一开始想到哈希，但是序列的顺序保证不了
1，就直接暴力，外循环是扫描短串，内循环是比较字符和长串中的字符异同。时间复杂度在O(strlen(A)*strlen(B))
2，也想到了动态规划，但实现方面开始无从下手。
3,双指针法，最坏情况是O(strlen(t))


### 代码

```cpp
class Solution {
public:
    bool isSubsequence(string s, string t) {
        bool flag=false;
        int nextj=0;
        for(int i=0;i<s.size();i++){
              int j;
               for(j=nextj;j<t.size();j++){
                      if(s[i]==t[j]){
                          flag=true;
                          break;
                      }

               }
               
               if(flag){
                   nextj=j+1;
                   flag=false;
               }else{
                   return false;
               }


        }
        return true;
    }
};

```
双指针法
class Solution {
public:
    bool isSubsequence(string s, string t) {
        int i=0,j=0;
        while(i<s.size()&&j<t.size()){
            if(s[i]==t[j]){
                i++;
                j++;
            }else{
                j++;
            }
        }
        if(i==s.size()) return true;
        else return false;
    }
};