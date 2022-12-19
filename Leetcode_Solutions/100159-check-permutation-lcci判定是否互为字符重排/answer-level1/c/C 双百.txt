### 解题思路
![Snipaste_2020-03-23_15-33-13.png](https://pic.leetcode-cn.com/05b5e3104a01d886c51365f586283f0b5458d1b54e8225573cdbbb00f49ca5d9-Snipaste_2020-03-23_15-33-13.png)
哈希思想：标记s1中各字母出现次数，用s2串去匹配。

### 代码

```c
bool CheckPermutation(char* s1, char* s2){
    int flag[26]={0};
    int len1=strlen(s1),len2=strlen(s2);
    int i;
    if(len1!=len2) return false;
    for(i=0;i<len1;i++){
        flag[s1[i]-'a']++;
    }
    for(i=0;i<len2;i++){
        if(flag[s2[i]-'a']>0){
            flag[s2[i]-'a']--;
        }else{
            return false;
        }
    }
    return true;
}
```