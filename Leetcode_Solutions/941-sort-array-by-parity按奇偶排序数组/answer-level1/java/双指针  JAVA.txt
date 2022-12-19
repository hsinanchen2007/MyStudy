该方法的时间复杂度是O(n)，空间复杂度是O(1)，实质上额外的空间只是两个指针

思路：要求是将偶数放在数组前面，奇数放在数组后面，而对于偶数和奇数内部是怎么排列的没有要求
所以，使用一个指针evenCount记录在数组头部，另一个指针oddCount记录在数组尾部
接下来是对数组的遍历
判断角标为evenCount的元素，如果为偶数，则evenCount++；如果为奇数，则与角标为oddCount的元素进行交换，并将oddCount--（这里交换使用了异或的方法，减少多余的空间使用，而且交换之后角标为oddCount的元素是奇数）
最后循环的条件就是evenCount<oddCount
```
代码块
class Solution {
    public int[] sortArrayByParity(int[] A) {
        int evenCount = 0;
        int oddCount = A.length-1;
        while(evenCount < oddCount)
        {
            if(A[evenCount] % 2 == 0)
                evenCount++;
            else
            {
                A[evenCount] = A[evenCount]^A[oddCount];
                A[oddCount] = A[evenCount]^A[oddCount];
                A[evenCount] = A[evenCount]^A[oddCount];
                oddCount--;
            }
        }
        return A;
    }
}

