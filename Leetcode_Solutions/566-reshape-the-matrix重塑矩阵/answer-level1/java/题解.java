### 解题思路
由题意知道，先要判断，还没有学习队列就采用遍历的方法。题解中遍历是用了新的矩阵，这一点可以不断完善

### 代码

```java
class Solution {
    public int[][] matrixReshape(int[][] nums, int r, int c) {
        int a=nums.length*nums[0].length;
        int nums3[][]=new int[r][c];
        int b=0;
        int nums2[]=new int[a];
        for(int i=0;i<nums.length;i++){
            for(int j=0;j<nums[i].length;j++){
                nums2[b]=nums[i][j];
                b++;
            }
        }
        b=0;
        if(r*c==a){
        for(int i=0;i<r;i++){
            for(int j=0;j<c;j++){
                nums3[i][j]=nums2[b];
                b++;
            }

        }
        }
        else{
            nums3=nums;
        }
        return nums3;
    }
    
}
```