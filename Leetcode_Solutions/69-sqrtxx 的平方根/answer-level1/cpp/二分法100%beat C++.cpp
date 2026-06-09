### 思路
如果从0开始累加，一个一个判断， 会超时的，采取二分法；
底数是0和1的时候，幂次方都是自身；mid写成图中的形式，防止INT_MAX超标；
返回值是right-1的情况包含了需要取整（8取整算作2* 2）和不用取整（4=2*  2）这两种情况

### 代码
```
int mySqrt(int x) {
       if(x<=1) return x;
       int left=0;
       int right=x;
       while(left<right)
       {
           int mid=left/2+right/2;
           if(x/mid>=mid){
               left=mid+1;
           } 
           else{
               right=mid;
           }
       } 
       return right-1;
    }
```


### 提交结果
![image.png](https://pic.leetcode-cn.com/1265b9e0afa84e6d2dc7bb52771380e6dd83a19261eb8f967e5af2c606f109b0-image.png)
