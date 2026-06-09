### 解题思路
见代码注释
自己瞎琢磨的，通过以后还有点懵逼，写个题解理理思路
### 代码

```c
int lengthOfLongestSubstring(char * s){
    int i,j,low=0,len=0,sign,longest=0;
    int a=strlen(s);
    for(i=0;i<a;i++){
        sign=0;                         //设置重复标志
        for(j=i-1;j>=low;j--){          //从后向前扫描遍历过的无重复字符串
            if(*(s+i)==*(s+j)){         
                sign=1;                 //若重复则标志置1
                len=i-j;                //重置长度
                low=j;                  //设置扫描下限，保证扫描的字符串无重复
                break;
            }
        }
        if(sign!=1) len++;              //无重复则长度加1
        if(longest<len) longest=len;    //更新长度最大值
    }
    return longest;
}
```