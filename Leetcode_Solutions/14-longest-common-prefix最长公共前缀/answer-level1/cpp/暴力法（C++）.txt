### 解题思路
将第一项放入result中，接着for循环strs，设置一个temp，每次遍历result，如果不同，更新result=temp，跳出。最后return result。
PS：开头不要忘了判断strs为NULL的情况，不然时间很难看

### 代码

```cpp
class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        if(strs.size()==0) return "";
        string result=strs.size()?strs[0]:"";
        int len,tgm;
        string tempRe;
        for(auto &s:strs){
            len=result.size();
            tgm=0;
            tempRe="";
            while(tgm<len){
                if(result[tgm]==s[tgm]){
                    tempRe+=result[tgm];
                    tgm++;
                }
                else {
                    result=tempRe;
                    break;
                }
            }
        }
        return result;
    }
};
```