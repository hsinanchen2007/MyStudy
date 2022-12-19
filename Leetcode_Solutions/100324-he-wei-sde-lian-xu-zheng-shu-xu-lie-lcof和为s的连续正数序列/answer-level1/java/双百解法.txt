首先声明，这种解法参考了提交记录中0ms的代码，做了一些改动，提高了代码的可读性。

核心思想：找到连续序列的第一个值，因为是连续序列，他后面的值分别比他多1、2、3···。
我们使用一个数字（i + 1）【下标为0到i】表示连续序列的长度，那么他后面的数字就比他多1 + ··· + i。
举个例子：假设target为9，首先i为1，我们target -= i；表示连续序列的长度为2（i + 1），第二个数字比第一个数字多1（i)
减去i之后的target就相当于序列中每一个数字都等于第一个数字，对于这个例子就是 第一个数字和第二个数字相等，我们用target / i,就能得到第一个数字了，根据序列长度，我们就能求出序列了。

代码如下：
```
class Solution {
    public int[][] findContinuousSequence(int target) {
        List<int[]> res = new ArrayList<>();
        int i = 1;
        while (target > 0) {
            target -= i;
            i ++;
            if (target > 0 && target % i == 0) {
                int[] arr = new int[i];
                // k 为序列的第一个数字
                int k = target / i;
                for (int j = 0; j < i; j ++) {
                    arr[j] = k;
                    k ++;
                }
                res.add(arr);
            }
        }
        Collections.reverse(res);
        return res.toArray(new int[0][]);
    }
}
```
