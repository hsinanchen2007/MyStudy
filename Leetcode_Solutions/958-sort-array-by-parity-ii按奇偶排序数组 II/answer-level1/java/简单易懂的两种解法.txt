### 解题思路
解法一：将原来数组中的奇数和偶数分别存放在两个数组或者list中，然后在轮流放到结果数组里
解法二：遍历两次原来的数组，偶数存放到结果数组中的偶数位置，奇数存放到结果数组中的奇数位置。

展示解法二如下：

### 代码

```java
class Solution {
    public int[] sortArrayByParityII(int[] A) {
        int[] res=new int[A.length];
        int i=0;
        for(int x:A){
            if(x%2==0){
                res[i]=x;
                i+=2;
            }
        }
        i=1;
        for(int x:A){
            if(x%2!=0){
                res[i]=x;
                i+=2;
            }
        }
        return res;
    }
}
```