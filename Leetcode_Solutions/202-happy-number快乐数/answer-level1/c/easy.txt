### 解题思路
![image.png](https://pic.leetcode-cn.com/435dd4bfde8f6d15c9adea25ab5aef50f17a3c4a7adf7b9bb3b07f3a936b734d-image.png)


### 代码

```c
bool isHappy(int n){
    int lj,t,cnt=0;
    while(1){
        lj=0;
        cnt++;
        while(n){
            t=n%10;
            lj+=t*t;
            n/=10;
        }
        if(lj==1) return true;
        n=lj;
        if(cnt>50) break;
    }
    return false;
}
```