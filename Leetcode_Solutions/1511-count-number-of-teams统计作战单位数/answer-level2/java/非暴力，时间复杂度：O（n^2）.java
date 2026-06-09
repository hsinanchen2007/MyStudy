### 解题思路
分两次进行排序，第一次排序（第一个士兵<（>）第二个士兵），第二次排序（第二个士兵<(>)第三个士兵）
以递增排序来说，第一次排序存放在ins数组里的是第二个士兵的下标，
第二次排序就从第二个士兵的下标的下一位进行比较，如果大于第二个士兵的rating值，count就++。

### 代码

```java
class Solution {
    public int numTeams(int[] rating) {
        int count=0;
        int count1=0;//计算存入递增数组的元素个数
        int count2=0;//计算存入递减数组的元素个数
        int ins[]=new int[rating.length*rating.length];
        int dec[]=new int[rating.length*rating.length];
        //第一回递增，递减比较（作战单位第一，二个士兵有序）
         for(int i=0;i<rating.length;i++){
             for(int j=i+1;j<rating.length;j++){
                 if(rating[i]<rating[j]){
                    ins[count1++]=j;//递增数组存放j的下标
                 }else if(rating[i]>rating[j]){
                     dec[count2++]=j;//递减数组存放j的下标
                 }
             }
         }
         //第二回递增递减比较
         for(int i=0;i<count1;i++){
             for(int k=ins[i]+1;k<rating.length;k++){//此时比较应该从ins[i](即第二个士兵）的下个士兵开始
                 // 与第二个士兵的rating值进行比较，大于第二个士兵，count就++
                 if(rating[k]>rating[ins[i]]){
                     count++;
                 }
             }
         }
        for(int i=0;i<count2;i++){
            for(int k=dec[i]+1;k<rating.length;k++){
                if(rating[k]<rating[dec[i]]){
                    count++;
                }
            }
        }
        return count;
    }
}
```