### 解题思路
找到字符串中从A到z的个数并记录到哈希表中，再读取哈希表，count=所有元素个数中的可以组成偶数+1
比如 a3 b5 c2 则count= 2+ 4 +2 +flag(1)=9

### 代码

```c
int longestPalindrome(char * s)
{
    int len_str = strlen(s);
    int hash[128]={0};               //ASCII码哈希表    够用就行
    int count =0;                   //最大组成的长度
    int flag=0;                     //有奇数的标志  比如只有一个a

    for(int i=0; i<len_str; i++)        //遍历字符串 记录哈希表
    {        
        hash[s[i]]++;
    }

    for(int i='A'; i<='z'; i++)            //遍历哈希表 得到最大长度
    {
        count+=hash[i]/2*2;             //加上该数字含有的最大偶数
        if(flag==0)                        //标记含有奇数
        {
        if(hash[i]%2) flag=1;
        }
    }

    return count + flag;

}
```