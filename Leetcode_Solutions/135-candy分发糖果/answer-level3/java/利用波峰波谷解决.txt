### 解题思路
在纸上将`ratings[]`绘制成折线图就很清晰明了了。
对于概率处于波谷的小孩：分配到的最小糖果数量绝对是1
对于概率处于波峰的小孩：分配到的最小糖果数取决于其左右两个斜坡，孩子数量多的斜坡决定了波峰的值。
例如假设有一个长度为6的`ratings`数据[0,1,3,5,4,3]
显然`ratings[3]`是波峰，`ratings[0]`与`ratings[5]`都是波谷为1。左斜坡：`ratings[0]~ratings[2]`一共有3个小孩，右斜坡`ratings[4]~ratings[5]`一共有2个小孩。所以波峰小孩`candy[3]`需要的糖果数从左波谷开始不断加1,到波峰时，`candy[3]=4`;

### 代码
//代码写地实在不球，大家知道波峰波谷这个思想就好。
```java
class Solution {
    public int candy(int[] ratings) {
        if(ratings.length==1)return 1;
        
        int sum=0;
        for(int i=1;i<ratings.length;)
        {
            int up=0,down=0;
            //upstair
            while(i<ratings.length&&ratings[i]>ratings[i-1]){up++;i++;}
            //downstair
            while(i<ratings.length&&ratings[i]<ratings[i-1]){down++;i++;}
            //fair
            while(i<ratings.length&&ratings[i]==ratings[i-1]){sum++;i++;}
            
            //System.out.println(up+","+down);
            int max=Math.max(up,down);
            int min=Math.min(up,down);
            if(max==min)
                sum=sum+(1+max)*max+max;
            else
                sum=sum+(2+max)*(max+1)/2+(1+min)*min/2-1;
            
        }
        
        return sum+1;
    }
}
```