`剑指offer---P51-54`

1. 时间复杂度为O(n)的解法：先遍历一遍字符串，统计出字符串空格的总数，每替换一个空格，总长度加二，计算出替换之后的字符串的总长度。从字符串的后面开始复制和替换，准备两个指针p1和p2，p1指向原始字符串的末尾，p2指向替换之后的字符串的末尾。向前移动指针p1，逐个把它指向的字符复制到p2指向的位置，碰到空格时，p1向前移动一格，在p2之前插入%20后，p2向前移动三格。p2和p1指向同一位置后，表明所有空格替换完毕。

```
class Solution {
public:
    string replaceSpace(string s) {
        int originalLen=s.size();
        if(originalLen<=0)return "";

        int numOfBlank=0;  
        for(auto c:s)if(c==' ')++numOfBlank;  //s中空格的个数
        int newLen=originalLen+numOfBlank*2; //替换之后的字符串的总长度
        for(int i=0;i<numOfBlank*2;i++)s+=' ';

        int indexOfOriginal=originalLen-1,indexOfNew=newLen-1;  //p1指向原始字符串的末尾，p2指向替换之后的字符串的末尾
        while(indexOfOriginal!=indexOfNew)
        {
            if(s[indexOfOriginal]!=' ')
                s[indexOfNew--]=s[indexOfOriginal];
            else
            {
                s[indexOfNew--]='0';
                s[indexOfNew--]='2';
                s[indexOfNew--]='%';
            }
            indexOfOriginal--;
        }
        return s;
    }
};
```