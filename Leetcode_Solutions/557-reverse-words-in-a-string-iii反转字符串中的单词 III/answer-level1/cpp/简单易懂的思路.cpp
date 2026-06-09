### 解题思路
遍历字符串，若遇到空格，就把之前的单词逐一反转。

### 代码

```cpp
class Solution {
public:
    void reverse(string &s,int l,int r){
        char tmp;
        while(l<r){
            tmp=s[l];
            s[l]=s[r];
            s[r]=tmp;
            l++;
            r--;
        }
    }
    string reverseWords(string s) {
        int start=0;
        for(int i=0;i<s.size();i++){
            if(s[i]==' '){
                reverse(s,start,i-1);
                start=i+1;
            }else if(i==(s.size()-1)){
                reverse(s,start,i);
            }
        }

        return s;
    }
};
```