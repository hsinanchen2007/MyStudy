
```Java []
class Solution{
    /**
    * 方法一：每个数字先平方，然后调用sort()排序
    * 执行用时: 8 ms
    * 内存消耗: 51.2 MB
    */
    public int[] sortedSquares1(int[] A) {
        int len = A.length;
        int[] a = new int[len];
        for (int i = 0; i < len; i++) {
            a[i] = A[i] * A[i];
        }
        Arrays.sort(a);
        return a;
    }
    
    /**
    * 方法二：双指针A版：i指向最大的负数，j指向最小的正数，j=i+1  
    * 执行用时: 3 ms
    * 内存消耗: 40 MB
    */ 
    public int[] sortedSquares2A(int[] A) {
        int len = A.length;
        int j = 0;
        //1.找到双指针的位置
        while (j < len && A[j] < 0)
            j++;
        int i = j-1;
        
        //2.排序、平方、新数组
        int[] a = new int[len];
        int t = 0;
        while( i >= 0 && j < len) {
            if(A[j] * A[j] > A[i] * A[i]) {
                a[t] = A[i] * A[i];
                i--;
            }else {
                a[t] = A[j] * A[j];
                j++;
            }
            t++;
        }
        
        while(i >= 0) {
            a[t] = A[i] * A[i];
            i--; t++;
        }
        while(j < len) {
            a[t] = A[j] * A[j];
            j++; t++;
        }
        return a;
    }

    /**
    * 方法三：双指针B版：i指向最左边0，j指向最右边len-1，选取最大的值放在新数组的最后，在比较的过程中i++或j--
    * 执行用时: 2 ms
    * 内存消耗: 40.4 MB
    */ 
    public int[] sortedSquares2B(int[] A) {
        int len = A.length;
        int[] a = new int[len];
        int i = 0, j = len - 1, t = j;
        while( i <= j) {
            if (A[i] * A[i] <= A[j] * A[j]) {
                a[t] = A[j] * A[j];
                j--;
            }else {
                a[t] = A[i] * A[i];
                i++;
            }
            t--;
        }
        return a;
    }
}
```
