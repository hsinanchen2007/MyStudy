### 解题思路


### 代码

```cpp
class Solution {
public:
string convert(string s, int numRows) {
    string ans = "";
    if(s == "")
        return ans;
    if(numRows == 1)
        return s;
    if(numRows == 2)
    {
        for(int i = 0 ; i < s.length() ; i += 2)
            ans += s[i];
        for(int i = 1 ; i < s.length() ; i += 2)
            ans += s[i];
        return ans;
    }
    if(numRows == s.length())
        return s;
    int vsize = 0;
    int size = s.length();
    char v[size][numRows];
    int flag = 1;
    int cnt = 0;
    for(int i = 0 ; i < s.length() ; ++i)
    {
        if(flag > 0)    //如果在处理Z的两边部分
        {
            if(cnt >= 0 && cnt < numRows)   //直接存入
                v[vsize][cnt++] = s[i];
            //cout<<"a "<<s[i]<<endl;
            if(cnt == numRows || i == s.length() - 1)   //如果到了中间部分或者读完
            {
                //cout<<"a "<<s[i]<<endl;
                if(i == s.length() - 1)
                {
                    for(; cnt < numRows; ++cnt)
                        v[vsize][cnt] = ' ';    //补全空字符
                    cnt++;
                }
                vsize++;
                flag = -flag;   //转到处理中间部分
                cnt--;
            }
        }
        else    //如果在处理z的中间部分
        {
            if(cnt == 0 || cnt == numRows - 1)  //如果是没有字符的部分
            {
                v[vsize][cnt--] = ' ';
                i--;
            }
            else if(cnt > 0 && cnt < numRows - 1)
            {
                v[vsize][cnt--] = s[i];
                //cout<<"b "<<s[i]<<endl;
            }
            if(cnt == -1 || i == s.length() - 1)
            {
                //cout<<"b "<<s[i]<<endl;
                if(i == s.length() - 1)
                {
                    for(; cnt >= 0; --cnt)
                        v[vsize][cnt] = ' ';
                    cnt--;
                }
                vsize++;
                flag = -flag;
                cnt++;
            }
        }
    }
    for(int i = 0 ; i < numRows ; ++i)
    {
        for(int j = 0 ; j < vsize ; ++j)
        {
            //cout<<v[j][i]<<endl;
            if(v[j][i] == ' ')
                continue;
            ans += v[j][i];
        }
    }
    return ans;
}
};
```