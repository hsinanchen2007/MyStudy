```
class Solution {
public:
    //首先考虑，取出两个点中间的数,又可以用前面的方法
    //int j=i;
    //while(j<s.size()&&s[j]!='.') j++
    int compareVersion(string s1, string s2) {
        int i=0,j=0;
        while(i<s1.size()||j<s2.size())
        {
            int x=i,y=j;
            while(x<s1.size()&&s1[x]!='.') x++;//分别找到s1和s2中。前面的字符
            while(y<s2.size()&&s2[y]!='.') y++;

            //atoi将字符串改成数字,并且接收的是char* 类型的，所以需要c_str转换一下char* 类型
            int a=i==x?0:atoi(s1.substr(i,x).c_str());//因为上一步中如果i已经指向最后一位的后一位，已经结束x==i
            int b=j==y?0:atoi(s2.substr(j,y).c_str());


            if(a>b) return 1;
            if(a<b) return -1;

            i=x+1;
            j=y+1;
        }
        return 0;
    }
};
```
