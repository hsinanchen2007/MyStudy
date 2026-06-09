### 解题思路
重点是对第一部分的处理，用一个数组来存储所有可能作为第一部分的分界点
避免了使用复杂度为O（n^2)的暴力滑窗
### 代码

```java
class Solution {
    public boolean canThreePartsEqualSum(int[] A) {
        /*先统计数组的和，如果不是三的倍数，直接false*/
        int sum = 0;
        for (int a : A) {
            sum += a;
        }
        if (sum % 3 != 0) return false;
        /*三分点的值*/
        int partno = sum / 3;
        /*第一个三分点起始值*/
        int part1 = 0;
        int point = 0;
        /*记录第一次遍历得到的所有三分点*/
        int index[] = new int[A.length];
        /*第二个三分点起始值*/
        int part2 = 0;
        for (int i = 0; i < A.length - 2; i++) {
            part1 += A[i];
            if (part1 == partno) {
                index[point] = i;
                point++;
            }
        }
        for (int i = 0; i < index.length; i++) {
            if (i > 0 && index[i] == 0) {
                break;
            }
            part2 = 0;
            for (int j =  index[i]+1; j < A.length - 1; j++) {
                part2 += A[j];
                if (part2 == partno) {
                    return true;
                }
            }
        }
        return false;
    }
}
```