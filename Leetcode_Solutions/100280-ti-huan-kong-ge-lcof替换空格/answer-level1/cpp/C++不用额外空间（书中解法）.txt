```
class Solution {
public:
    string replaceSpace(string s) {
       if(s.size()<1) return s;
       int num=0;
       for(int i=0;i<s.size();i++)
        {
            if(s[i]==' ') 
            num++;
        }
        int len=2*num+s.size();//每个空格新s长度+2
        int left=s.size()-1;
        int right=len-1;
        s.append(2*num,0);//不改长度直接访问会报错；
        while(left>=0&&right>left)
        {
            if(s[left]==' ')
            {
                s[right]='0';
                s[right-1]='2';
                s[right-2]='%';
                right-=3;
            }
            else
            {
                s[right]=s[left];
                right-=1;
            }
            --left;
        }
        return s;
    }
};
```
