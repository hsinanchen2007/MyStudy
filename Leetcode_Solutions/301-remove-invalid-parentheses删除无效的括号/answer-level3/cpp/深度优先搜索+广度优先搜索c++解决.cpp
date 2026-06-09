
```
class Solution {
public:
    set<string>   results;
    vector<string>   finalresults;
    int    maxs = 0;
    int    maxkuohao = 0;
void   dfs(int  index,string  s,int  left_count,int  right_count,string  currents)
{
    if(index == s.length())
    {
        if(left_count == right_count)
        {
            if(currents.length() >= maxs)
            {
                results.insert(currents);
                int   lengths = currents.length();
                maxs = max(maxs,lengths);
                maxkuohao = max(left_count,maxkuohao);
            }
        }
        return;
    }
    if(s[index] == '(')
    {
        if(left_count-right_count <= s.length()-index&&left_count+(s.length()-index)/2 >= maxkuohao)
        //假设左边的括号都能够匹配，并且右边的括号都能够匹配
        {
            dfs(index+1,s,left_count+1,right_count,currents+s[index]);
        } 
        dfs(index+1,s,left_count,right_count,currents);
    }
    else   if(s[index] == ')')
    {
        dfs(index+1,s,left_count,right_count,currents);
        if(right_count < left_count)
        {
            dfs(index+1,s,left_count,right_count+1,currents+s[index]);
        }
    }
    else
    {
        dfs(index+1,s,left_count,right_count,currents+s[index]);
    }
}
vector<string> removeInvalidParentheses(string s)
{
    dfs(0,s,0,0,"");
    for(set<string>::iterator  it = results.begin(); it != results.end(); it++)
    {
        if((*it).length() == maxs)
        {
            finalresults.push_back((*it));
        }
    }
    return  finalresults;
}
};
```

