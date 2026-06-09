### 解题思路
自己的第一次依靠自己解答的中等题，很开心
思路：先将数组进行排序，然后定义两个下标，`font`和`end`，以及记录移动的次数`moveNumber`，如果`A[font] == A[end]`并且`end`没有到达数组尾部，则将`end`继续向后移动一位，直到找到`A[font] != A[end]`时，并且判断两下标相邻之间大于1，开始循环`move`以font后一位的数字为开头，直到end处结束。这个算法有种临界情况，就是当end移动最后一位了，并且也同font处的数字相等，此时只需要计算`n + (n - 1) + ...+ 1，n = end - font;`即可。

### 代码

```java
class Solution {
    public int minIncrementForUnique(int[] A) {
        Arrays.sort(A);
        int font = 0;
        int end = 1;
        int moveNumber = 0;

        while(end < A.length) {
            if (A[font] == A[end]) {
                if (end != A.length - 1) {
                    end++;
                } else {
                    for (int i = end - font; i > 0; --i) {
                        moveNumber += i;
                    }
                    break;
                }
            } else {
                if (end - font > 1) {
                    for (int j= font+1; j < end; ++j) {
                        A[j] = A[j] + 1;
                        moveNumber++;
                    }
                    font++; 
                } else {
                    font++;
                    end++;
                }
                
            }
        }
        
        return moveNumber;
    }

    // 数组冒泡排序
    // public void bubbleSortArray(int[] A) {
    //     boolean flag = true;
    //     for (int i=0; i < A.length && flag; ++i) {
    //         flag = false;
    //         for (int j=A.length-2; j>=i; --j) {
    //             if (A[j] > A[j+1]) {
    //                 int temporary = A[j];
    //                 A[j] = A[j+1];
    //                 A[j+1] = temporary;
    //                 flag = true;
    //             }
    //         }
    //     }
    // }
}
```