### 解题思路
思路和官方题解相同，这个是c++版本
下面是官方题解
比较相同字母组的长度：
我们首先将 S 拆分成若干组相同的字母，并存储每组字母的长度。例如当 S 为 abbcccddddaaaaa 时，可以得到 5 组字母，它们分别为 abcda，长度为 [1, 2, 3, 4, 5]。

对于 words 中的每个单词 word，如果它可以扩张得到 S，那么它必须和 S 有相同的字母组。对于每一组字母，假设 S 中有 c1 个，word 中有 c2 个，那么会有下面几种情况：

如果 c1 < c2，那么 word 不能扩张得到 S；

如果 c1 >= 3，那么只要添加 c1 - c2 个字母即可；

如果 c1 < 3，由于在扩张时至少需要添加到 3 个字母，所以此时不能添加字母，必须有 c1 == c2。

如果 word 的包含的字母组中的每个字母都满足上述情况，那么 word 可以扩张得到 S。

### 代码

```cpp
class Solution {
public:
    struct node{
        string s;
        vector<int>count;
    };
    node fenjie(string str){
        node tmp;
        int cnt=1;
        char c=str[0];
        for(int i=1;i<str.size();i++){
            if(str[i]==c) cnt++;
            else {
                tmp.s+=c;
                tmp.count.push_back(cnt);
                cnt=1;c=str[i];
            }
        }
        tmp.s+=c;
        tmp.count.push_back(cnt);
        return tmp;
    }
    int expressiveWords(string S, vector<string>& words) {
        if(S.size()==0||words.size()==0) return 0;
        node n=fenjie(S);
        int res=0,i,j;
        for(i=0;i<words.size();i++){
            if(words[i].size()==0) continue;
            node tmp=fenjie(words[i]);
            if(tmp.s!=n.s) continue;
            for(j=0;j<n.count.size();j++){
                if (n.count[j]<3 && n.count[j] != tmp.count[j] || n.count[j] < tmp.count[j])
                    break;
            }
            if(j==n.count.size()) res++;
        }
        return res;
    }
};
```