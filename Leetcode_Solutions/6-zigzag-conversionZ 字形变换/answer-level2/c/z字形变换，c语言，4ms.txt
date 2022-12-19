### 解题思路
就是找规律，按行读取。
L   C   I   R    
E T O A S I I G   
K   D   H   N
第一行和最后一行是一类：如第一行字母C的下标 = 字符L下标 + 2*numRows-2
其余行是一类：如第2行字符E和O的关系同上，字符T下标 = 字符E下标 + 2*(numRows-当前所在行是第几行)；
### 代码

```c
char * convert(char * s, int numRows){
    if(numRows == 1){
        return s;
    }
    int n=strlen(s),j,k=0;
    char *result = (char*)malloc(sizeof(char)*(n+1));
    result[n] = '\0';
    for(int i=0;i<numRows;i++){
        if(i==0 || i==numRows-1){               //第一行和最后一行
            for(j=i;j<n;j += 2*numRows-2){
                result[k++] = s[j];
            }
        }else{                                  //其余行
            for(j=i;j<n;j += 2*numRows-2){
                result[k++] = s[j];
                if(j+2*(numRows-1-i)<n){
                result[k++] = s[j+2*(numRows-1-i)];  
                }
            }
        }
    }
    return result;
}
```