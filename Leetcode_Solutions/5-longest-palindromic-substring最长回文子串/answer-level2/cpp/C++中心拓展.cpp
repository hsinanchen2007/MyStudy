### 解题思路

### 代码

```cpp
class Solution {
public:
struct huiwen{
    int begin=0;
    int length=1;
};
huiwen len(int num,string s)
{
    int i=num;
    int j=num;
    while(s[num]==s[j])
    {j++;}
    j--;
    while(i>=0&&j<s.size())
    {
        if(s[i]==s[j])
        {
            i--;
            j++;
        }
        else break;
    }
    i++;
    j--;
    huiwen tmp;
    tmp.begin=i;
    tmp.length=j-i+1;
    return tmp;
}
    string longestPalindrome(string s) {
        huiwen a,b;
        for(int i=0;i<s.size();)
        {  
            b=len(i,s);
            if(b.length>a.length)
            {
                a=b;
                i=a.begin+a.length/2;
            }
            else {
               if(b.length%2==1)
                i=i+1;
                else
              {
                i=i+2;//while(s[i]==s[i+1]&&i<s.size()-1)i++;i++;
               }
            }
            if(i+a.length/2>=s.size()-1)
            break;
            //i++;
        }
        string str(s,a.begin,a.length);
        return str;
    }
};
```