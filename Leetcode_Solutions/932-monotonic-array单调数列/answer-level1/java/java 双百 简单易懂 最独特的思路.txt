![屏幕快照 2020-03-15 上午10.27.38.png](https://pic.leetcode-cn.com/55e53d9fec2265cf33605ee9ce7a278112f929e4dc7c544cb6ef8902317d2c3d-%E5%B1%8F%E5%B9%95%E5%BF%AB%E7%85%A7%202020-03-15%20%E4%B8%8A%E5%8D%8810.27.38.png)

一次遍历，简单易懂，递增则i+1，递减则j+1
```
class Solution {
        public boolean isMonotonic(int[] A) {
            int i = 0;
            int j = 0;
            for(int k=0;k<A.length-1;k++){
                if(A[k]<A[k+1]){
                    i++;
                }else if(A[k]>A[k+1]){
                    j++;
                }
                if(i!=0&&j!=0){
                    return false;
                }
            }
            return i*j==0;
        }
    }
```
