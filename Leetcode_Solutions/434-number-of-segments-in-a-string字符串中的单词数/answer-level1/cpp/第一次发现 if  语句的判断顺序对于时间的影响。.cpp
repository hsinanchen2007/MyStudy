### 解题思路
此处撰写解题思路

### 代码

```cpp
class Solution {
public:
    int countSegments(string s) {
        int length=s.length();
        if(length==0) return 0;
        int count=0;
        int start=0;
        for(start;start<length-1;start++){
            if(s[start+1]==' '&& s[start]!=' ' ){ //尝试将两个语句对调，时间有非常大的区别。
                count++; 
            }
        }
        return s[length-1]!=' '?count+1:count; 
    }
};
```