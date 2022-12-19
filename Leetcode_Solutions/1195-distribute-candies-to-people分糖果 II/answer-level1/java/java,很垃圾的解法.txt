### 解题思路
此处撰写解题思路

### 代码

```java
class Solution {
     /**
        i代表数组的位置times表示第几轮从0开始计时
        由提可以推理出当前元素的值curr=result[i] + times * result.length + i + 1;
        当candies=0时候说明糖已经分完了跳出循环
        否则将计算的curr的值赋值到result[i]中并且重置candies,
        candies = candies - curr + result[i];
        result[i]代表覆盖之前的时候result[i]的值,
        因为当前值curr包含了之前的result[i],所以需要加回来避免减两次
        如果curr - result[i]>candies说明糖果不够这次分配,
        直接将剩余的糖果都分配到result[i]中,candies置为0跳出循环
    */
    public int[] distributeCandies(int candies, int num_people) {
        int[]result=new int[num_people];
        //记录第几轮
        int times=0;
        while(candies>0){
            for(int i=0;i<num_people;i++){
                ////计算i对应的curr的值
                int curr=result[i]+num_people*times+i+1;
                ////判断当前candies糖果是否够此次分配
                if(curr-result[i]>candies){
                    //不够分配,直接将当前所有的糖果都给result[i]
                    result[i]=candies+result[i];
                    candies=0;
                    break;
                }else{
                    ////够分配,重新计算candies,因为curr已经包含了 result[i]所以需要加回来
                    candies=candies-curr+result[i];
                    result[i]=curr;
                }
            }
            times++;
        }
        return result;
    }
}
```