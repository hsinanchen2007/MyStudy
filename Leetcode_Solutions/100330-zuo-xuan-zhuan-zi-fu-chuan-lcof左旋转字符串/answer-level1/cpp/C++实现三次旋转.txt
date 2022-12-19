### 解题思路
1、分为两个区间，分别旋转
2、整体旋转
### 代码

```cpp
class Solution {
public:
    string reverseLeftWords(string s, int n) {
        if(s.size()==0||n>s.size()||n<0) return "";//不正确的输入
        reverse(s,0,n-1);
        reverse(s,n,s.size()-1);
        reverse(s,0,s.size()-1);
        return s;


    }
    void reverse(string& s,int begin,int end)//定义交换函数
    {
        while(begin<end){
        char p=s[begin];
        s[begin]=s[end];
        s[end]=p;
        begin++;end--;}
    }


    
};
```