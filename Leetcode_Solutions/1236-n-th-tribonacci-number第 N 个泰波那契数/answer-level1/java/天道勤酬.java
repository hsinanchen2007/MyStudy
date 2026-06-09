### 解题思路
此处撰写解题思路
一开始看成了斐波那契数列，尴尬。用递归求解时，耗时太长，所以不要完全相信算法，算法只是工具。这道题是动态规划问题，以下是代码，有看不懂的朋友欢迎随时提问，共同进步。
### 代码

```java
class Solution {
    public int tribonacci(int n) {
        if(n==0){
            return 0;
        }
        if(n==1||n==2){
            return 1;
        }
        int i1=0;
        int i2=1;
        int i3=1;
        for(int i=4;i<=n;i++){
            int temp=i1+i2+i3;
            i1=i2;
            i2=i3;
            i3=temp;
        }
        return i1+i2+i3;
    }
}
```