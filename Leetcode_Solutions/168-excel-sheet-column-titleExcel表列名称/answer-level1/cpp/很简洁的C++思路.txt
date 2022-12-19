### 解题思路
此处撰写解题思路

### 代码

```cpp
class Solution {
public:
    string convertToTitle(int n) {
    string result="";
    while (n) {
        n=n-1;
        char last=char('A'+n%26);
        n=n/26;
        result=last+result;
    }
    return result;
}
};
```