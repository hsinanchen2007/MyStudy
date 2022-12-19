### 解题思路
设置一个辅助数组flag[26]，两次遍历：第一遍统计各字符出现次数，第二遍找到第一个值为1的索引即为所求

### 代码

```c
int firstUniqChar(char * s){
    int flag[26]={0};
    int len=strlen(s);
    int i;
    for(i=0;i<len;i++){
        flag[s[i]-'a']++;
    }
    for(i=0;i<len;i++){
        if(flag[s[i]-'a']==1) return i;
    }
    return -1;
    
}
```