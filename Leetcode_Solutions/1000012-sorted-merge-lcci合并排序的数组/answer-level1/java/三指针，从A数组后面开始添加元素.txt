利用双指针，m指针指着A数组中的元素，n指针指着B数组，index指针指着要填入A数组处的索引。
```
class Solution {
    public void merge(int[] A, int m, int[] B, int n) {
        int index = m + n - 1;
        --m;
        --n;
        //只要还有数可以填入A数组中
        while (m >= 0 || n >= 0) {
            //当A数组没有可填的数了，或者B数组还有数可填入，并且当前B数组指针所指的数大于A数组指针所指的数
            if (m < 0 || (n >= 0 && B[n] >= A[m]))
                //将B数组的数填入A数组尾部
                A[index--] = B[n--];
            //否则填入A数组的数
            else
                A[index--] = A[m--];
        }
        
    }
}
```
