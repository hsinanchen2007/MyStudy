首先，看到这个题目，会很自然地想到两个参数，数组的起始值，单个数组里的元素，不妨设 起始值为i,数组元素为n：
根据求和公式有：
*(n + 2i - 1)n / 2 = t*
可简化为:*i = (2t - n^2 + n) / 2n  (1)*, 等价于*(2n)i + n^2 - n - 2t = 0  (2)*
(2)式可看成为一个关于i的线性函数，由于i >= 1, 所以 可得出n关于t的取值范围，即*n < sqrt(2t+1) + 1*,，在这里我为了数学上的方便，其实是i >= 0, 在编程中去掉0开头的就ok了，得到n范围后，再进行遍历，根据(1)式得出i的取值，
代码:双100%
```
class Solution {
    public int[][] findContinuousSequence(int target) {

        int n_bound = (int)(Math.sqrt(2 * target + 1) + 1);
        List<int[]> list = new ArrayList<>();
        for(int n = n_bound ; n >= 2; n--){
            int i = (int)(2 * target - n * n + n) / (2 * n);
            if((2 * target - n * n + n) % (2 * n) == 0 && i != 0){
                int[] temp = new int[n];
                for(int j = i; j < i + n; j++){
                    temp[j - i] = j; 
                }
                list.add(temp);
            } 
        }

        int[][] res = new int[list.size()][];
        for(int i = 0; i < list.size(); i++){
            res[i] = list.get(i);
        }

        return res;
    }
}
```
