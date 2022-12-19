### 解题思路
遍历数组，只需要从0到是s.size()/2即可，然后首尾交换，第二个和倒数第二个交换。。。。遍历完即完成目标。
但是运行时间是真的长。内存消耗击败100%用户。
![image.png](https://pic.leetcode-cn.com/dd6b4821988486121fce778d2e6c2e8af2e0fc8b89cf027a7c09dc3f4e04b2d2-image.png)




### 代码

```cpp
class Solution {
public:
    void reverseString(vector<char>& s) {
        int len=s.size();
        int j=len-1;
        for(int i=0;i<len/2;i++)
        {
           char c;
           c=s[j];
           s[j]=s[i];
           s[i]=c;
           j--;
        }
    }
};
```