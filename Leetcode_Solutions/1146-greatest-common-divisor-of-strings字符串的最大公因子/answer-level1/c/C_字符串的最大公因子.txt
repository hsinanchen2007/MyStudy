### 解题思路
窗口法，窗口从大到小

判断因子串的方法：因为题目给出，对与任意两个串T、S只要满足S=T+T+T+T+T+T+....就可以说T是S的因子串。因此可以得到结论“S的长度一定是T的整数倍”且“T的内容一定是从S[0]开始到S[T的长度-1]的内容”

### 代码

```c
char * gcdOfStrings(char * str1, char * str2){
    char* result;//最大的公因子串
    //测量两个字符串长度
    int length1=0,length2=0;
    char *iter1=str1,*iter2=str2;
    while(*iter1!='\0'){++length1;++iter1;}
    while(*iter2!='\0'){++length2;++iter2;}
    //窗口最大为两个字符串长度中较小的值，每次循环窗口大小减一
    for(int window=length1>length2?length2:length1;window>0;--window)
    {
        //如果两个字符串长度都可以被窗口长度整除，证明这时的窗口长度是一个合适的最大公因子串长度
        if(length1%window==0&&length2%window==0)
        {
            //查看一下两个字符串在窗口长度中（str【0~window-1】）的字符是不是对应相等，相等才可能是公因子串
            int flagWindow=1;
            for(int i=0;i<window;++i)
                if(str1[i]!=str2[i])
                {
                    flagWindow=0;
                    break;  
                }
            //如果是潜在的公因子串，先用这个子串“除”一下Str1.
            if(flagWindow==1)
            {
                //如果str[i]==str[i+window]对于任意i∈[0,length-window]成立，那么str[0~window]就是一个因子串（根据解题思路中结论）
                int flagStr1=1;
                for(int i=0;i<length1-window;++i)
                    if(str1[i]!=str1[i+window])
                    {
                        flagStr1=0;
                        break;
                    }
                //如果不是str1的因子串，重新选择窗口和潜在公因子串
                if(flagStr1==0)
                    continue;
                //是str1的公因子串，再用同样的方法看看是不是str2的公因子串
                int flagStr2=1;
                for(int i=0;i<length2-window;++i)
                    if(str2[i]!=str2[i+window])
                    {
                        flagStr2=0;
                        break;
                    }
                if(flagStr2==0)
                    continue;
                //是最大公因子串，保存到result并返回
                if(flagStr1==1&&flagStr2==1)
                {
                    result=(char*)malloc(sizeof(char)*(window+1));
                    int i=0;
                    while(i<window)
                    {
                        result[i]=str1[i];
                        ++i;                        
                    }
                    result[i]='\0';
                    return result;
                }
            }
        }
    }
    //如果没有公因子串，就返回空串
    result="";
    return result;
}
```