### 解题思路
28ms 5.6MB
比较笨的方法，建一个数组对应ASCII码计数来判断是否重复。
start从头开始向后逐个移动，计数，效率很低
不做题不知道水平有多差。相对来说,控制类比赛的代码真的太简单了
### 代码

```c
#include <string.h>
int lengthOfLongestSubstring(char * s){
    //使用类似桶排序方式计数
    int counter[128];
    //归零
    memset(counter, 0, sizeof(counter));
    int maxLength=0;
    int length=0;
    int start=0,end=0;
    int ascii;
    while(s[start] != '\0'){
        //end到达结尾
        if(s[end]=='\0'){
            start++;
            //归零
            memset(counter, 0, sizeof(counter));
            if(maxLength<length)    maxLength=length;
        }else{
            ascii = (int)s[end++];
            if(++counter[ascii]==2){
                //printf("start:%d\t,end:%d\t,lenght:%d\n",start,end,length);
                start++;
                end=start;
                if(maxLength<length)    maxLength=length;
                //归零
                length=0;
                memset(counter, 0, sizeof(counter));
            }else{
                length++;
            }
        }   
    }
    return maxLength;
}
```