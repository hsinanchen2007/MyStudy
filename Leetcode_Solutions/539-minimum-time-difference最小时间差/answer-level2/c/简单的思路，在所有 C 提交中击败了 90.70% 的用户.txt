### 解题思路
![image.png](https://pic.leetcode-cn.com/01504fd972ceecc9c9df9e2bbcb0ac4e74ffb5d23bde33dcff761917353d36cb-image.png)


### 代码

```c
int findMinDifference(char ** tp, int n){
    int a[1450]={0},i,h,m,min=1500,j;
    for(i=0;i<n;i++){
        h=(tp[i][0]-'0')*10+tp[i][1]-'0';
        m=(tp[i][3]-'0')*10+tp[i][4]-'0';
        a[h*60+m]++;
    }
    i=0;
    while(j<1440){
        while(i<1440&&a[i]==0) i++;
        if(a[i]>1) return 0;
        j=i+1;
        while(j<1440&&a[j]==0) j++;
        if(j<1440&&j-i<min) min=j-i;
        i=j;
    }
    i=0,j=1439;
    while(i<1440&&a[i]==0) i++;
    while(j>=0&&a[j]==0) j--;
    if(i+1440-j<min) min=i+1440-j;

    return min;
}
```