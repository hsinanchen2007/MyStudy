### 解题思路
此处撰写解题思路
1、长度为n的数组，第一个丑数为1；
2、下一各丑数为Min（第一个数*质因子）；
3、依次获取最小值即可。

### 代码

```java
class Solution {
    public int nthUglyNumber(int n) {
        int[] result = new int[n];
        result[0] = 1;
        int index = 0;
        int indexR2 = 0;
        int indexR3 = 0;
        int indexR5 = 0;

        while(index < (n-1)){
            int min = Math.min(result[indexR2]*2,result[indexR3]*3);
            min = Math.min(min,result[indexR5]*5);
            if(min == result[indexR2]*2){
                indexR2++;
            }
            if(min == result[indexR3]*3){
                indexR3++;
            }
            if(min == result[indexR5]*5){
                indexR5++;
            }
            index++;
            result[index] = min;
        }

        return result[n-1];
    }
}
```