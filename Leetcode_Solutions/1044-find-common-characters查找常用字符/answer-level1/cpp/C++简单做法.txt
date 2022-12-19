执行用时 :
12 ms
, 在所有 C++ 提交中击败了
94.64%
的用户
内存消耗 :
9.2 MB
, 在所有 C++ 提交中击败了
98.08%
的用户
```c++ []
class Solution {
public:
    vector<string> commonChars(vector<string>& A) {
        vector<string> ans;
        int count[26];
        //把计数表初始化为最大值
        for(int i=0;i<26;i++)
            count[i]=101;
        //遍历每个字符串的元素
        for(int i=0;i<A.size();i++)
        {
            int word[26]={0};
            for(int j=0;j<A[i].size();j++)
                word[(int)A[i][j]-'a']++;    //记录每个字符串26个字母的出现次数
            for(int i=0;i<26;i++)
                count[i]=min(count[i],word[i]);     //把计数表更新，保留最小的数
        }

        for(int i=0;i<26;i++)
            if(count[i])
                for(int j=0;j<count[i];j++){
                string str;
                str.push_back((char)('a'+i));
                ans.push_back(str);
                }
        return ans;
    }
};
```

