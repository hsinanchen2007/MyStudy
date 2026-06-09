可以通过列等式的方式来解题。
若array1数组所有元素的和为sum1,array2数组所有元素的和为sum2。
解：尝试移除array2数组中的某一个元素num,并且假设array1数组中存在一个元素x，满足交换后数组和相等。
    即 sum2 - num + x = sum1 - x + num -> 2 * x = sum1 - sum2 + 2 * num;
    通过hashSet辅助，将array1中的元素值 * 2存在set中，方便查找。
```
class Solution {
    public int[] findSwapValues(int[] array1, int[] array2) {
        //简单的数学问题，各自求出两个数组的所有元素的和，把其中一个数组的元素放到set中，方便查找
        Set<Integer> set = new HashSet<>();
        int sum1 = 0;
        for (int num : array1) {
            sum1 += num;
            //存放num * 2的值，方便查找
            set.add(2 * num);
        }
        
        int sum2 = 0;
        for (int num : array2)
            sum2 += num;
        
        //尝试在array2数组中移除某一个元素num
        //设array1中存在一个数为x，满足 sum2 - num + x == sum1 - x + num -> 2x = sum1 - sum2 + 2num
        //
        for (int num : array2) {
            int sub = sum1 - sum2 + 2 * num;
            //注意对sub的值除以2，因为sub相当于2x，我们要找的其实是x
            if (set.contains(sub))
                return new int[]{sub >> 1, num};
        }
        
        return new int[0];
    }
}
```
