### 解题思路
这道题目非常基础，主要考察判断。如果n偶数就让答案字符串加上一个'a'，再让n减一。然后剩下n-1个为奇数，全部加上'b'就好了。
如果n是奇数，直接加n次'b'就可以。具体看代码吧~

### 代码

```cpp
class Solution {
public:
    string generateTheString(int n) {
        string ans;
        if(n%2==0) ans+='a',n--;
        while(n--) {
            ans+='b';
        }
        return ans;
    }
};
```