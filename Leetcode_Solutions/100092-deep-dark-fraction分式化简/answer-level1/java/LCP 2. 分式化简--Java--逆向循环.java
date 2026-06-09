[Leetcode-Java(200+题解，持续更新、欢迎star)](https://github.com/pphdsny/Leetcode-Java/blob/master/src/pp/arithmetic/LCP/_2_fraction.java)

```java
    /**
     * 解题思路：
     * 对整个题目比划比划你会发现，整个解题的过程就是个循环求解分式，为了更好的写代码，逆向求解
     * 1、定义一个length为2的数组result，第一位是分子，第二位是分母
     * 2、逆向遍历数组
     * 3、对于第一位，result[0]=1,result[1]=item
     * 4、分式对下一位相加，直接分母*该值加到分子上，并将分子分母求导数
     * 5、由于是逆向求解，还需要对最终结果进行求导数
     *
     * @param cont
     * @return
     */
    public int[] fraction(int[] cont) {
        //1
        int[] result = new int[2];
        //2
        for (int i = cont.length - 1; i >= 0; i--) {
            int item = cont[i];
            if (result[0] == 0 && result[1] == 0) {
                //3
                result[0] = 1;
                result[1] = item;
            } else {
                //4
                result[0] += result[1] * item;
                swap(result);
            }
        }
        //5
        swap(result);
        return result;
    }

    private void swap(int[] arr) {
        int temp = arr[0];
        arr[0] = arr[1];
        arr[1] = temp;
    }
```