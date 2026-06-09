### 解题思路
此处撰写解题思路
对于这题我的第一想法是标记空格发，对于已经遍历的坐标赋为true,So定义一个boolean型的二维数组sign来标记，然后就是使用dfs来求解了。
第一步：定义sign二维数组和方法遍历，主要就是用来存储sign为true
第二步：1.判断角标是否过m或者n，等于也不行，2.当角标为两位数时需数字相加且不大于k，可以等于k，3.sign数组是否标记为true，是证明已经走过。
第三步：为了提高速度向下遍历时，有对x和y进行减1，So在判断中增加两个条件，4.x和y不能少于0。
以上是我的个人见解，如有不对还望大佬指点，这也是我第一次做的题和第一次写题解不是很懂。如果有优化的还望指点一下。谢谢

### 代码

```java
class Solution {
    public int movingCount(int m, int n, int k) {
        boolean[][] sign = new boolean[m][n];
        return dfs(0,0,m,n,k,sign);
    }
    private int dfs(int x,int y,int m, int n,int k, boolean sign[][]){
        if(x<0 || x>=m || y<0 ||y>=n || (x%10+x/10+y%10+y/10)>k || sign[x][y]){
            return 0;
        }
        sign[x][y] = true;
        return dfs(x+1,y,m,n,k,sign)+dfs(x-1,y,m,n,k,sign)+dfs(x,y+1,m,n,k,sign)+dfs(x,y-1,m,n,k,sign)+1;
    }
}
```