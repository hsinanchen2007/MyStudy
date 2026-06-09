### 解题思路
1.新建一个数组保存每个孩子的糖果数，开始全部给每个小孩都发一个糖；
2.第一次遍历先从左向右 若右边的孩子评分比左边高 则右边的糖果数等于左边的糖果数加一
3.第二次遍历先从右向左 若左边的孩子评分比右边高且左边的孩子糖果数小于等于右边的  则左边的糖果数等于右   边的糖果数加一  同时求和

### 代码

```java
class Solution {
    public int candy(int[] ratings) {
        int[] candy = new int[ratings.length];
        // Arrays.fill(candy, 1);  
        for(int i =0 ; i<ratings.length ; i++) candy[i]=1;    //开始全部给每个小孩都发一个糖
        //两次遍历
        //第一次遍历先从左向右 若右边的孩子评分比左边高 则右边的糖果数等于左边的糖果数加一
        for(int i =1 ; i<ratings.length ; i++){
            if(ratings[i]>ratings[i-1]){
                candy[i]=candy[i-1]+1;
            }
        }
        int sum=0;   //保存分发的糖果数
        //第二次遍历先从右向左 若左边的孩子评分比右边高且左边的孩子糖果数小于等于右边的
        //则左边的糖果数等于右边的糖果数加一  同时求和
        for(int i = ratings.length-1;i>0; i--){
           if( ratings[i-1]> ratings[i] && candy[i-1]<= candy[i] ) candy[i-1]=candy[i]+1;
            sum+=candy[i];
        }
    return sum+candy[0];
    }
}
```