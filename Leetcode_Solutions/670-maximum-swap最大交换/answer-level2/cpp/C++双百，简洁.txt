### 解题思路
将数字转化为字符串然后降序排列，然后得到交换的最大数字，因为题目只能交换一次，所以只改变第一个与降序不同的字符为降序排列中的字符
还要注意的是重复的字符应该取最后一个，如63424->64423而不是64324

### 代码

```cpp
class Solution {
public:
    int maximumSwap(int num) {
        string str=to_string(num),tp=str;
        sort(tp.rbegin(),tp.rend());
        for(int i=0;i<str.size();i++){
            if(tp[i]!=str[i]){
                int mark=0;
                for(int j=i+1;j<str.size();j++)
                    if(str[j]==tp[i])mark=j;
                    swap(str[i],str[mark]);
                    break;
            }
        }
        return stoi(str);
    }
};
```