我这个应该属于暴力解吧，跑了一千多毫秒QAQ
首先排序，有序之后从1开始只要前面的元素小于后面的元素就可以，
如果不小于的话，就把这个元素加1，最小操作数+1
遍历完就好了

这代码刚写完就发现可以优化...
如果不小于的话，直接加上A[i-1]-A[i]+1就比前一个元素大1了

[臭不要脸的宣传一下自己的算法库..](https://github.com/H-Always/Algorithm-Repository)

### 代码

```java
class Solution {
    public int minIncrementForUnique(int[] A) {

        int min_length = 0;

        Arrays.sort(A);


        int i = 1;

        while (i < A.length) {
            if (A[i - 1] >= A[i]) {
                A[i]++;
                min_length++;
            } else {
                i++;
            }
        }


        return min_length;
    }
}
```

优化之后跑了16ms，作为一个菜鸡自我感觉还阔以...

```java
public class MinIncrementForUnique {
    public int minIncrementForUnique(int[] A) {

        int min_length = 0;

        Arrays.sort(A);

        int i = 1;

        while (i < A.length) {
            if (A[i - 1] >= A[i]) {
                min_length+=A[i-1]-A[i]+1;
                A[i]+=A[i-1]-A[i]+1;
            } else {
                i++;
            }
        }


        return min_length;
    }
}
```