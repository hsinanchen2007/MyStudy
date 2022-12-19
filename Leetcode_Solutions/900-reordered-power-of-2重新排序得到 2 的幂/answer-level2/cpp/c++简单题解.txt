![4_7ZL1O`V9V0WDMZ2YZA16X.png](https://pic.leetcode-cn.com/da4c7c355b505f7893e0a9060e01147a290386a149009068bb95db7481af9b37-4_7ZL1O%60V9V0WDMZ2YZA16X.png)

先找到和N同样长度的2的幂的值，存入temp1,然后比较temp1里面每个数字中0-9的数量和原数字转化为字符之后的0-9数量相比，若全部相同，则可以变为2的幂
比如  46 我们先找到和46一样长度(2)的数字且是2的幂  有16,32,64
然后将这3个数字和46的0-9数字的个数比较 若有相同的 则返回true
否则继续比较 ，比较完了 还没找到 返回false
如果觉得写的还行 麻烦给我点个赞 谢谢各位
```
class Solution {
public:
    bool cmp1(int temp1,vector<int>& temp2)
    {
        vector<int> t1num(10,0);
        string t1str=to_string(temp1);
        for(int i=0;i<t1str.size();i++)
        {
            t1num[t1str[i]-'0']++;
        }
        for(int i=0;i<10;i++)
        {
            if(temp2[i]!=t1num[i])
                return false;
        }
        return true;
    }
    bool reorderedPowerOf2(int N) {
        string temp=to_string(N);
        int num1=pow(10,temp.size()-1);
        int num2=1;
        vector<int> temp1;
        while(num2/num1<=0)
        {
            num2*=2;
        }
        while(num2/num1<=9&&num2/num1>0)
        {
            if(num2==N) return true;
            temp1.push_back(num2);
            //cout<<num2<<endl;
            num2*=2;
        }
        vector<int> temp2(10,0);
        for(int i=0;i<temp.size();i++)
        {
            temp2[temp[i]-'0']++;
        } 
        for(int i=0;i<temp1.size();i++)
        {
            if(cmp1(temp1[i],temp2))
                return true;
        }
        return false;

    }
};
```

