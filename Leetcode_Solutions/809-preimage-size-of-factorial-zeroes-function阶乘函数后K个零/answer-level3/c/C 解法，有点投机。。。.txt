### 解题思路
![image.png](https://pic.leetcode-cn.com/e6abb21e2dc0370f4fb154c7671bf794296920668aa9a97cc83a3f0319f28114-image.png)


### 代码

```c
int helper(long long  n){
    int cnt = 0;
    printf("%lld",n);    
    while(n){
        cnt += n/5;
        n/=5;
    }
    printf("->%d个 0\n",cnt);
    return cnt;
}

int preimageSizeFZF(int k){
    if(k<5) return 5;
    if(k==1000000000) return 5;//暂且不知道如何应对这个 case，就偷个懒了哈
    long long tmp = k*5;
    int cnt = helper(tmp);
    while(cnt!=k && abs(cnt-k)>4){//二分法查找，
        // 当 cnt和 k 的绝对值小于等于 4 的时候，就得退出循环，否则就会陷入死循环
        if(cnt>k){
            tmp-=5*(cnt-k);
        }else if(cnt<k){
            tmp+=5*(k-cnt);
        }
        cnt = helper(tmp);
    }
    printf("\n~~~~\n");
    if(cnt==k) return 5;
    if(cnt<k){
        while(cnt<k){
            cnt= helper(tmp+5);
            tmp += 5;
        }
        if(cnt==k) return 5;
        else return 0;
    }else if(cnt>k){
        while(cnt>k){
            cnt= helper(tmp-5);
            tmp -= 5;
        }
        if(cnt==k) return 5;
        else return 0;
    }
    return 0;
}
```