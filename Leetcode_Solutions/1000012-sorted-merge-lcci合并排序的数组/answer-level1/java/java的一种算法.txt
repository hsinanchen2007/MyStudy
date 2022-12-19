### 解题思路
因为存在A和B两个数组。
首先循环比较，将A中比B大的数直接拉到B中去，然后对B进行排序，放回A数组中。

### 代码

```java
class Solution {
    public int[] merge(int[] A, int m, int[] B, int n) {
        //因为B必定是放在最后的，所以将A中比B中大得数全部放进B中去
        int a=0;
        for(int i=0;i<m;i++) {
            int tmp = 0;//中转值
            for (int j = 0; j < n; j++) {
                if (B[j] < A[i]) {//如果A中的值大于B的，则交换两者的内容。
                    tmp = A[i];
                    A[i] = B[j];
                    B[j] = tmp;
                }
            }

        }
//运算后得出一个经过排序的A和初步排序的B（理论上只有一种情况就是当B的值全部大于A时。需要排序。）
        Arrays.sort(B);
//这个就是赋值了
        for(int i=m;i<A.length;i++) {

//                Arrays.sort(B);
            A[i] = B[a];
            a++;
        }


        return A;
    }
}
```