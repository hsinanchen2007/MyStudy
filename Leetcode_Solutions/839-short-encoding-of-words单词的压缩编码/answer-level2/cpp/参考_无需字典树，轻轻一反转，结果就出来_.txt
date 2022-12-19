### 解题思路
参考"https://leetcode-cn.com/problems/short-encoding-of-words/solution/wu-xu-zi-dian-shu-qing-qing-yi-fan-zhuan-jie-guo-j/"

### 代码

```cpp
class Solution {
public:
    int minimumLengthEncoding(vector<string>& words) {
        //本题如果words中某个单词a是另一个单词b的后缀,那么a不用额外单独编码
        //直接合并到b中,再用一个#标识就行
        //注意必须是后缀,仅仅是出现在中间是不行的,比如time和im就无法合并编码,而只能表示成"time#im#"
        int len = words.size();
        vector<string> reverse_words;
        for(int i=0;i<len;i++)
        {
            reverse(words[i].begin(),words[i].end());
            reverse_words.push_back(words[i]);
        }
        //如果a是b的后缀,那么翻转后,a'就是b'的前缀,那么按照字典排序后,a',b'是相邻的,且a'在b'的前面
        sort(reverse_words.begin(),reverse_words.end());

        int result=0;
        for(int i=0;i<len;i++)
        {
            //reverse_words[i]是reverse_words[i+1]的前缀,不用处理
            if(i<len-1 && reverse_words[i+1].find(reverse_words[i])==0)
                continue;
            result+=reverse_words[i].length()+1;//+1是添加'#'
        }
        return result;
    }
};
```