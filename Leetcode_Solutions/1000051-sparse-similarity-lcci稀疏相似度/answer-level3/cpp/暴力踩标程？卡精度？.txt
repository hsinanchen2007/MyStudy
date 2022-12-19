# 解法一：
暴力枚举，O(len)判断两数组相同元素个数，具体做法就是双指针，就是合并两个有序数组的思想。
时间复杂度**O(n^2*len)**，由于只有枚举，所以其实常数小，跑的飞快
# 解法二：
对每个出现的值v记录下含有v的行的编号集合s[v]，再扫描每个出现的值，这样其s[v]中任意两编号就是相似度不为0的一对，每一对只统计一次，对每一对计算答案时间依然是O(len)。分析一波，我们扫描到的都是相似度不为0的对，题目约定最多1000对，然后每一对最多被扫到O(len)次，每一对答案计算时间是O(len)，所以最终的时间复杂度是**O(1000*len)**
不过由于常数问题，并没有快很多。
这题还有另一个难点，就是小数转字符串时，要注意模拟保留精度的过程，手动进位。
```
class Solution {
    const double eps=1e-12;
    map<int,vector<int> > A;
    map<pair<int,int>,bool> Mark;
    vector<string> Ans;
    void Put(int a,int b,vector<vector<int> > &v)
    {
        int s=0;
        int n=v[a].size();
        int m=v[b].size();
        if (!n || !m) return ;
        for (int i=0,j=0;i<n && j<m;)
            if (v[a][i]==v[b][j]) ++s,++i,++j;
            else if (v[a][i]<v[b][j]) ++i;
            else ++j;
        if (!s) return ;
        double ans=1.0*s/(n+m-s);
        //printf("%d %d %.4lf\n",a,b,ans);
        string ss;
        string aa;
        if (!a) aa="0";
        else
        {
            while (a)
            {
                aa.push_back('0'+a%10);
                a/=10;
            }
        }
        reverse(aa.begin(),aa.end());
        ss=aa;
        aa.clear();
        if (!b) aa="0";
        else
        {
            while (b)
            {
                aa.push_back('0'+b%10);
                b/=10;
            }
        }
        reverse(aa.begin(),aa.end());
        ss.push_back(',');
        ss+=aa;
        ss+=": ";
        int vv=ans;
        double vvv=ans-vv;
        aa.clear();
        if (!vv) aa="0";
        else
        {
            while (vv)
            {
                aa.push_back('0'+vv%10);
                vv/=10;
            }
        }
        reverse(aa.begin(),aa.end());
        ss+=aa;
        ss.push_back('.');
        vvv*=10000;
        int vvvv=vvv;
        vvv*=10;
        int t=vvv;
        vvv-=t;
        t%=10;
        vvv-=t;
        if (t>5) ++vvvv;
        else if (t==5)
        {
            if (vvvv>eps) ++vvvv;
        }
        aa.clear();
        for (int i=1;i<=4;++i)
        {
            aa.push_back(vvvv%10+'0');
            vvvv/=10;
        }
        reverse(aa.begin(),aa.end());
        ss+=aa;
        Ans.push_back(ss);
    }
public:
    vector<string> computeSimilarities(vector<vector<int>>& docs) {
        int n=docs.size();
        for (int i=0;i<n;++i) sort(docs[i].begin(),docs[i].end());
        /*暴力的部分
        for (int i=0;i<n;++i)
            for (int j=i+1;j<n;++j)
                Put(i,j,docs);
        */
        for (int i=0;i<n;++i)
        {
            int m=docs[i].size();
            for (int j=0;j<m;++j) A[docs[i][j]].push_back(i);
        }
        vector<int> s;
        for (auto it:A)
        {
            s=it.second;
            int mm=s.size();
            for (int i=0;i<mm;++i)
                for (int j=i+1;j<mm;++j)
                {
                    pair<int,int> v=make_pair(s[i],s[j]);
                    if (!Mark[v])
                    {
                        Put(s[i],s[j],docs);
                        Mark[v]=true;
                    }
                }
        }
        return Ans;
    }
};
```
