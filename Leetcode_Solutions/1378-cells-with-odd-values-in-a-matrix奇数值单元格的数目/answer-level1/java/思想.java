### 解题思路
此处撰写解题思路
我的思路:
    根据传进来的二维数组中的的值来进行定位
    先循环indices的值，将里面的行和列的值取出来，再根据行和列的值进行遍历，
    1，进行行的遍历，每次遍历都加上1
    2，进行列的遍历，每次遍历都会加上1(列和行相交处自然会累加起来);
    3,再根据已经加了1的数组进行遍历，将奇数的个数进行一个统计
最后返回这个奇数的个数；
### 代码

```java
class Solution {
    public int oddCells(int n, int m, int[][] indices) {
        int nums[][]=new int[n][m];
        for(int i=0;i<indices.length;i++){
            int a,b;
            a=indices[i][0];
            b=indices[i][1];
            for(int j=0;j<m;j++){
                nums[a][j]++;
            }
            for(int k=0;k<n;k++){
                nums[k][b]++;
            }
        }
        int len=0;
          for(int j=0;j<nums.length;j++){
                for(int k=0;k<nums[j].length;k++){
                  if(nums[j][k]%2==1){
                     len++;
                    }
            }
          }
            return len;
    }
}
```