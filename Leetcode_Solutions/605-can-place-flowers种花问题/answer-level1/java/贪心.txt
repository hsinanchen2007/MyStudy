### 解题思路
此处撰写解题思路
寻找等于0的那个位置，并找出它的前驱和后继，若都是零，则可以在此种花，然后将此地变为1，依次向后寻找。
### 代码

```java
class Solution {
    public boolean canPlaceFlowers(int[] flowerbed, int n) {
        int num=0;
        for(int i=0;i<flowerbed.length;i++){
            if(flowerbed[i]==0){
            int pre=i==0?0:flowerbed[i-1];
            int lat=i==flowerbed.length-1?0:flowerbed[i+1];
            if(pre==0&&lat==0){
            num++;
            flowerbed[i]=1;}
            }
        }
        return num>=n;
    }
}
```