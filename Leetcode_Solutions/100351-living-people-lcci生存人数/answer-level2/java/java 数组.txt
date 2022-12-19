### 解题思路
首先记录每个年份人员的变化,然后在统计出存活人最多的年份
1:birth[i]的每一个数据代表一个人的出生,所在年份的统计存活人数加1,birth[i]-1900
2:death[i]的每一个数据代表一个人的死亡,但是由于死亡当年也需要统计在存活,所以真正减去这个人的死亡是下一年
所以他的统计是death[i]-1900+1;
3:因为2000年死亡的人,会在2001年记录所以chenges数组的定义长度需要是102
### 代码

```java
class Solution {
    public int maxAliveYear(int[] birth, int[] death) {
        //因为1990-2000一共101个数字,而且极限情况death[i]=2000的时候,
        //实际上是2001死亡的,所以数组长度加1避免数组越界
        int []chenges=new int[102];
        for(int i=0;i<birth.length;i++){
            //记录出生的人
            chenges[birth[i]-1900]++;
            //记录死亡的人,因为一个人在某一年任意时期都属于活的状态
            //所以死亡的那一年会记录获得统计,真正不计入的是下一年不在记录
            //例如1948年死亡,但是1948年需要统计在生存里面,1949年才会记录这个人死亡了
            //所以死亡的统计是death[i]-1900+1
            chenges[death[i]-1900+1]--;
        }
        int maxAlive=0,currAlive=0,result=0;
        for(int i=0;i<chenges.length;i++){
            currAlive=currAlive+chenges[i];
            if(currAlive>maxAlive){
                maxAlive=currAlive;
                result=1900+i;
            }
        }
        return result;
    }
}
```