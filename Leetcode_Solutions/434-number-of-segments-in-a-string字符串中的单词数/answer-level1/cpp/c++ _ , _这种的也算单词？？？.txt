### 解题思路
"  ,  "这种的也算单词，工作量下降了好多

### 代码

```cpp
class Solution {
public:
    int countSegments(string s) {
        istringstream ss(s);
        string temp;
        int num=0;
        while(ss>>temp)
        {
            num++;
        }
        return num;
    }
};
```