### 解题思路


### 代码

```java
class Solution {
    public int candy(int[] ratings) {
        int cd[]=new int[ratings.length];
        cd[0]=1;//默认最左值为谷底
        for(int i=1;i<ratings.length;i++){//第一次遍历从左向右搜递增连续序列
            if(ratings[i]>ratings[i-1])cd[i]=cd[i-1]+1;
            else if(i==ratings.length-1||ratings[i]<=ratings[i-1]&&ratings[i]<=ratings[i+1])cd[i]=1;
        }
        for(int i=ratings.length-2;i>=0;i--){//从有向左搜递增序列
            if(ratings[i]>ratings[i+1])cd[i]=cd[i]>cd[i+1]+1?cd[i]:cd[i+1]+1;//取第一次与右边一个节点+1的较大值
        }
        int res=0;
        for(int i=0;i<cd.length;i++)res+=cd[i];//累加糖果
        return res;
    }
}
```