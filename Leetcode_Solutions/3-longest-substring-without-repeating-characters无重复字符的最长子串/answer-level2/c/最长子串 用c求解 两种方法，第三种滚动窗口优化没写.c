### 解题思路
把第一个写出来后，时间复杂度有点大，想优化。无果，于是看了官方题解，于是就有了下面的。
折腾了好久。。。。。。也许还是太菜了。
第一个是穷举的方法
第二个的是滚动窗口 一个区间[i,j)的移动，当j在该区间找不到重复的字符，该区间右端右移，否则左端右移。
滚动窗口的优化是当检查到s[j]在s[i~j-1]中有重复的字符时，直接将i=j，无需进行i的递增判断，因为i+1到j的最长子串必定小于
i到j的最长子串

### 代码

```c
// bool check (int i,int j, char c,char *s){
//     for (int k=i;k<=j;k++){
//         if(s[k]==c){
//             return true;
//         }
        
//     }
//     return false;
// }
// int lengthOfLongestSubstring(char * s){
//     int len=strlen(s);
//     int maxlen=0;
//     for(int i=0;i<len;i++)
//     {
//         int curlen=0;
//         for (int j=i+1;j<len;j++){
//             if(check(i,j-1,s[j],s)){//检查从i到j-1中是否有第j个元素
//                 break;
//             }else{
//                 curlen++;
//             }
           
//         }
//         if(curlen>maxlen){
//             maxlen=curlen;
//         }
//     }
//     if(len>0) maxlen+=1;
//     return maxlen;
// }
// 上面是穷举的方法
// 下面的是滚动窗口 一个区间[i,j)的移动，当j在该区间找不到重复的字符，该区间右端右移，否则左端右移。
// 滚动窗口的优化是当检查到s[j]在s[i~j-1]中有重复的字符时，直接将i=j，无需进行i的递增判断，因为i+1到j的最长子串必定小于
// i到j的最长子串

bool check1(int i,int j,char c,char *s){
    if(i>j) return false;
    for (int k=i;k<=j;k++){
        if(s[k]==c) return true;
    }
    return false;
}
int lengthOfLongestSubstring(char * s){
    int len=strlen(s);
    int i=0,j=0;
    int li=i;//这里的其实是多余的，直接使用i，j就好
    int lj=j+1;
    int maxlen=0;
    while(i<len&&j<len&&lj<len&&li<len){
        
        if(check1(li,lj-1,s[lj],s)){//这里判断li到lj-1是否含有s[j];
            li++;
           
        }
        else{
           
            lj++;
          
        }
           if(maxlen<lj-li) maxlen=lj-li;
    }
    if(len==0) return 0;
    if(len==1) return 1;
    return maxlen;
}

```