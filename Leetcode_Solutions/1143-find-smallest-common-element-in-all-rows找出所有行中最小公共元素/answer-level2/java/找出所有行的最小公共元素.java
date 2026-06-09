### 解题思路
此处撰写解题思路

### 代码

```java
class Solution {
    public int smallestCommonElement(int[][] mat) {
        if(mat.length==0||mat[0].length==0)
            return -1;
        for(int i=0;i<mat[0].length;i++) //第一行的元素
        {
            boolean find=true;
            for(int j=0;j<mat.length;j++)
            {
                int index=Arrays.binarySearch(mat[j],mat[0][i]);  //二分查找
                if(index<0)
                {
                    find=false;
                    break;
                }
            }
            if(find)
                return mat[0][i];
        }
        return -1;
    }
}
```