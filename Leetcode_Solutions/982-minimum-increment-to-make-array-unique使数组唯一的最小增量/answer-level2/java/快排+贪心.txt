### 解题思路
首先，使用快排进行排序 时间复杂度 O(nlogn)
一次遍历，O(n)

### 代码

```java
class Solution {
    public int minIncrementForUnique(int[] A) {
        if (A.length == 0) {
            return 0;
        }
        //快排
        quickSort(A, 0, A.length-1);

        //排序
        int count = 0;
        //int pre   = A[0];
        for (int i = 1; i < A.length; i++) {
            if (A[i] <= A[i-1]) {
                //贪心思想
                int pre = A[i];
                A[i]    = A[i-1] + 1;
                count  += A[i-1] - pre + 1;
            } 
        }

        return count;
    }


    private void quickSort(int[] A, int left, int right) {
        
        if (left >= right) {
            return;
        }

        //设置一个初始变量
        int key = A[left];
        //左变量
        int i = left;
        //右变量
        int j = right;

        while (i < j) {

            //从右向左扫描
            while(i < j && A[j] >= key) {
                j--;
            }

            //从左往右扫描
            while (i < j && A[i] <= key) {
                i++;
            }

        

            //交换两个值
            if (i < j) {
                swap(A, i, j);
            }
        }

        //交换key的值
        A[left] = A[i];
        A[i] = key;
        
        //递归左区间
        quickSort(A, left, i-1);
        //递归右区间
        quickSort(A, i+1, right);
    }

    //交换两个值
    private void swap(int[] A, int i, int j) {
        int temp = A[i];
        A[i]     = A[j];
        A[j]     = temp;
    }

}
```