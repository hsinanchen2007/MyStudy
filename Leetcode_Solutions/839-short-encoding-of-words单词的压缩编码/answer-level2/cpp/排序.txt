### 解题思路
排序，按照字符串长度进行降序排序，然后从后向前查找子字符串的存在，如果有并且正好是在最后面，那么就不加这个字符串的长度。时间复杂度有点高了，现在滚去学习一下字典序。。。

### 代码

```cpp
class Solution {
public:
    int minimumLengthEncoding(vector<string>& words) {
        int res=0;
        if(words.empty()) return 0;
        sort(words.begin(),words.end(),cmp);
        res+=words[0].size()+1;
        for(int i=1;i<words.size();i++){
            int flag=0;
            for(int j=0;j<i;j++){
                size_t it = words[j].rfind(words[i]);
                if(it==string::npos) continue;
                else if(it+words[i].length()==words[j].length()){
                    flag=1;
                    break;
                }
                else continue;
            }
            if(!flag){
                res+=words[i].size();
                res++;
            }
        }
        return res;
    }

    static bool cmp(string& a, string& b){
        return(a.length()>b.length());
    }
};
```