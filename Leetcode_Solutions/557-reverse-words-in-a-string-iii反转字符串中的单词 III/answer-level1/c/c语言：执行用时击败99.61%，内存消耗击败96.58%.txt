### 解题思路
分别找到每个单词的起点和终点，将每个单词逆置
![1.png](https://pic.leetcode-cn.com/ab31108f6ff940359957df5de3f14895b1dd577b644df746d4d7ad8a9b59f615-1.png)


### 代码

```c
char * reverseWords(char * s){
    int l=0,r=0;
    int len=strlen(s);
    while(r<len)
    {
        l=r;
        while(s[r+1]!=' ' && s[r+1]!='\0')            //找到每个单词的起点l和终点r
            r++;
        int left=l,right=r;                           //用left和right分别记录l和r，
        while(left<right)                             //将一个单词逆置
        {
            char tmp=s[right];
            s[right]=s[left];
            s[left]=tmp;
            left++;
            right--;
        }
        if(s[r+1]=='\0')                              //到达句子末尾，终止循环
            break;
        r++;
        r++;
    }
    return s;
}
```