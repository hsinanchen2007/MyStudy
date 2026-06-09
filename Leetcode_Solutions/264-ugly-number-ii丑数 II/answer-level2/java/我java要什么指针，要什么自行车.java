### 解题思路
此处撰写解题思路
2 3 5 依次从1开始乘，乘出来的数绝对是丑数，然后按顺序排序就可以了
排序的方式就是记录和2，3，5乘过的次数，代码里就是有三个计数的变量 ，
分别去匹配2，3，5，如果和2乘了就+1，下次就用+1的变量去乘匹配的2或
者3或者5。
---- 代码是从csdn上扒的，只做记录。。
https://blog.csdn.net/Strom72/article/details/80719276?depth_1-utm_source=distribute.pc_relevant.none-task&utm_source=distribute.pc_relevant.none-task
### 代码

```java
class Solution {
    public int nthUglyNumber(int n) {
         if(n==0) return 0;
            int[] factor={2,3,5};
            int[] ugly=new int[n];
            ugly[0]=1;
            int t2=0,t3=0,t5=0;
            for(int i=1;i<n;i++){
                ugly[i]=Math.min(ugly[t2]*factor[0],Math.min(ugly[t3]*factor[1],ugly[t5]*factor[2]));
                if(ugly[i]==ugly[t2]*factor[0])t2++;
                if(ugly[i]==ugly[t3]*factor[1])t3++;
                if(ugly[i]==ugly[t5]*factor[2])t5++;
            }
            return ugly[n-1];
    }
}
```