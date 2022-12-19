### 解题思路
刚开始做这题的时候使用暴力的遍历，虽然知道只要a,b,c集齐了，在先前的字符不变的情况下不需要再往后一一遍历了，只需要再加strlen(s)-1的长度就好，但是依然还是超时；
想方设法简化了重复的操作，比如遍历时判断当前字符已经记过了就直接continue，但还是超时；
后来根据现有题解中的大神的思路启发，使用滑动窗口解决了此问题：
必要条件：设置一个记录a,b,c出现次数的数组alphbet，设置一个初始标杆startPoint以及一个游标endPoint，一开始把它们均设在最左边的0位;
初始标杆可以先放着暂时不必理会，用游标遍历字符串，每遍历一个字符，数组alphbet就要累加这个字符出现的次数；


一旦a,b,c齐活了，就没必要再单纯地往下走了，只要叠加上当前位置（含）到最后一位的个数即可，然后将初始标杆右移一位，将移开的字符在alphbet中的计数-1，然后再看看a,b.c是否还都有，如果都有，那就一样的，加上当前位置（含）到最后一位的个数即可，如果没有，游标就继续往右移，直到a,b,c再次齐活，然后做同样的累加。

以此循环。

这样真是比之前的双重循环省好多时间！


### 代码

```c

int numberOfSubstrings(char * s){
    if(s==NULL){
        return 0;
    }
    
    int alphbet[3] = {0};

    int startPoint = 0;
    int endPoint = 0;
    int count = 0;
    int sLen = strlen(s);
    while(endPoint<sLen){
        alphbet[s[endPoint]-'a']++;
        while(alphbet[0]>0&&alphbet[1]>0&&alphbet[2]>0){
            count+=(sLen-endPoint);
            alphbet[s[startPoint]-'a']--;
            startPoint++;
        }
        endPoint++;
    }
    return count;
}
```