### 解题思路
![360截图20200322174056041.jpg](https://pic.leetcode-cn.com/7284e4ef7106307f3199d320a5513001e5a1f932757517270732e103a9bc9f8b-360%E6%88%AA%E5%9B%BE20200322174056041.jpg)


### 代码

```c
int lengthOfLongestSubstring(char * s){
    int cnt=0;
    int max=0;
    if(*s=='\0')return 0;
    if(*(s+1)=='\0')return 1;
    char *p1,*p2,*p3;
    p1=s;
    for(p2=s+1;*p2!='\0';p2++)
     //p1在子串开头，p2在子串结尾，p3的作用是检查p2所指的字符在p1到p2之间是否出现过 
    {   
        if(p2<=p1)
        {
            continue;
        }
        for(p3=p1;p3<p2;p3++)
        {
            if(*p3==*p2)
            {
                cnt=p2-p1;
                if(max<cnt)max=cnt;
                p1=p3+1;
                break;

            }
        }
        
                

    }
    //当最长子串出现在s的结尾，上述循环不将其长度赋给max，如abcabcd。因为没有*p3==*p2，（此时*p2指向空）
    if(*p2=='\0'&&(p2-p1)>max){
        max=p2-p1;
    }
    return max; 


}
```