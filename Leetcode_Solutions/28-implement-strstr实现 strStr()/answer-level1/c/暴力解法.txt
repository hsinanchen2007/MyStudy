### 解题思路
此处撰写解题思路

### 代码

```c
int strStr(char * haystack, char * needle){
    int lenh=strlen(haystack);
    int lenn=strlen(needle);
    if(lenh==0&&lenn==0)return 0;
    if(lenh==0&&lenn!=0)return -1;
    if(lenh!=0&&lenn==0)return 0;
    int key=-1;
    int j=0;
    for(int i=0;i<lenh;i++){
        int k=i;
        while(k<lenh&&j<lenn&&haystack[k]==needle[j]){
            k++;
            j++;
        }
        if(j<lenn)j=0;
        else if(j==lenn){
            key=k-lenn;
            break;
        }
    }
    return key;
}
```