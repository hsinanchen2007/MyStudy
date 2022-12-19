### 解题思路
如题：
[1,2,3,4,5] b[0]
[1,1,3,4,5] b[1]
[1,2,1,4,5] b[2]
[1,2,3,1,5] b[3]
[1,2,3,4,1] b[4]
通过计算该矩阵的下三角矩阵和上三角矩阵进行求解
### 代码

```java
class Solution {
    public int[] constructArr(int[] a) {
        if(a == null || a.length == 0) return a;
        int length = a.length;
        int[] b = new int[length];
        //先计算下三角行列式
        b[0] = 1;
        for(int i=1;i < length;i++){
            b[i] = a[i-1]*b[i-1];
        }
        int temp = 1;
        //再把上三角给计算进去
        for(int i = length-2;i >= 0;i--){
            //倒数第一个开始加
            temp *= a[i+1];
            //倒数第一行不用加,直接从倒数第二行开始计算就可以
            b[i] *= temp;
        }
        return b;
    }
}
```