### 解题思路
此处撰写解题思路
思路很简单 将n个台阶的解法表示成f(n).f(n)=f(n-1)+f(n-2);可以这么理解到达n前面只有两种情况，n-1跨1步，n-2跨2步
刚改始我写的代码是
int climbStairs(int n){
    int ret_tmp[2];
    int ret =0;
    ret_tmp[0]=1;
    ret_tmp[1]=2;
    if(n < 3){
        ret = n;
    }
    else{
        ret =climbStairs(n-1) +climbStairs(n-2);
        }

    }
    return ret ;   
}
n=44时时间超时了，f(44)=f(43)+f(42)；而f(43)=f(42)+f(41)依次类推时间复杂度是2^n;
后面想到n->1太多重复了，就计算1->n。用ret_tmp[0]、ret_tmp[1]分别表示f(i-2),f(i-1);i从3计算到44

### 代码

```c
//动态规划的基本形式 f（i）=af（i）+bf（i-1）
//你有n阶的话，那么n-1跨一步到n阶，n-2跨2步，其他无法刚好得到n阶段那么方式为f（n）=f(n-1) +f(n-2); 
int climbStairs(int n){
    int ret_tmp[2];
    int ret =0;
    ret_tmp[0]=1;
    ret_tmp[1]=2;
    if(n < 3){
        ret = n;
    }
    else{
        for(int i=3;i<n+1;i++){
            ret =ret_tmp[0] + ret_tmp[1]; //不断往前增加
            ret_tmp[0] = ret_tmp[1] ;
            ret_tmp[1] = ret ;
           // printf("i=%d,ret=%d",i,ret);
        }

    }
    return ret ;   
}
```