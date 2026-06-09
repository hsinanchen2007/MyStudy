两个指针，分别指向首尾，进行比较。

要注意的是一个为大写字母一个为小写字母的情况。例如'P'和'p'，判断的方法是相差等于32或-32，但要注意，**数字0和大写'P'之间的差值也为32**。因此此类判断应该**限定其值大于等于'A'**。
```
class Solution {
public:
    bool isPalindrome(string s) {
        if(s.size()==0)
            return true;
        
        int i=0,j=s.size()-1;
        while(i<j)
        {
            if((s[i]>='a'&&s[i]<='z'||s[i]>='A'&&s[i]<='Z'||s[i]>='0'&&s[i]<='9')&&(s[j]>='a'&&s[j]<='z'||s[j]>='A'&&s[j]<='Z'||s[j]>='0'&&s[j]<='9'))
            {
                if ((s[i] == s[j]) || (s[i]>='A'&&s[j]>='A')&&((s[i] - s[j] == 32) || (s[i] - s[j] == -32)))
                {
                    ++i;
                    --j;
                }
                else
                    break;
            }
            if(!(s[i]>='a'&&s[i]<='z'||s[i]>='A'&&s[i]<='Z'||s[i]>='0'&&s[i]<='9'))
                ++i;
            if(!(s[j]>='a'&&s[j]<='z'||s[j]>='A'&&s[j]<='Z'||s[j]>='0'&&s[j]<='9'))
                --j;
        }
        if(i<j)
            return false;
        else
            return true;
    }
};
```
