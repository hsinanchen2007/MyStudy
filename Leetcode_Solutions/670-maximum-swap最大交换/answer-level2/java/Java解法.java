### 解题思路
此处撰写解题思路
思路：先根据给定的数字，把数字的每一位拆分并放到 list 集合中，并且利用 list 中的数字组合成最大的数字，再根据这个最大的数字,判断原数字是否是最大数字，若不是找出应该交换的位置，进行交换即可。


### 代码

```java
class Solution {

    public int maximumSwap(int num) {
        //当 num 小于等于 10 时，直接返回。
        if (num <= 10) {
            return num;
        }
        //创建两个集合，一个是按照原来数字的顺序放到集合中；另一个是利用将原来的数字组合成最大数字后的。
        List<Integer> list1 = new ArrayList<>();
        List<Integer> list2 = new ArrayList<>();
        int result = num;
        //分别把 num 的每一位放到 list1 和 list2 中。
        while (result > 0) {
            int n = result % 10;
            list1.add(0, n);
            list2.add(0, n);
            result /= 10;
        }
        //判断原来的数字是否已经是最大数字了，如果是就将该数字直接返回。
        boolean flag = false;
        for (int i = 0; i < list1.size() - 1; i++) {
            if (list1.get(i) < list1.get(i + 1)) {
                flag = true;
                break;
            }
        }
        if (flag == false) {
            return num;
        }
        //把 list1 集合中的数字按照降序排序
         Collections.sort(list1, new Comparator<Integer>() {
            @Override
            public int compare(Integer o1, Integer o2) {
                if (o1 > o2) {
                    return -1;
                }
                if (o1 < o2) {
                    return 1;
                }
                return 0;
            }
        });
        //找出组合成的最大数与原来数字中从高位开始，第一个不同的数字，该数字就是需要交换的数字，
        //而交换的数字是该数字后最大的数字。
        int ret = 0;
        int i = 0;
        for (; i < list2.size(); i++) {
            //找到不同数字所在的位置
            if (list1.get(i) != list2.get(i)) {
                //ret 记录该位置
                ret = i;
                break;
            }
        }
        //由于集合不可以直接进行交换，因此先把集合中的数字放到数组中。
        int[] arr = new int[list1.size()];
        for (int j = 0; j < list1.size(); j++) {
            arr[j] = list2.get(j);
        }
        // max 记录需要交换数字后最大的数字，如果有多位，那么就取最后面的
        //那个数字(因为越往后面权重越低，所以要想获得最大值，就要把后面大的数字往前面放)。
        int max = 0;
        int w = 0;
        for (int j = ret + 1; j < list2.size(); j++) {
            //找到比需要交换数字大的数字就记录该数字的下标
            if (arr[j] >= max) {
                max = arr[j];
                w = j;
            }
        }
        //交换需要交换的数字
        int tmp = arr[ret];
        arr[ret] = arr[w];
        arr[w] = tmp;
        int cur = 0;
        int k = 0;
        //最后根据数组中数字的顺序转换成为最终的数字。
        for (int j = arr.length - 1; j >= 0; j--) {
            cur += arr[j] * Math.pow(10, k);
            k++;
        }
        return cur;
    }
}
```