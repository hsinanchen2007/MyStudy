
```
class Solution {
```
```
public:
    vector<string> commonChars(vector<string>& A) {
        int temp[101][26]={0};
//统计字符
        for(int i=0;i<A.size();i++)
        {
            for(int j=0;j<A[i].size();j++)
            {
                temp[i][A[i][j]-'a']++;
            }
        }
//计算共有的字符及个数
        for(int i=0;i<26;i++)
        {
            int k=temp[0][i];
            for(int j=1;j<A.size();j++)
                k=min(k,temp[j][i]);
            temp[100][i]=k;
        }
//将字符写入答案数组
        vector<string> x;
        for(int i=0;i<26;i++)
        {
            string s(1,'a'+i);
            x.insert(x.begin(),temp[100][i],s);//不要用y=x.beging()代替insert中的x.begin()
        }
        return x;
    }
};
注：向一个vector,string 或 deque插入元素会使所有指向容器的迭代器,引用和指针失效