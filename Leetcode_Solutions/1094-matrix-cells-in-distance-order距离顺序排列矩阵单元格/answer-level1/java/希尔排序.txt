### 解题思路
此处撰写解题思路

### 代码

```java
class Solution {
    public int[][] allCellsDistOrder(int R, int C, int r0, int c0) {
        int[][] res = new int[R*C][2];
        for(int i=0;i<R;i++){
            for(int j=0;j<C;j++){
                res[i * C + j] = new int[]{i, j};
            }
        }
        sort(res,r0,c0,R,C);
        return res;
    }

    public void sort(int[][] arr,int r0,int c0,int R, int C){
        int len = R*C;
        
        int gap = len/2;
        while(gap>0){
            for(int i=gap;i<len;i++){
                int[] temp = arr[i];
                int tempjuli = Math.abs(temp[0]-r0)+Math.abs(temp[1]-c0);
                // System.out.print(tempjuli+"x  ");
                
                int preIndex = i-gap;
                int[] pre = arr[preIndex];
                int prejuli = Math.abs(pre[0]-r0)+Math.abs(pre[1]-c0);
                // System.out.print(prejuli+"y  ");
                while(preIndex>=0&&prejuli>tempjuli){
                    arr[preIndex+gap] = arr[preIndex];
                    preIndex = preIndex - gap;
                    if(preIndex>=0){
                        pre = arr[preIndex];
                        prejuli = Math.abs(pre[0]-r0)+Math.abs(pre[1]-c0);
                    }
                }
                System.out.print(preIndex+gap);
                arr[preIndex+gap] = temp;
            }

            gap = gap/2;
        }
    }
}
```