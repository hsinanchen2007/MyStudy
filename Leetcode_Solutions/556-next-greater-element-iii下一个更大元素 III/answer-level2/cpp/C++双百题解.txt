### 解题思路
![无标题.jpg](https://pic.leetcode-cn.com/1c330dce72cb65d61a25b25bd3d7592b91a47a70411ce1ddf3ce90321b00621e-%E6%97%A0%E6%A0%87%E9%A2%98.jpg)
与实现next_permutation的题目类似，需要考虑结果会不会超过INT_MAX.

### 代码

```cpp
class Solution 
{
public:
    int nextGreaterElement(int n) 
    {
        string s=to_string(n);
        for(int i=s.size()-1;i>=0;i--)
        {
            if(i==0)
                return -1;
            if(s[i-1]<s[i])
            {
                sort(s.begin()+i,s.end());
                for(int j=i;j<s.size();j++)
                {
                    if(s[i-1]<s[j])
                    {
                        swap(s[i-1],s[j]);
                        if(stol(s)>INT_MAX)
                            return -1;
                        return stoi(s);
                    }
                }
            }
        }
        return -1;
    }
};
```