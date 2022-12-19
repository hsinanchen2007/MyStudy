### 解题思路
2步长 + 奇偶双指针 查找交换
### 代码

```java
class Solution {
    public int[] sortArrayByParityII(int[] A) {
        //初始化奇数序列指针
        int j = 1;
        //初始化偶数序列指针，每次的步长为2，保证遍历的数组为偶数数组，进行排序
        for (int i = 0; i < A.length; i += 2){
            //当值为奇数时
            if (A[i] % 2 == 1) {
                //遍历奇数序列
                for (;j < A.length ;j +=2) {
                    if (A[j] % 2 == 0) {
                        //找到偶数就进行交换元素
                        int tmp = A[i];
                        A[i] = A[j];
                        A[j] = tmp;
                        break;
                    }else {
                        continue;
                    }

                }
            }
        }
      return A;
    }
}

```