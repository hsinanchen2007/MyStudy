### 解题思路
创建一个数组，初始化为0；以字符的ASCII码为下标。可以统计出相同字符的个数，一旦出现相同字符大于
1就直接返回false.

### 代码

```cpp
class Solution {
public:
    bool isUnique(string astr) {
        int a[200]={0};
        for(int i=0;i<astr.size();i++)
        {
            a[(int)astr[i]]++;
        }
        for(int i=0;i<200;i++)
        {
            if(a[i]>1)
            return false;
        }
        return true;
    }
};
```