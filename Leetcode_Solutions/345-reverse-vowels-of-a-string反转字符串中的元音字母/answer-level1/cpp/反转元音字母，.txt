### 解题思路
双指针+循环判断。
注意数组越界，会报线程错误 thread

### 代码

```cpp
class Solution {
public:
    string reverseVowels(string s) {
        int p1=0,p2=s.size()-1;
        char temp;
        while(p1<p2){
            while(p1<s.size()&&!judge(s[p1])) ++p1;
            while(p2>=0&&!judge(s[p2])) --p2;
           // swap(s[p1],s[p2]);
           if(p1>=p2) break;
          // if(p1>=s.size()||p2<0) break;
            temp=s[p1];
            s[p1]=s[p2];
            s[p2]=temp;
            ++p1;
            --p2;

        }
        return s;
        
    }
    bool judge(char ch){
        if(ch=='a'||ch=='A'||ch=='o'||ch=='O'||ch=='e'||ch=='E'||ch=='i'||ch=='I'||ch=='u'||ch=='U') return true;
        else return false;
    }
};
```