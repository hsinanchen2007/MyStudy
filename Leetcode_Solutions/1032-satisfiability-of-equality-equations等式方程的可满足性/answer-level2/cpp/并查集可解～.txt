### 解题思路
简单的并查集题目，对相等的字符全部进行一个合并操作，合并完之后就对不想等的字符进行判断，若已经在集合之中就直接返回错误～～～

### 代码

```cpp
class Solution {
public:
    int find(vector<int>& cha,int x)
    {
        int i=x;
        while(x!=cha[x])
            x=cha[x];
        while(i!=cha[i])
        {
            int temp=i;
            i=cha[i];
            cha[temp]=x;
        }
        return x;
    }
    void union_1(vector<int>& cha,int x,int y)
    {
        int x1=find(cha,x);
        int y1=find(cha,y);
        if(x1!=y1)
            cha[y1]=x1;
    }
    bool equationsPossible(vector<string>& equations) {
        vector<int> cha(26,0);int count=0;
        map<char,int> mp;
        for(int i=0;i<26;++i)
            cha[i]=i;
        for(int i=0;i<equations.size();++i)
        {
            if(equations[i][1]=='='&&equations[i][2]=='=')
            {
                char l=equations[i][0],r=equations[i][3];
                if(mp.find(l)==mp.end()) mp[l]=count++;
                if(mp.find(r)==mp.end()) mp[r]=count++;
                union_1(cha,mp[l],mp[r]);
            }
        }
        for(int i=0;i<count;++i)
            find(cha,i);
        for(int i=0;i<equations.size();++i)
        {
            if(equations[i][1]=='!'&&equations[i][2]=='=')
            {
                char l=equations[i][0],r=equations[i][3];
                if(mp.find(l)==mp.end()) mp[l]=count++;
                if(mp.find(r)==mp.end()) mp[r]=count++;
                int x1=find(cha,mp[l]);int y1=find(cha,mp[r]);
                if(x1==y1) return 0;
            }
        }
        return 1;
    }
};
```