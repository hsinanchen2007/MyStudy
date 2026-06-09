![6.png](https://pic.leetcode-cn.com/1ca10908d728223fe7f3c867e42284c6360659c78fabcefd8db6dcb0bf61adbc-6.png)

```
int lengthOfLongestSubstring(char * s){
    const int size = 0xffff;
    int mtx[size];
    memset(mtx,0,size*sizeof(char));
    int i=0,j=0,result=0;
    int len = strlen(s);
    for(j=0;j<len;j++){
        int idx = s[j];
        mtx[idx] += 1;
        while(mtx[idx] > 1 && i < j){
            int ii = s[i];
            mtx[ii] -= 1;
            i++;
        }
        result = j-i+1 > result ? j-i+1:result;
    }
    return result;
}
```



