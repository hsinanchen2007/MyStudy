### 解题思路
![QQ截图20200408130838.png](https://pic.leetcode-cn.com/3b7a6aac1626507fdb6c9b76ac8099bc6aaef396f894482ee9257d1e970dfd1e-QQ%E6%88%AA%E5%9B%BE20200408130838.png)


### 代码

```java
public class Solution {
    boolean[][] matrix;
    int count=0;
    int k,row,col;
    public int movingCount(int m, int n, int k) {
        matrix=new boolean[m][n];
        this.k=k;
        this.row=m;
        this.col=n;
        DFS(0, 0);
        return count;
    }

    public void DFS(int m,int n){
        if(m==row || n==col || matrix[m][n] ||getDigit(m)+getDigit(n)>k)return;
        matrix[m][n]=true;
        count++;
        DFS(m + 1, n);
        DFS(m, n + 1);
    }

    public static int getDigit(int m){
        if(m<10)return  m;
        else if (m<100)return m/10+m%10;
        return 1;   //m <=100
    }
}
```