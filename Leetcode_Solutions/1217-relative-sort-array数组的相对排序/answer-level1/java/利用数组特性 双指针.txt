### 解题思路
利用数组特性 双指针

### 代码

```java
class Solution {
    public int[] relativeSortArray(int[] arr1, int[] arr2) {
        //初始化一个临时数组
        int[] temp = new int[1001];
        //把arr1的数据先装入temp，并进行计数统计： temp[9]:3
        for (int i : arr1) {
            temp[i]++;
        }
        //初始化指针
        int index=0;
        //遍历数组arr2，如果temp[j]不等于0 说明 在temp数组中即arr1中有对应的数据
        for (int j : arr2) {//arr2 数据的序列位置即为有序序列
            while (temp[j] >0) {
                //把存在相对序列的下标位置，写回arr1
                arr1[index] = j;
                //计数减1
                temp[j]--;
                //后移继续查找
                index++;
            }
        }
        //依然有计数的值 遍历放回arr1 （后面这些值都是不需要arr2相对排序的）
        for (int i=0; i<temp.length; i++) {
            while (temp[i] >0) {
                arr1[index] = i;
                temp[i]--;
                index++;
            }
        }
        return arr1;

    }
}

```