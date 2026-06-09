### 解题思路
还有比我更快的算法，没理由啊

### 代码

```cpp
class Solution {
public:
    bool isPalindrome(string s) {
        if(!s.size()) return true;
        char *pt1,*pt2;
        pt1 = &s[0];
        pt2 = &s[s.size()-1];
        while(pt1<pt2){
          if( ((*pt1>='0'&& *pt1<='9')||(*pt1>='a'&& *pt1<='z')||(*pt1>='A'&& *pt1<='Z')) && ((*pt2>='0'&& *pt2<='9')||(*pt2>='a'&& *pt2<='z')||(*pt2>='A'&& *pt2<='Z')) ){
              if( *pt1==*pt2 || (*pt1-'a'==*pt2-'A'&&(*pt1>='a'&& *pt1<='z')&&(*pt2>='A'&& *pt2<='Z')) || (*pt1-'A'==*pt2-'a'&&(*pt2>='a'&& *pt2<='z')&&(*pt1>='A'&& *pt1<='Z')) ) {++pt1;--pt2;}
              else return false;
          }
          else if ( !((*pt1>='0'&& *pt1<='9')||(*pt1>='a'&& *pt1<='z')||(*pt1>='A'&& *pt1<='Z')) && !((*pt2>='0'&& *pt2<='9')||(*pt2>='a'&& *pt2<='z')||(*pt2>='A'&& *pt2<='Z')) ){
              ++pt1;--pt2;
          }//0跟P的判断存在问题，因此需要加上它们是字符这一条件
           else if ( !((*pt1>='0'&& *pt1<='9')||(*pt1>='a'&& *pt1<='z')||(*pt1>='A'&& *pt1<='Z')) && ((*pt2>='0'&& *pt2<='9')||(*pt2>='a'&& *pt2<='z')||(*pt2>='A'&& *pt2<='Z')) ){
               ++pt1;
           }
           else if ( ((*pt1>='0'&& *pt1<='9')||(*pt1>='a'&& *pt1<='z')||(*pt1>='A'&& *pt1<='Z')) && ((*pt2>='0'&& *pt2<='9')||!(*pt2>='a'&& *pt2<='z')||(*pt2>='A'&& *pt2<='Z')) ){
               --pt2;
           }
        }
        return true;
    }
};
```