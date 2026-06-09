扫一遍集合，记录word1和word2上一次出现位置，扫到word1或者word2时更新答案。
时间复杂度：O（n） 空间复杂度：O（1）
```
class Solution {
    const int INF=(1LL<<31)-1;
public:
    int findClosest(vector<string>& words, string word1, string word2) {
        int n=words.size();
        int Ans=INF;
        int a=-1,b=-1;
        for (int i=0;i<n;++i)
        {
            if (words[i]==word1)
            {
                a=i;
                if (b!=-1) Ans=min(Ans,a-b);
            }
            else if (words[i]==word2)
            {
                b=i;
                if (a!=-1) Ans=min(Ans,b-a);
            }
        }
        return Ans;
    }
};
```
