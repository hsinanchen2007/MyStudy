### 解题思路
很烂的算法，应该不叫算法。
    思路：从最小的开始，若有n个相同，则需要有n-1个都加1，在此基础上继续循环
时间复杂度不会算，反正很高，估计是n方

### 代码

```java
class Solution {
    public int minIncrementForUnique(int[] A) {
        Arrays.sort(A);
        int num = 0;
        for(int i=0;i<A.length;i++){
            int a = A[i];
            for(int j=i+1;j<A.length;j++){
                if(A[j]==a){
                    A[j]++;
                    num++;
                }else{
                    break;
                }
            }
        }
        return num;
    }
}
```