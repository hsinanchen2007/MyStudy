### 解题思路
此处撰写解题思路

### 代码

```cpp
class Solution {
public:
    int numDecodings(string s) {
        //每存在一个只有“1”、“2”构成的连续子串，解码总数res*=连续子串len对应的斐波那契数（len需要根据子串后的数字-1或-2）
        if(s.size()==0||s[0]=='0')
        return 0;
        vector<int> fi;

        //正常斐波那契数组为{1，1，2，3……}，我用的{1，2，3……}。所以处理子串后为0时需要避免数组下标取-1
        fi.push_back(1);
        fi.push_back(2);
        int i;
        for(i=2;i<45;i++)
        {
            fi.push_back(fi[i-1]+fi[i-2]);
        }
        int res=1;
        for(i=0;i<s.size();i++)
        {
            //0前必须为1，2
            if(s[i]=='0'&&(s[i-1]!='1'&&s[i-1]!='2'))
            return 0;

            //处理连续含1，2子串
            if(s[i]=='1'||s[i]=='2')
            {
                int len=0;
                int j;
                for(j=i+1;j<s.size();j++)
                {
                    if(s[j]!='1'&&s[j]!='2')
                    {
                        break;
                    }
                }
                len=j-i;

                //处理子串长度
                //子串后没有数据或末尾为2，下一位>6,len-1
                //子串后为0,len-2.
                if(j>=s.size()||(s[j-1]=='2'&&s[j]>'6')||s[j]=='0')
                {
                    --len;
                }
                if(len>0&&s[j]=='0')
                {
                    --len;
                }
                res*=fi[len];
                cout<<res<<" "<<j<<endl;
                i=j;
            }
        }
        return res;
    }
};
```