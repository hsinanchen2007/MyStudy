执行结果：
通过
显示详情
执行用时 :0 ms, 在所有 C++ 提交中击败了100.00% 的用户
内存消耗 :8.7 MB, 在所有 C++ 提交中击败了17.35%的用户
bool wordPattern(string pattern, string str) 
{
	 	vector<string> lis1;
        int pos;
        int i=0;
        while(pos!=-1)
        {
            pos=str.find_first_of(' ',i);
            string temp=str.substr(i,pos-i);
            lis1.push_back(temp);
            i=pos+1;
        }
        if(pattern.size()!=lis1.size()) return false;
        map<char,string> s;
        map<string,char> s1;
        for(int i=0;i<lis1.size();i++)
        {
            if(s.find(pattern[i])!=s.end())
            {
                if(s[pattern[i]]!=lis1[i])
                    return false;
            }
            else 
            {
            	s[pattern[i]]=lis1[i];
            }
            if(s1.find(lis1[i])!=s1.end())
            {
                if(s1[lis1[i]]!=pattern[i])
                    return false;
            }
            else 
            {
            	s1[lis1[i]]=pattern[i];
            }
		}
		return true;
}