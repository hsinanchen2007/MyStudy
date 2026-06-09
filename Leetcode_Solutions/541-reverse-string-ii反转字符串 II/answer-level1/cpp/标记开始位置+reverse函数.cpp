### 解题思路
通过变量i标记反转开始位置，使用STL的reverse函数完成反转，注意最后是否越界的分类讨论

### 代码

```cpp
class Solution {
public:
    string reverseStr(string s, int k) {
        int i=0;
        while(i<s.size()){ 
            if(i+k<s.size())
                reverse(s.begin()+i,s.begin()+i+k);
            else
                reverse(s.begin()+i,s.end());
            i+=2*k;
        }
        return s;
    }
};
```