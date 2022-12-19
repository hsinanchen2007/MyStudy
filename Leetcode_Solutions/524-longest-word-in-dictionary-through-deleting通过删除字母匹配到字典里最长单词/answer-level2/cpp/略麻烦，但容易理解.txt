### 解题思路
index存储符合条件的所有字符串的索引，然后按字典序进行排序，在找出最长的字符串
### 代码

```cpp
class Solution {
public:
    string findLongestWord(string s, vector<string>& d) {
		vector<int> index;
		for (int i = 0; i < d.size(); i++)
		{
			if (isSubstring(s, d[i]))
				index.push_back(i);
		}
		if (index.empty()) return "";
        //排序
        for(int i=0;i<index.size();i++)
        {
            for(int j=i+1;j<index.size();j++)
            {
                if(d[index[i]]>d[index[j]])
                swap(d[index[i]],d[index[j]]);

            }
        }
        //找出最长的第一个索引
        size_t maxIndex = index[0];
		for (int i = 0; i < index.size(); i++)
		{
			if (d[maxIndex].size() < d[index[i]].size())
				maxIndex = index[i];
		}
		return d[maxIndex];
	}
private:
bool isSubstring(string s1,string s2)
{
    int i=0,j=0;
    while(i<s1.size()&&j<s2.size())
    {
        if(s1[i]==s2[j])
        {
            i++;
            j++;
        }
        else i++;
    }
    if(j==s2.size())
    return true;
    else
    return false;
}

void swap(string &t1,string &t2)
{
    string tmp=t1;
    t1=t2;
    t2=tmp;
}
};
```