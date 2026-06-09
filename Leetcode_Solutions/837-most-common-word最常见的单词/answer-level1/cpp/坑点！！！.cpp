### 解题思路
这类断字符串类型的题目，必须注意最后一个字符处到底是不是字符，若是字符则必须单独拎出来考虑这个情况，若不是字符则不用单独考虑末尾情况

### 代码

```cpp
class Solution {
public:
    string mostCommonWord(string paragraph, vector<string>& banned) {
        for(int i=0;i<paragraph.size();++i)
            if(paragraph[i]>='A'&&paragraph[i]<='Z')
                paragraph[i]+=32;
        map<string,int> ct;
        map<string,int> ban;
        for(int i=0;i<banned.size();++i)
            ban[banned[i]]=1;
        int max1=INT_MIN;string temp1;
        int i=0,pre=0;
        while(i<paragraph.size())
        {
            if(paragraph[i]>'z'||paragraph[i]<'a')
            {
                if(paragraph[pre]>='a'&&paragraph[pre]<='z')
                {
                    string temp2=paragraph.substr(pre,i-pre);
                    if(ban.find(temp2)==ban.end())
                    {
                        if(ct.find(temp2)==ct.end())
                            ct[temp2]=1;
                        else
                        {
                            ++ct[temp2];
                        }
                        if(ct[temp2]>max1)
                        {
                            max1=ct[temp2];
                            temp1=temp2;
                        }
                    }
                    pre=i+1;
                    ++i;
                }
                else
                {
                    pre=i+1;
                    ++i;
                }
            }
            else
                ++i;
        }
        //此题的坑点，
        if(paragraph[paragraph.size()-1]>='a'&&paragraph[paragraph.size()-1]<='z')
        {
            string temp2=paragraph.substr(pre,i-pre);
            if(ban.find(temp2)==ban.end())
            {
                if(ct.find(temp2)==ct.end())
                    ct[temp2]=1;
                else
                {
                    ++ct[temp2];
                }
                if(ct[temp2]>max1)
                {
                    max1=ct[temp2];
                    temp1=temp2;
                }
            }
        }
        return temp1;
    }
};

```