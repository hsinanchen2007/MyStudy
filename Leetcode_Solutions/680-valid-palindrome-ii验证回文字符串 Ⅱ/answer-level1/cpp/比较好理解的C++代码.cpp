```
class Solution 
{
public:
    bool is(string s,int i,int j)  //判断是不是j回文字符串
    {
        while(i<j)
        {
            if(s[i++] != s[j--])
                return false;
        }
        return true;
    }
    
    bool validPalindrome(string s) 
    {
        for(int i = 0,j = s.size()-1; i < j; i++,j--)
        {
            if(s[i] != s[j])   //当两端不等的时候，检查是否符合这两个条件
            {
                return is(s,i+1,j) || is(s,i,j-1);
            }
        }
        //跳出循环说明始终相等，即为回文字符串
        return true;

    }
};
```
