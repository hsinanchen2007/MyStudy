![image.png](https://pic.leetcode-cn.com/1810a7ad293ab83aa08995375519f5d2bd1d722dee1467147b6e328eb69f7fc1-image.png)

```
int factoria(int n){
    int f=1;
    for(int i=2;i<=n;i++){
        f*=i;
    }
    return f;
}
char * getPermutation(int n, int k) {
    char* res=(char*)malloc(n+1);
    res[n]='\0';
    
    int f=factoria(n);//求n! 
    int vis[10]={0};
    int index_r=0;
    const int len=n;

    while(index_r<len){
       
        f=f/n;//求（n-1）!
        int offset=k%f;//组内偏移
        int gropId=k/f+(offset==0?0:1); //以n(n-1)!为单位，计算k属于第几组
       
        // 找到第index_r个位置上的数字 即第1~n数组中未被选择的第groupId个数
        int digit=1,id=0;
        for(digit=1;digit<=len;digit++){
            if(!vis[digit]){
                id++;
            }
            if(!vis[digit]&&id==gropId){
                break;
            }
        }
        vis[digit]=1;//标记数字index已被选择
        res[index_r++]=digit+'0';
        k=(offset==0?f:offset);//组内偏移继续进行迭代
        n--;
    }
    return res;
}
```