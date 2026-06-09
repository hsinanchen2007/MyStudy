```c++
public:
    string findLongestWord(string s, vector<string>& d) {
        int i,j;
        string The_Whole=s;
        string zichuan;
        string better,best="";
        for(i=0;i<d.size();i++)//遍历字典
        {
            int m=0;
            zichuan=d[i];
            for(j=0;j<s.size();j++){//遍历给定字符串
            if(The_Whole[j]==zichuan[m])
            m++;
            if(m>=zichuan.size())
            {
            better=zichuan;
            if(better.size()>best.size()||(better.size()==best.size()&&better.compare(best)<0))//最优字串选拔条件
            best=better;}
            }
        }
        return best;
    }
```