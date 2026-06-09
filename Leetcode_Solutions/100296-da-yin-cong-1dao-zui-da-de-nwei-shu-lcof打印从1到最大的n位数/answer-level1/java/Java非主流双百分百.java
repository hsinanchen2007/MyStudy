1.由题意得：n为数组最后一个值也是最大值的9的个数
2.那直接把用StringBuild把最大值得出来
3.最大值转化为int
4.从1开始循环地放进数组
```
class Solution {
    public int[] printNumbers(int n) {
        StringBuilder sb = new StringBuilder();
        for (int i = 0; i < n; i++) {
            sb.append('9');
        }
        int max = Integer.parseInt(sb.toString());
        int[] arr = new int[max];
        for(int i = 1; i <= max; i++) {
            arr[i-1] = i;
        }
        return arr;
    }
}
```
