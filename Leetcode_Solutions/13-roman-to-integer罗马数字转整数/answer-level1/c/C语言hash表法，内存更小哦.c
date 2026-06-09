### 解题思路
![图片.png](https://pic.leetcode-cn.com/6a328dee7bc007fa0c06255ca396441ce5d9818fbc30036514e0c20feb95d715-%E5%9B%BE%E7%89%87.png)
### 代码

```c
int romanToInt(char * s){
    int hashtab[26]={0};
    hashtab['I'-'A']=1;hashtab['V'-'A']=5;hashtab['X'-'A']=10;
    hashtab['L'-'A']=50;hashtab['C'-'A']=100;hashtab['D'-'A']=500;
    hashtab['M'-'A']=1000;
    int slen=strlen(s);int output=0;int sumi=0;
    for(int i=0;i<slen;i++){
        int dex=s[i]-'A';int nexdex=0;
        if(i+1==slen){//防止越界，i+1越界了就这样处理
            sumi=hashtab[dex];
        }else{
            nexdex=s[i+1]-'A';
            if(hashtab[dex]<hashtab[nexdex]){
                sumi=hashtab[nexdex]-hashtab[dex];i++;//i++，因为i和i+1被绑定处理
            }else{                                    //所以下次循环要跳过一个元素
                sumi=hashtab[dex];
            }
        }
        output+=sumi;
    }
    return output;
}
```