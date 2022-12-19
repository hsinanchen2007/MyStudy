## 第一种解法：
```
 /***
* 时间复杂度O(m+n)
* 空间复杂度O(m+n) 可以优化成O(m)
*/
    public static class Solution1 {
        public static void solution(int[] arr1, int[] arr2) {
            //arr1和arr2的元素数量
            int m = 3, n=3;

            //临时存放结果
            int[] resultArr = {0,0,0,0,0,0};
            int i = 0, j = 0, k = 0;

            while (i < m && j < n) {
                if (arr1[i] < arr2[j]) {
                    resultArr[k++] = arr1[i++];
                } else {
                    resultArr[k++] = arr2[j++];
                }
            }

            //存在arr1的数都比较小已排序完毕，或arr2的数都比较小已排序完毕，所以要判断哪个数组还有数据，因为数组是排序的，所以直接往结果集后添加即可
            if (i < m) {
                while (i < m) {
                    resultArr[k++] = arr1[i++];
                }
            }

            if (j < n) {
                while (j < n) {
                    resultArr[k++] = arr2[j++];
                }
            }

            //把临时结果替换到arr1中
            for (int index = 0; index < resultArr.length; index++) {
                arr1[index] = resultArr[index];
            }
        }
    }
```

## 第二种解法：
```
 /***
     * 因为我们知道m和n，所以可以把num2数组的数据合并到数组1中，然后再通过快速排序排序
     * 这种方法没有考虑到两个数组是排序过的
     * 时间复杂度O((N+M)log(N+m))
     * log(N+M)是排序需要的时间复杂度
     * 空间复杂度O(1)
     */
    public static class Soulution2 {
        public static void Solution(int[] arr1, int[] arr2, int m, int n) {
            System.arraycopy(arr1, 0, arr2, m, n);
            Arrays.sort(arr1);
        }
    }
```

## 第三种解法：
```
/***
     * 从后往前互相比较，把大的那个放到arr1的最后面
     * 时间复杂度O(m+n)
     * 空间复杂度O(1)
     */
    public static class Solution3 {
        public static void main(String[] args) {
            //后面的3个0用于占位，便于arr2的数据放进去
            int[] arr1 = {1,2,3,0,0,0};
            int[] arr2 = {2,5,6};
            //int[] arr1 = {2,7,0,0,0};
            //int[] arr2 = {0,1,5};
            Solution3.solution(arr1, arr2, 3, 3);
            for (int index = 0; index < arr1.length; index++) {
                System.out.println(index + ":" + arr1[index]);
            }
        }
        public static void solution(int[] arr1, int[] arr2, int m, int n) {
            int i = m - 1;
            int j = n - 1;
            int tailPoint = arr1.length - 1;
            while (i >= 0 && j >= 0) {
                if (arr2[j] > arr1[i]) {
                    arr1[tailPoint--] = arr2[j--];
                } else {
                    arr1[tailPoint--] = arr1[i--];
                }
            }

            //在i先耗尽的情况下，需要把arr2的前面几个的数字移到arr1中
            if (i < 0 && j >= 0) {
                for (int index = j; index >= 0; index--) {
                    arr1[tailPoint--] = arr2[index];
                }
            }
        }
    }
```

