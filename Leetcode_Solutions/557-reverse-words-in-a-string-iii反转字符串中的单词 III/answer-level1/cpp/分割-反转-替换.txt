```
class Solution {
public:
    string reverse(string ss)
    {
        int size= ss.size();
        string res=ss;
        for(int i=0;i<size;i++)
        {
            res[i] = ss[size-1-i];
        }
        return res;
    }
    
    
    string reverseWords(string s) {
        int size = s.size(); 
        int i=0;
        while(i<size)
        {
            int pre = i;
            while(s[i]!=' ')
            {
                i++;
                if(i>=size)
                    break;
            }
            string temp = s.substr(pre,i-pre);
            temp = reverse(temp);
            int k=0;
            for(int j=pre;j<i;j++,k++)
                s[j]=temp[k];
          
            i++;
            
        }
        return s;
    }
};
```