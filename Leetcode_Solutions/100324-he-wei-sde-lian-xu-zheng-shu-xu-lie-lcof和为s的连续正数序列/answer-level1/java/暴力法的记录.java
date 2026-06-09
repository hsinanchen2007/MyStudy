### 解题思路
思路见代码注释。

### 代码

```java
class Solution {
    public int[][] findContinuousSequence(int target) {
        List<int[]> ans = new ArrayList<>(); //申请一个list，存放每一个结果集
        int sum, flag, tra, inset; //sum用于每一次求和，flag 表示从单个结果哪一个out开始
                             //tra为每一次的循环变量,inset作为找到一个结果进行数组插入的循环变量
        for(int out = 1; out <= target; ++out) { //从1开始测试
            sum = 0;  //每一次测试将sum清零
            for(tra = out; tra <= target; ++tra) { //从out开始进行求和，找出结果
                sum += tra; 
                if(sum > target) { //求和大于输入数，退出此循环
                    break;
                }                                       //为满足题意，舍去target本身，及判断结果数组长度数大于1
                else if(sum == target && tra - out + 1 > 1){ //找到一个结果，插入数组，并退出循环
                    int[] sotin = new int[tra - out + 1]; //申请储存一个结果的数组，长度为tra-out+1
                    flag = out; //从out开始
                    for(inset = 0; inset < tra - out + 1; ++inset) {
                        sotin[inset] = flag++;  
                    }
                    ans.add(sotin); //将一个结果数组存入到ans中
                    break;  //并退出此次循环
                }
            }
        }
        
        return ans.toArray(new int[0][]);  //将ans转成一个数组
    }
}
```