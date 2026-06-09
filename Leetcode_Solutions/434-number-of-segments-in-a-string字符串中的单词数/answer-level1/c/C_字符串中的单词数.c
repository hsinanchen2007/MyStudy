### 解题思路
抓住单词的特征数单词
特征：前一个为空格，后一个为字符
参考
https://leetcode-cn.com/problems/number-of-segments-in-a-string/solution/zi-fu-chuan-zhong-de-dan-ci-shu-by-zed-65536/
### 代码

```c
int countSegments(char * s){
    if(s==0)return 0;
    int sum=0;
    for(int i=0;s[i]!='\0';++i)
        if((i==0||s[i-1]==' ')&&s[i]!=' ')
            ++sum;
    return sum;
}
```