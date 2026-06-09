### 解题思路
直接在容器内操作。
一开始定义一个大小为2、均值为0的vector容器v。
遍历S每个字母，将字母占用单位累加到v[1]，当v[1]>100证明这一行的字母占用超标了要换到下一行，所以v[0]++代表行数加一，同时因为当前值使得上一行超标，v[1]值变成当前字母的值，然后继续遍历。最后v[0]++把最后一行加上去就完事儿了。

### 代码

```cpp
class Solution {
public:
    vector<int> numberOfLines(vector<int>& widths, string S) {
        
        vector<int> v(2,0);
        
        for(int i=0;i<S.size();i++)
        {
            v[1]+=widths[S[i]-'a'];
            if(v[1]>100)
            {
                v[0]++;
                v[1]=widths[S[i]-'a'];
            }
        }
        
        v[0]++;
        
        return v;

    }
};
```