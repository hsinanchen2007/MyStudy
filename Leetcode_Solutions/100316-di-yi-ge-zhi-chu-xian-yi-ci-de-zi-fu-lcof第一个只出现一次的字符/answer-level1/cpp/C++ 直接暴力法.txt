```
代码块
class Solution {
public:
    char firstUniqChar(string s) {
        char ans=NULL;
        char curr;
        int len =s.size();
        for(int i=0;i<len;i++)
        {
            curr=s[i];//选定一个比较字符
            ans=s[i];//假设
            for(int j=0;j<len;j++)
            {
                if(j!=i&&s[j]==curr) {ans=NULL; break; } //轮流与除自己以外的元素比较
            }
            if(ans!=NULL) break;//如果ans假设成功，直接跳出循环
        }
        if(ans==NULL) return ' ';
            return ans;
    }
};
```
