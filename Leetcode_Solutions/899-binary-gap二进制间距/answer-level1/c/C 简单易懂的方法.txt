# 思路：
1）利用 1 与数字N进行&运算检查二进制第一位是否为1
2）逐步将数字二进制值向右移动一位:N = N>>1
3) N <= 0 时终止
 ![image.png](https://pic.leetcode-cn.com/2c7ece970f0b2a8502d061329f84f33aced246b94a55b4317de5298ae682cafd-image.png)


# 代码：
```
int binaryGap(int N){
    int distance = 0, max = 0,distanceon = 0; 

    while (N > 0){
        if((N & 1) != 0){
            distanceon = 1;
            if(distance > max){
                max = distance;
            }
            distance = 0;
        }
        distance+=(distanceon);
        N = N >> 1;
    }
    return max;
}
```
或者这样：
```
int binaryGap(int N){
    int distance = 0, max = 0,distanceon = 0; 
    unsigned int mask  = 1;
    for(int i  = 0; i < 32; i++){
        if((mask & N)!= 0){
            distanceon = 1;
            if(distance > max){
                max = distance;
            }
            distance = 0;
        }
        distance+=(distanceon);
        mask = mask << 1;
    }
    return max;
}
```
