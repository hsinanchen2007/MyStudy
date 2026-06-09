### 解题思路
#### 最开始的误解
最开始的思路是把横纵坐标的相对和算出，之后再进行排序求和，但是发现这样子只可以求出满足条件的点，并不能求出从（0，0）出发的点

### 正确方向

之后改进思路，从(0,0)出发，就是路径相关的题目，使用深搜或者广搜来实现，这里使用深度优先，并标记

### 实现步骤
 1.声明一段数组，来保存并标记走过路径，1表示符合条件的点，-1表示不符合条件的点（可以不用区分，统一表示，这里为调试准备）
 2.对该点的状态进行判断，并标记
 3.对上下左右符合要求的点，进行循环，递归，深度优先，搜索到需要的点的个数，并返回
### 代码

```java
class Solution {
    public static int[] l = {0,0,-1,1};
    public static int[] r = {-1,1,0,0};
    public int movingCount(int m, int n, int k) {
        int[][] x = new int[m][n];
        
        return getRes(x,0,0,m,n,k);
    }
    private int getRes(int[][] x,int a,int b,int m ,int n,int k){
        // -1 表示不可以，1表示可以
        if(x[a][b]==1||x[a][b]==-1){
            return 0;
        }
        if(getSum(a)+getSum(b)>k){
            x[a][b]=-1;
            return 0;
        }
        x[a][b] =1;
        int res = 1;
        for(int i = 0;i<4;i++){
            if(a+l[i]>=0&&a+l[i]<m&&b+r[i]>=0&&b+r[i]<n){
                res += getRes(x,a+l[i],b+r[i],m,n,k);
            }
        }
        return res;

    }
    private int getSum(int x){
        int res =0;
        while(x>0){
            res+=x%10;
            x = x/10;
        }
        return res;
    }
}
```