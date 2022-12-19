此处提供两种做法，第一种由C语言实现，第二种由Python3实现。
```c
char * defangIPaddr(char * address){
    int i,length=0,sign=0;
    while(address[length]!=0)
        length++;
    char s[length+7];
    s[length+6]=0;
    for(i=0;i<length;i++){
        if(address[i]=='.'){
            sign++;
            s[i+sign*2-2]='[';
            s[i+sign*2-1]='.';
            s[i+sign*2]=']';
        }
        else s[i+sign*2]=address[i];
    }
    char *str;
    str=s;
    return str;
}
```
用Python3解决，只需要一行代码。
```python3
class Solution:
    def defangIPaddr(self, address: str) -> str:
        return address.replace('.','[.]')
```
![捕获.PNG](https://pic.leetcode-cn.com/72912bb75239f5e0ddc39a5243e68fc137ce8cf2c9f0a77822ae853a7bb2e0ef-%E6%8D%95%E8%8E%B7.PNG)
但是，虽然用Python3可以以十分简洁的代码完成工作，其执行用时和内存消耗都比用C语言实现差得多。