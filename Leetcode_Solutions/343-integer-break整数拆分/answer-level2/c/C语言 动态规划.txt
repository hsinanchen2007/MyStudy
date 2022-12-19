![QQ图片20200313002726.png](https://pic.leetcode-cn.com/d3cac550389ff8a83f4f669a2940482e876eee00f9d4bdc764878e2adead7f0b-QQ%E5%9B%BE%E7%89%8720200313002726.png)

    #define max(a,b) (a>b?a:b)

    int integerBreak(int n){
    int i,j;
    int *arr=(int*)malloc(sizeof(int)*(n+1));
    for(i=0;i<n+1;i++){
        arr[i]=1;
    }
    for(i=3;i<n+1;i++){
        for(j=2;j<i;j++){
            arr[i]=max(arr[j]*(i-j),arr[i]);
            arr[i]=max(j*(i-j),arr[i]);
        }
    }
    return arr[n];
    }