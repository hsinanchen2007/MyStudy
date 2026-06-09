快排的partition思想，只是把分组的标准改成判断奇偶，而不再是比较相对于pivot的大小。
单独抽出接口增加可扩展性，以后有其他的分组标准只需改变接口实现即可。


```
class Solution {
    public int[] sortArrayByParity(int[] A) {
        return sortArrayByCriteria(A, element -> (element & 1) == 0);
    }

    public int[] sortArrayByCriteria(int[] A, Criteria criteria) {
        int i = 0;
        int j = 0;

        for (j = 0; j < A.length; j++) {
            if (criteria.condition(A[j])) {
                //i指向后面分组的第一个元素
                if (i != j) {
                    swap(A, i, j);
                }
                i++;
            }
        }
        return A;
    }

    public interface Criteria {
        boolean condition(int element);
    }

    private void swap(int[] array, int i, int j) {
        int temp = array[i];
        array[i] = array[j];
        array[j] = temp;
    }
}
```
