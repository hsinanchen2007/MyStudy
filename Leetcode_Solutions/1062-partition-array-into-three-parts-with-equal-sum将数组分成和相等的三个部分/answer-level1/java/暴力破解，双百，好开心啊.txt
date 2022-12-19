### 解题思路
单纯的计数法，求总和的三分之一，然后看子序列有几个满足的，还有要排除0的干扰，不然可能最后count>3
![图片.png](https://pic.leetcode-cn.com/dbaacc000eb320a1da12ed62d2ea6da43055c81a2b98fa5c888957ecf6116b10-%E5%9B%BE%E7%89%87.png)

### 代码

```java
class Solution {
    public boolean canThreePartsEqualSum(int[] A) {
         int a = 0;
		 for (int i = 0; i < A.length; i++) {
			a+=A[i];
		}
		 if(a % 3 != 0) return false;
         int b = a/3;
         int temp = b;
         int count = 0;
		 for(int i = 0 ; i < A.length ; i++){
             temp-=A[i];
             if(temp == 0){
                 temp = b;
                 count ++;
             }
         }
        if(count >= 3){//大于等于是因为可能有多个连续的和为0的情况，所以大于也可以。
            return true;//如果是等于的话最后一个用例过不了
        }else{
            return false;
        }
		 
    }
}
```