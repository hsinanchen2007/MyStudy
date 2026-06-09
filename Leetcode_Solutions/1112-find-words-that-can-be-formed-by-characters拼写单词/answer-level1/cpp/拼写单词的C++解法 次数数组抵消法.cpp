### 解题思路
![image.png](https://pic.leetcode-cn.com/0910ab9d51763498a5d1c7632c40877f2f23324dd945a4044ec6b2d9e09f42c5-image.png)
首先用一个长度为26的int数组保存各个字母在chars中出现的次数，然后逐个遍历，遇到大于1的字母，就在次数数组中相应的减一。
直到遍历到次数为0的字母，这表明在字母表中没有这个字母，或者已经被抵消完了，那么就break，跳过这个单词的遍历。
成功遍历完一整个单词的字符即视为正确
### 代码

```cpp
class Solution {
public:
    int countCharacters(vector<string>& words, string chars) {
        int res=0;
        vector<int> ch(26,0);
        for(int i=0;i<chars.size();i++) ch[chars[i]-'a']++;//保存各个字母次数数组
        vector<int> tmp;//临时数组
        int j;
        for(int i=0;i<words.size();i++)
        {
            tmp=ch;
            for(j=0;j<words[i].size();j++)
            {   
                if(tmp[words[i][j]-'a']>0) tmp[words[i][j]-'a']--;//次数不为0，减一，抵消
                else break;//次数为0，则退出
            }
            if(j==words[i].size()) res+=words[i].size();//遍历完全，添加到结果
        }
        return res;
    }
};
```