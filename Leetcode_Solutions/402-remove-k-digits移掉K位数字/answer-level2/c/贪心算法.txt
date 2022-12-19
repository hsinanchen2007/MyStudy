### 解题思路
![image.png](https://pic.leetcode-cn.com/a3adb8a69b26547593256c8d84a1bf9267ba5968a956b0560aa3d03b9f3ba9ec-image.png)


### 代码

```c
char ans[10005];
char * removeKdigits(char * num, int k){
    int n=strlen(num),i,cur,j=0;
    if(k==n){
        ans[0]='0',ans[1]='\0';
        return ans;
    }
    ans[0]=num[0];
    cur=n-k-1;
    for(i=1;i<n;i++){
        if(n-i > cur){
            if(cur > 0 && num[i]>=ans[j]) ans[++j]=num[i],cur--;
            else{
                while(j>=0 && n-i > cur && ans[j]>num[i]){
                    j--,cur++;
                }
                if(cur > 0) ans[++j]=num[i], cur--;
            }
        }
        else{
            ans[++j]=num[i];
        }
    }
    ans[++j]='\0';
    for(i=0;;i++) if(ans[i]!='0') break;
    if(ans[i]=='\0') {
        ans[1]='\0';
        return ans;
    }
    return ans + i;
}
```