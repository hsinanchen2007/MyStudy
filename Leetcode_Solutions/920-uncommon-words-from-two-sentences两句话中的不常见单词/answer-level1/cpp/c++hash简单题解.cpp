![3YK\]6@SO32`AFCX`Q_LTHBV.png](https://pic.leetcode-cn.com/f5eff06143599cbee63acad2bfda3a0eb9a0a65422f71c2b904d06f59356a17d-3YK%5D6@SO32%60AFCX%60Q_LTHBV.png)

有一个hash表存储A,B字符串中的单词的个数信息，个数为1，则存入结果
```
class Solution {
public:
    vector<string> uncommonFromSentences(string A, string B) {
        vector<string>  res;
        unordered_map<string,int>   temp;
        int i=0;
        while(i<A.size())
        {
            string temp1;
            while(i<A.size()&&A[i]!=' ')
            {
                temp1+=A[i];
                i++;
            }
            //cout<<temp1<<endl;
            i++;
            if(temp1!="")
            {
                if(temp[temp1])
                    temp[temp1]++;
                else temp[temp1]=1;
            }
        }
        i=0;
        while(i<B.size())
        {
            string temp1;
            while(i<B.size()&&B[i]!=' ')
            {
                temp1+=B[i];
                i++;
            }
            //cout<<temp1<<endl;
            i++;
            if(temp1!="")
            {
                if(temp[temp1])
                    temp[temp1]++;
                else temp[temp1]=1;
            }
        }
        for(auto i=temp.begin();i!=temp.end();i++)
        {
            if(i->second==1)
                res.push_back(i->first);
        }
        return res;
    }
};
```
