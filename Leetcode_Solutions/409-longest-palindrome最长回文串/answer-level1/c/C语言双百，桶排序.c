### 解题思路
经过题解里两位大佬思路的启发。
第一个for循环将字符串中各字母的出现次数记录在数组a[52]中（区分大小写）。
第二个for循环将sum加上各字母的成对出现次数，偶数直接相加，奇数减1后相加。
最后判定sum与原数组长度是否相等，相等直接return sum，不等还可以在中间加一个字母，所以return sum+1.

### 代码

```c
int longestPalindrome(char * s){
    int a[52]={0};
    for(int i =0;i<strlen(s);i++){
        if(s[i]>='a'&&s[i]<='z')
            a[s[i]-'a']++;          //将小写字母放在前26位
        else
            a[s[i]-'A'+26]++;       //将大写字母放在后26位
    }

    int sum=0;
    for(int i =0;i<52;i++){
        sum += a[i]-a[i]%2;         //将sum加上各字母的成对出现次数
    }
    if(sum == strlen(s))
        return sum;
    else return sum+1;
}
```