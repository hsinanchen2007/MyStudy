
 
![pic.jpg](https://pic.leetcode-cn.com/260a3ecb4c3c0cc8cd1e3e818626df311beda1e058227afb9975623ebfc06b7c-pic.jpg)
由上表可知：
    木板的所有组合方法=木板数量+1；
    木板的组合从大到小排列为一个等差数列
    有k块木板，按照从小到大的组合方式排列，则排在第n的长度=k*x+(y-x)*(n-1);

特殊情况:shorter和longer相等，组合方式只有一种，长度为k*shorter，返回即可

代码如下：
```
int* divingBoard(int shorter,int longer,int k,int* returnSize){
    if(!k)  {*returnSize=0;return 0;}
    //两块木板相等时
    if(shorter==longer){
        int* pt=(int*)malloc(sizeof(int));
        pt[0]=k*shorter;
        *returnSize=1;
        return pt;    
    }
    
    int* pt=(int*)malloc(sizeof(int)*(k+1));
    *returnSize=k+1；
    for(int i=0;i<k+1;++i){
        pt[i]=k*shorter+(longer-shorter)*(i+1-1);
    }
    return pt;
}
```
