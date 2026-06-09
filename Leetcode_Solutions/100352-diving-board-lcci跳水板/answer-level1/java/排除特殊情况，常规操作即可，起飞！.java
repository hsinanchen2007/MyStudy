### 解题思路
![图片.png](https://pic.leetcode-cn.com/cb597c301161ee5b4e85b3fbe7b085211fe76631af435eba5f6842c8473d1e77-%E5%9B%BE%E7%89%87.png)
效率还不错，总体上要排除特殊情况，
即k==0时返回new int [0] ;
shorter == longler时int [] a = new int [1];
                    a[0] = k*shorter;
                    return a;

一般情况就递增即可。
时间复杂度O(N)
空间复杂度O(N)
### 代码

```java
class Solution {
    public int[] divingBoard(int shorter, int longer, int k) {
        if(k==0){
            return new int [0];
        }
        if(shorter == longer){
            int [] a = new int [1];
            a[0] = k*shorter;
            return a;
        }
        int [] ans = new int [k+1];        
        
        for(int i = 0 ;i<ans.length;i++){
            ans[i]=k*shorter+i*(longer-shorter);
        }
        return ans;
    }
    
}
```