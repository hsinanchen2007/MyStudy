### 解题思路
 思路1，暴力解法 n=3 3层for循环，下标的和加起来等于k就是要找的组合，时间复杂度 O(K) K = n! ==> O（n!) 是指数级别
  思路2， 时间复杂度 O(n) + O(n) + O(n*n),所以是 O(n^2), 当n越大，时间越短和思路1比起来
通过观察全排序我们可以发现这个是有序的， 第一列从1 到3，第二列是去除第一列值之后得 1,3， 第三列是去除 第一列
  和 第二列值之后的唯一值了。第k个组合就可以通过这个规律算出来 第1，2，3列的值。
  比如下面的 n =3， k = 3，
  n =3 ，说明总共有3列，k = 3 说明要第3个组合
  第二列和第三列组合总共有2种 = (n-1)!,  所以第一列等于1的时候有2个组合，k=3,所以要取第三个组合，前两个组合
  第一列是1，第三个组合 第一列肯定是2，因为组合是列的升序进行组合的,所以我们可以通过公式  k/(n - 1)! = 3/2 = 1,
  但是这里有个问题，当 k =2 时， 2/2=1，也会选择2，其实这个时候应该选择1，所以公式改为   （k -1）/ (n - 1)!= 2-1/2 = 0
  使用 k -1 ，同时也解决了，当剩余元素为2个时 k =2 这种特殊情况的处理。
  来计算第一列的值的在 [1， 2，3]中的下标，从而得到具体的值，当前由于全排列的特定，其实直接用下标+1就是具体的值。
  由于第一列确定了，所以 k的值应该减去已经进行的排列了 k = k % (n-1)! = 3 /2 = 1,
   但是这种取余数的做法无法解决 k=2，阶乘等于 1 的情况，所以 k =（k -1）/ (n1)! * (n -1)!
  注意 ： 当k=1时，表明取第一个组合 ,一个组合就是按照未被访问过的，升序的组合
  未被访问元素 1，3， 按照升序即位 1，3，和 第一列组合就是 2 1 3 正确结果.

### 代码

```java
class Solution {
    /**
     * 思路2解法，时间复杂度是由n来决定的，所以是 O(n)
     *
     * @param n
     * @param k
     * @return
     */
    public String getPermutation(int n, int k) {
        if (n < 1 || n > 9)
            return "";
        int[] fac = calFactorial(n);
        boolean[] used = new boolean[n];
        int index;
        Arrays.fill(used, false);
        StringBuilder sb = new StringBuilder(n);
        // 1 <  k < n!, 当k = 1时退出，把剩下的数据，按照从小到大进行拼接就是最后结果
        //最后一个元素不用进行分析，
        for (int i = 0; i < n - 1 ; i++) {
            if (k == 1)
                break;
            index = (k -1) / fac[n - i - 1];
            k = k - index * fac[n - i - 1] ;
            //找到未使用的，第 index 个元素,index为0，表示第一个
            int j ;
            for (j = 0 ;  j < n; j++){
                if(used[j]) {
                    continue;
                } else{
                    if (0 == index)
                        break;
                    else
                        index--;
                }
            }
            // 因为下标从0开始，所以j下标对应得元素值应该是  j+1
            sb.append(j + 1);
            used[j] = true;
        }
        //k = 1时，进行处理
        for (int i = 0; i < used.length; i++)
            //如果还未被访问过，则按照顺序输出，就是k=1时的组合
            if (!used[i])
                sb.append(i + 1);
        return  sb.toString() ;
    }

    /**
     * 生成一个阶乘数组，从1到n的阶乘，结果存入数组中，数组从0开始
     * @param n
     * @return
     */
    private int[] calFactorial(int n) {
        int[] fac = new int[n];
        if (n < 1)
            return fac;
        fac[0] = 1;
        for (int i = 1; i < n; i++) {
            fac[i] = fac[i - 1] * i;
        }
        return fac;
    }

    @Test
    public void test() {
        Assertions.assertEquals("123", getPermutation(3, 1));
        Assertions.assertEquals("132", getPermutation(3, 2));
        Assertions.assertEquals("213", getPermutation(3, 3));
        Assertions.assertEquals("231", getPermutation(3, 4));
        Assertions.assertEquals("312", getPermutation(3, 5));
        Assertions.assertEquals("321", getPermutation(3, 6));
        Assertions.assertEquals("312", getPermutation(3, 5));
        Assertions.assertEquals("21", getPermutation(2, 2));
        Assertions.assertEquals("132", getPermutation(3, 2));
        Assertions.assertEquals("2314", getPermutation(4, 9));
    }
}
```