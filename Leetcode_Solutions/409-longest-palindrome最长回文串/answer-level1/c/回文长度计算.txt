### 解题思路
根据回文的结构，字符为偶数时显然可以形成回文，字符为奇数时，只需要将该字符的一个放在字符串中间位置即可形成回文。但是字符串中间位置是唯一的，因此首先需要将字符串中的各种字符的数量进行统计。
1.对于数量为偶数的字符，回文长度直接加该偶数即可；
2.对于数量为奇数的字符，回文长度加该奇数减1，同时只要出现奇数数量的字符，回文长度最后都需要加1.

### 代码

```c
int longestPalindrome(char * s){
    int letters[52]={0};
    int length=0;
    int center=0;
    int i;
    for(i=0;s[i]!='\0';i++)
        isupper(s[i])?letters[s[i]-'A'+26]++:letters[s[i]-'a']++;
    
    for(i=0;i<52;i++)
        if(letters[i]%2)
            {length+=letters[i]-1;
            center=1;}
        else
            length+=letters[i];
    return length+center;


}
```