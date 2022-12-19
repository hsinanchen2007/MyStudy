利用字符串和哈希表的基本操作。
周一至周五的题目似乎都简单一些。
```
class Solution {
public:
    int countCharacters(vector<string>& words, string chars) {
        map<char,int> m,m_tmp;
        for(char c:chars){
            ++m[c];
        }
        int sum=0;
        for(string s:words){
            m_tmp=m;
            int cnt=0;
            for(char c:s){
                if(m_tmp.find(c)!=m_tmp.end() && m_tmp[c]){
                    ++cnt;
                    --m_tmp[c];
                }
                else{
                    cnt=0;
                    break;
                }
            }
            sum+=cnt;
        }
        return sum;
    }
};
```
