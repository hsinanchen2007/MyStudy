### 解题思路
**方法：反转加排序**
如果 t 是 s 的后缀，那么反转之后 t’ 就是 s’ 的前缀。
在反转+排序之后，s’ 一定紧跟在 t’ 的后面！

这样我们可以检查排序后的每一个单词，如果当前单词是下一个单词的前缀，则将单词丢弃

### 代码

```cpp
class Solution {
public:
    int minimumLengthEncoding(vector<string>& words) {
        vector<string> reverses;
        for(auto i:words){
            reverse(i.begin(),i.end());
            reverses.push_back(i);
        }

        sort(reverses.begin(),reverses.end());
        int res=0;
        for(int i=0;i<words.size();i++){
            if(i+1<words.size() && reverses[i+1].find(reverses[i])==0 ){

            }
            else{
                res += reverses[i].length()+1;
            }
        }

        return res;
    }
};
```