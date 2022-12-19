### 解题思路
菜鸡解法。。。本题的思路很明确，想要构成一个三角形为第一条件，构成三角形基础上要求周长最大，这是第二条件。分析可得，我们可以使用排序算法先进行排序，随后进行反转，让其从大到小排列，方便找最大的周长，首先处理刚好为三个数的情况，如果第三个数小于或等于前两个数之差我们无需讨论，无法构成三角形，如果大于，那么返回这三个数之和，如果超过三个数，我们依次选取前三个数，因为第一个和第二数必然大于第三个数，所以无需讨论是否小于其他两边之和，只需讨论大于两边之差即可，这里好像写的有些问题，要大于最大的差，我们应该选取第一个数减去第三个数和第三个数比较，如果成立，跳出循环，这就是我们要找的数，如果遍历到最后依然不存在，返回的MAX不会变化，依然为0.

### 代码

```java
class Solution {
    public int largestPerimeter(int[] A) {
        if(A.length<=2) {
            return 0;
        }
        Arrays.sort(A);
        for(int i = 0;i<A.length/2;i++) {
            int temp = 0;
            temp = A[i];
            A[i] = A[A.length-1-i];
            A[A.length-1-i] = temp;
        }
        if(A.length==3) {
            if(A[2]<=A[0]-A[1]) {
                return 0;
            }else {
                return A[0]+A[1]+A[2];
            }
        }
        int MAX = 0;
        for(int i = 0;i<A.length-2;i++) {
            if(A[i+2]>A[i]-A[i+1]) {
                MAX = A[i+2]+A[i+1]+A[i];
                break;
            }
        }
        return MAX;
    }
}
```