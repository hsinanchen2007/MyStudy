![2020021502.PNG](https://pic.leetcode-cn.com/0af308069315633403169994af727320d6bc863201af4e7b34e859e4b5f4d5d6-2020021502.PNG)
### 解题思路
//两个for循环
//第一个for循环先求出最大的十进制数值
//第二个for循环打印从1到最大数值
//耗时:2ms,击败:88.36%用户;
//内存消耗:52.7MB,击败:100.00%用户;
### 代码

```java
class Solution {
    public int[] printNumbers(int n) {
        int temp = 1;
        for(int i=0;i<n;i++){
            temp *= 10;
        }
        int[] rec = new int[temp-1];
        int index=0;
        for(int k=1;k<temp;k++){
            rec[index] = k;
            index++;
        }
        return rec;
    }
}
```