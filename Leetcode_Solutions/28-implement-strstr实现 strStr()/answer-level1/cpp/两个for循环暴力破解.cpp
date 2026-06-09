
```
class Solution {
public:
    int strStr(string haystack, string needle) {
        if(!needle.length())
        {
            return 0;//子串空字符串返回0 
        }
        else if(haystack.length()<needle.length())
        {
            return -1;//长度小于不存在
        }
        int result=-1;
        for(int i=0,flag=0;i<haystack.length();++i)//两个for循环暴力查找
        {
            int temp=i;
            for(int j=0;j<needle.length();++j)
            {
                if(haystack[i]==needle[j])
                {
                    flag=1;//匹配
                    ++i;
                }
                else{
                    flag=0;//不匹配
                    break;
                }
            }
            if(flag)
            {
                result=temp;
                break;//匹配退出
            }
            i=temp;//防止i变化
        }
        return result;
    }
};
```
