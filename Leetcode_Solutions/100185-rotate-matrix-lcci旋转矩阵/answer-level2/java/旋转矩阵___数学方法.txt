### 解题思路
此处撰写解题思路
我是先写出了转换前后每一个数的下标，发现转换前的j发到了转换后的i中，而唯一变化的是由i转换为j。测试了最大转换和最少转换，得出其变化与i有关，当由0变2时发现由长度减1符合，当1变1时根据前面两个相关得到len-i-1便可以顺利转换。这一题是用来数学方法来解决的。
以上是我的个人见解，如有不对还望大佬指点，这也是我第一次做的题和第一次写题解不是很懂。如果有优化的还望指点一下。谢谢
### 代码

```java
class Solution {
    public void rotate(int[][] matrix) {
        int len = matrix.length;
        int[][] tmpe = new int[len][len];
        for(int i=0;i<len;i++){
            for(int j=0;j<len;j++){
                tmpe[j][len-i-1] = matrix[i][j];
            }
        }
        for(int i=0;i<len;i++){
            for(int j=0;j<len;j++){
                matrix[i][j]=tmpe[i][j];
            }
        }
    }
}
```