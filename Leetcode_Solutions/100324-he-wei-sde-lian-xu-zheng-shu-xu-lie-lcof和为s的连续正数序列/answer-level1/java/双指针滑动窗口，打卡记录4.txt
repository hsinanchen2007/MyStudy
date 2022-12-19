![TIM图片20200306183954.png](https://pic.leetcode-cn.com/a8c54eb77cc1339c01cd36c7e47cc17e0fbff519e4554476b4ef5c957a06aa0d-TIM%E5%9B%BE%E7%89%8720200306183954.png)

#### 方法：滑动窗口

暴力求解就是遍历所有子串，挑选出所有符合条件的值。但是，由于自然数序列是严格递增的。那么，如果求出来一个可行解就可以在这个可行解上推算出其他符合条件的答案。

##### 算法

使用两个指针`left`和`right`用于保存目前的滑动窗口的两端。每次移动都进行如下判断：
+ 如果$sum = target$：那么目前窗口内部的序列就是所求的答案之一。保存答案，并将窗口向前滑动（$right$自增1）。
+ 如果$sum \lt target$：说明当前窗口内的序列之和小于目标。窗口右端向前滑动，即$right$自增1。
+ 如果$sum \gt target$：说明当前窗口内的序列之和大于目标。窗口左端向前滑动，即$left$自增1。

```java []
class Solution {
    public int[][] findContinuousSequence(int target) {
        List<int[]> res = new ArrayList<>();
        int left = 0, right = 1;
        int sum = 0;
        int len = (target & 1) == 0 ? (target >> 1) + 3 : (target >> 1) + 2; 
        while(right <= len) {
            if (sum < target) 
            	sum += right++;
            else if (sum > target) 
                sum -= left++ + 1;
            else {
            	int m = right - left -1;
                int[] t = new int[m];
                for(int i = 0, n = left + 1; i < m; i++) {
                    t[i] = n++;
                }
                res.add(t);
                sum += right++;
            }
        }

        return res.toArray(new int[0][0]);
    }
}
```

##### 复杂度分析

+ 时间复杂度：$O(N)$ <br> 两个指针只需遍历一次，不需要回退
+ 空间复杂度：$O(N)$ <br> 在解题过程中需要新建一个数组储存暂时的结果

**P.S.** 这里还需要记录的是`List`的`toArray(T[] a)`接口。
文档中给出的示例如下：
```java []
String[] y = x.toArray(new String[0]);
```
注意，`toArray(T[] a)`方法传入一个目标数组，该数组的元素类型与目标类型一致。通过这种方法，可以将`List`对象转化成与传入类型参数相同的对象数组。`ArrayList`中`toArray(T[] a)`的实现如下：

```java []
@SuppressWarnings("unchecked")
public <T> T[] toArray(T[] a) {
    if (a.length < size)
        // Make a new array of a's runtime type, but my contents:
        return (T[]) Arrays.copyOf(elementData, size, a.getClass());// 这里用的也是System.arraycopy方法
    System.arraycopy(elementData, 0, a, 0, size);
    if (a.length > size)
        a[size] = null;
    return a;
}
```
其实就是判断传入数组的长度是否比`ArrayList`对象的`size`大。如果大于`size`大小，则将`ArrayList`对象的数组复制到传入的对象数组中，并且将下标为`size`的元素设置为`null`。做这一步的原因是因为**传入的数组不一定是刚刚初始化过的数组**。若不大于，就复制到一个新的对象数组中。故这个接口既可以像文档中给出的方式使用，也可以传入一个长度大于该`ArrayList`对象容量的数组。前者返回的是一个新的数组，后者是直接在传入的数组中进行修改。