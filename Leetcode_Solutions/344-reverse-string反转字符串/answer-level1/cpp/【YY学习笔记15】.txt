### 解题思路
把数组前一半的元素与后一半的元素换位置。

### 代码

```cpp
class Solution {
public:
    void reverseString(vector<char>& s) {
        int tmp;
        for(int i=0;i<s.size()/2;i++){
            tmp=s[i];
            s[i]=s[s.size()-i-1];
            s[s.size()-i-1]=tmp;
        }
    }
};
```