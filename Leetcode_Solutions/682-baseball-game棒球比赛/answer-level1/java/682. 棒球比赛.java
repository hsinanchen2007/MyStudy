
/**
 * Project:
 * Author : zhaozhen
 * Email  : 
 * Date   : 2019/9/28
 * 
 * 解题思路: 主要使用 整数数组记录当前的有效轮分数 然后求和即可
 * 
 */
```
public class leetcode682 {
    public int calPoints(String[] ops) {
        int[] s = new int[1001];
        int j = 0;
        int sum = 0;
        for(int i = 0;i < ops.length;i++){
            switch (ops[i]){
                case "+":
                    s[j] = s[j-1] + s[j-2];
                    j++;
                    break;
                case "D":
                    s[j] = s[j-1]*2;
                    j++;
                    break;
                case "C":
                    j--;
                    break;
                default:
                    s[j] = Integer.valueOf(ops[i]);
                    j++;
                    break;
            }
        }
        for(int i = 0;i < j;i++){
            sum+=s[i];
        }
        return sum;
    }

    public static void main(String[] args) {

    }
}
```