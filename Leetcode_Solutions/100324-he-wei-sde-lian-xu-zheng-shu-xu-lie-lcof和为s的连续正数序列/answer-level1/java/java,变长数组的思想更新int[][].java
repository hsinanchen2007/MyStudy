学习了一个老哥写的题解，确实很厉害。
以target=9 为例子：题目有两个解 [2,3,4][4,5]
    以[4,5]为例，此解可转换为[4,4+1],因此target -= i++ 之后, i = 2;接着可以得到target % i == 0,意味着以4为开始的i个数字之和为9；
    [2,3,4]同理，

```
class Solution {
    public int[][] findContinuousSequence(int target) {
        int[][] result = new int[0][];
        //设置result数组的维度，找到第一组题解后会new一个长度为list+1的数组来替换result；
        int list = 0;
        //设置符合题解的数组长度。
        int i = 1;
        while(target > 0){
            target -= i++;
            if(target % i == 0 && target != 0){
                int[] temp = new int[i];
                for(int j = target / i,k = 0; k < i; j++,k++){
                    temp[k] = j;
                }

                //变长数组,更新result;
                int[][] result_temp = new int[list + 1][];
                result_temp[0] = temp;
                temp = null;
                for(int m = 1;m < list+1;m++){
                    result_temp[m] = result[m-1];
                }
                result = result_temp;
                result_temp = null;
                list++;
            }
        }
        return result;     
    }
}
```
