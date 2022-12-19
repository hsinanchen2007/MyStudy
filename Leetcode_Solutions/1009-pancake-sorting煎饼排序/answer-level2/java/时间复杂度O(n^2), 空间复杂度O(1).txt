- 时间复杂度o(n^2), 空间复杂度O(1)
- 因为数组是1,2.......A.length的一种排列，也就是说不重复且是一个差值为1的等差数列的乱序
- 因此，我们并不需要对原数组排序！！！也就不需要额外的空间，所以空间复杂度为0
- 我的思路是：
-     1、外循环控制每次得到一个最大值，就如冒泡排序，每次冒到数组尾部一个最大值；
-     2、内层在索引0----max之间，找到那个最大的值，然后煎饼翻转两次，也就只需要两次，就可以把它翻转到对应的位置上去；
-     3、第一次反转：找到当前最大值后，把它放在索引0处；
-     4、第二次翻转：将0处的当前最大值，与他最后所在的位置之间的所有数字进行翻转；
-     5、如此循环A.length次，所有数字都已经完成了排序。


```java
class Solution {
    public List<Integer> pancakeSort(int[] A) {
        List<Integer> list = new ArrayList<Integer>();
        if(A == null || A.length == 0) return list;
        for(int i = 0, max = A.length; i < A.length; i++, max--) {
            for(int j = 0; j < max; j++) {
                if(A[j] == max) {
                    reverse(A, 0, j);
                    reverse(A, 0, max - 1);
                    list.add(j + 1);
                    list.add(max);
                    break;
                }
            }
        }
        return list;
    }
    
    private void reverse(int[] arr, int s, int e) {
        while(s < e) {
            int tmp = arr[s];
            arr[s] = arr[e];
            arr[e] = tmp;
            s++;
            e--;
        }
    }
    
}
```