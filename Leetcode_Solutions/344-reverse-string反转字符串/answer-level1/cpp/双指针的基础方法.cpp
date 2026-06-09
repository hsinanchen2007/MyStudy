### 解题思路
首尾left和right两个指针，如果left<right，就交换，left++，right++

### 代码

```cpp
class Solution {
public:
    void reverseString(vector<char>& s) {
        char tmp;
        int left=0,right=s.size()-1;
        while(left<right){
            tmp = s[left];
            s[left] = s[right];
            s[right] = tmp;
            left++;
            right--;
        }
    }
};
```