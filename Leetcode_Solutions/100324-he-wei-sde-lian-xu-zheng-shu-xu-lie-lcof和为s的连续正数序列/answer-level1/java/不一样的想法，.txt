### 解题思路
有没有和我一样样愚蠢的人来报个到！！(T_T)~(T_T)~(T_T)~

//根据数组中个数来计算
1. 因为题目中说明至少含有两个数，所以从`2`开始（2个的时候情况特殊一点，所以直接拎开另算）；
2. 从`3`个数开始计算到i(i+1)/2>target时结束
    i为奇数时，target能被i整除，则商即为正中间的数-i/2即为第一个数的值
    如，例1中的9/i=3(i=3),[2,3,4]；例2中15/i=5(i=3),[4,5,6]，15/i=3(i=5),[1,2,3,4,5]

    i为偶数时，以两个数为一个整体考虑，所以此时需要以target*2，i/2来计算是否满足
3. 反转list，转数组

这时间复杂度算是`(-1+√(1-4*(1-target*2))/2`吗？

### 代码

```java
class Solution {
    public int[][] findContinuousSequence(int target) {
        //从整数3开始才符合要求
        if(target < 3)
            return new int[0][0];

        List<int[]> list = new ArrayList<int[]>();
        //元素个数为2时较为特殊，直接判断即可
        if(target > 2 && target % 2 == 1)
            list.add(new int[]{target >> 1, 1 + target >> 1});

        //从元素个数i = 3开始计算，i个数时是否存在符合要求的序列
        for(int i = 3; i * (i + 1) / 2 <= target; i++){
            int num;
            //元素个数为奇数：整除即为满足
            if(i % 2 == 1 && target % i == 0){
                //正中间的数为targer/i
                num = target / i - (i >> 1);
            //为偶数：target*2能被i整除，target*2/i的商为奇数，才可能满足
            //如：i=6，21=1+2+3+4+5+6， 21*2=42能被6整除，42*2/6=7商为奇数
            //为什么要整除，商为奇数？ 21=7*(6/2)=(1+6)+(2+5)+(3+4);
            }else if(i % 2 == 0 && target * 2 % i == 0 && target * 2 / i % 2 == 1){
                // n+(n+1)=2n+1必为奇数，那么偶数个2n+1必为偶，奇数个2n+1必为奇
                if((target % 2 == 1 && i / 2 % 2 == 1) || (target % 2 == 0 && i / 2 % 2 == 0)){
                    //正中间一组数的前一位为targer/i
                    num = 1 + target / i - (i >> 1);
                }else{
                    continue;
                }
            }else{
                //不符合则继续 i++ 到 i*(i + 1)/2 > target 结束
                //i*(i + 1)/2 为1+...+i的和；从1开始都没办法满足了，说明个数达到上限了
                continue;
            }
            //满足要求的加入list
            int tmp[] = new int[i];
            for(int j = 0; j < i; j++){
                tmp[j] = num++;
            }
            list.add(tmp);
        }
        Collections.reverse(list);//反转，题目要求数字需要由小到大排序
        
        return (int[][])list.toArray(new int[list.size()][]);//list转数组。为什么不能直接List呢……
    }
}
/*
 *  以下为无注释方法体内代码，方便阅读
 */
        if(target < 3)
            return new int[0][0];

        List<int[]> list = new ArrayList<int[]>();
        if(target > 2 && target % 2 == 1)
            list.add(new int[]{target >> 1, 1 + target >> 1});

        for(int i = 3; i * (i + 1) / 2 <= target; i++){
            int num;
            if(i % 2 == 1 && target % i == 0){
                num = target / i - (i >> 1);
            }else if(i % 2 == 0 && target * 2 % i == 0 && target * 2 / i % 2 == 1){
                if((target % 2 == 1 && i / 2 % 2 == 1) || (target % 2 == 0 && i / 2 % 2 == 0)){
                    num = 1 + target / i - (i >> 1);
                }else{
                    continue;
                }
            }else{
                continue;
            }
            int tmp[] = new int[i];
            for(int j = 0; j < i; j++){
                tmp[j] = num++;
            }
            list.add(tmp);
        }
        Collections.reverse(list);
        
        return (int[][])list.toArray(new int[list.size()][]);
```