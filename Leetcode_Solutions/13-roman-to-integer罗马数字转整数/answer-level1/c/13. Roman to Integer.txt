### 解题思路
这道题思路来源于以下：
https://leetcode-cn.com/problems/roman-to-integer/solution/cyu-yan-shi-xian-jian-dan-ming-liao-by-187022/

### 代码

```c
int romanToInt(char * s){
    int len = strlen(s);    //先获取字符串长度
    if(len == 0) return 0;
    int resultNumber = 0;//!!不要忘记初始化不然是一个随机数！！
    for(int i=0;i<len;i++){
          switch(s[i]){
              case 'I':resultNumber+=1;
                        if(i<(len-1))
                            if(s[i+1]=='V'||s[i+1]=='X') resultNumber-=2;                                            break;
              case 'V':resultNumber+=5; break;
              case 'X':resultNumber+=10;
                         if(i<(len-1))
                            if(s[i+1]=='L'||s[i+1]=='C') resultNumber-=20;                                           break;
              case 'L':resultNumber+=50;break;
              case 'C':resultNumber+=100;
                         if(i<(len-1))    
                            if(s[i+1]=='D'||s[i+1]=='M') resultNumber-=200;                                          break;
              case 'D':resultNumber+=500; break;
              case 'M':resultNumber+=1000;break;
              default: break;//不要丢了这一句；
          } 
    }
    return resultNumber;
  
    
}
```
###总结
为什么想不到用switch语句？
首先，对字符串数组的操作不熟练，拿到题目之后看到*s，人是蒙的，不知道怎么下手。
以后遇到多种不同情况分类进行的时候，优先使用switch分支语句，根据不同的情况进行讨论。

###疑问
为什么我的执行时间是12ms，参考案例是0ms，这之间的区别来自于我在switch语句里面的顺序不一样。