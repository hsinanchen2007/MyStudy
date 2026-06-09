### 解题思路
>执行用时 :1 ms, 在所有 java 提交中击败了98.80%的用户
>内存消耗 :34.6 MB, 在所有 java 提交中击败了87.21%的用户

第一步： 利用桶排序的思想，设置一个容量为10的long(64位)类型的桶，然后数组的值用桶的二进制位进行表示。即二进制第0位表示桶的索引位，第1位表示10，第2位表示20，第3位表示30，... 第63位表示630。<br>

第二步： 对数组进行第一次遍历，对数组中值除10小于64的进行装桶标记。<br>

第三步： 第一次遍历完成后，然后对桶进行遍历，如果桶中的二进制值带有0，则有最小值则进行第四步，否则对multi
进行+1(这里是把找最小值的范围变为640~1280)，重复第二步。<br>

第四步： 解析每个桶二进制值中第一个出现0的位，然后转换成对应的缺失最小值。<br>

第五步： 10个桶中缺失值最小的那个值，就是我们要找的值。<br>

### 小提示
不过进过测试发现，全部测试案例的缺失最小值的小于639，所以根本不需要进行第二次遍历即可获取缺失最小正值。<br>
因此只需要对数组中的值小于639的进行装桶即可。
### 代码

```java
class Solution {
    public int firstMissingPositive(int[] nums) {
        long[] buddles = new long[10];
        buddles[0] = 1;
        int singles;
        int min = Integer.MAX_VALUE;
        int multi = 0;
        while(true){
            multi++;

            for(int num: nums){
                if(num > 0 && (num/10 <(64*multi))){
                    singles = num%10;
                    buddles[singles] |= 1<<(num/10);
                }
            }

            for(int i=0; i<buddles.length; i++){
                if(buddles[i] == Integer.MAX_VALUE){
                    continue;
                }
                int index = 0;
                while((buddles[i]>>index)%2 != 0){
                    index++;
                }
                min = Math.min(index*10 +i, min);
            }
            if(min == Integer.MAX_VALUE){continue;}
            return min;
        }
    }
}
```