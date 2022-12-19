### 解题思路
此处撰写解题思路

### 代码

```cpp
class Solution {
public:
    void reverseString(vector<char>& s) {
        int left=0;
        int right=s.size()-1;
        while(left<right){
            char t=s[left];
            s[left]=s[right];
            s[right]=t;
            left++;right--;
        }
        return;
    }
};
```