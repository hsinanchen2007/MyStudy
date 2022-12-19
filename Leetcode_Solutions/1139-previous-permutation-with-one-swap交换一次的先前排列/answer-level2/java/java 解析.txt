### 解题思路
此处撰写解题思路

### 代码

```java
class Solution {
    public int[] prevPermOpt1(int[] A) {
        int x = 0;
        int y = 0;
        // 反向遍历 查询出最后一个A[i]<A[j] j是最第一个满足条件的数字 的数 返回
        for(int i = A.length-2;i>=0;i--){
            for(int j=A.length-1;j>=i;j--){
                if (j>1&&A[j]==A[j-1]){
                   continue;
                }
                if(A[i]>A[j]){
                    int temp = 0;
                    temp = A[i];
                    A[i] = A[j];
                    A[j] = temp;
                    return A;
                }
                
            }
        }
        return A;
    }
}
```