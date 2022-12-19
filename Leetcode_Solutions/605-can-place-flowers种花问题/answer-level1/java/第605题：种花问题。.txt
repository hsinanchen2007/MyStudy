此法时间复杂度是O（n），空间复杂度是O（1）
该问题难点是判断该位置能够种花，能则使count加一，不能就不加，最后n小于count则返回true。
我的判断法是：
1.设置一个标志位tag，含义是上一个位置是否可以种花，可以则为1，不能则为0.
2.如果此位置没有种花，且上一个位置也没有种花，则使count加一，标记位tag置1，代表此位置可以种花。
3.如果此位置已种花，且上一个位置也种了花，代表上一个位置不该种花，是count减1，标志位tag置1，代表此位置已种花。
4.如果此位置已种花，且上一个位置没有种花，不操作count，置标记位tag=1，代表此位置已种花
5.如果此位置没有种花，且上一个位置已种花，不操作count，置标记位tag=0，代表此位置不种花。
代码实现如下：
```
class Solution {
    public boolean canPlaceFlowers(int[] flowerbed, int n) {
        int tag=0;
        int count=0;
        for(int i=0;i<flowerbed.length;i++){
            if(flowerbed[i]==0&&tag==0){
                count++;
                tag=1;
                continue;
            }
            if(flowerbed[i]==1&&tag==1){
                count--;
                tag=1;
                continue;
            }
            if(flowerbed[i]==1&&tag==0){
                tag=1;
            }
            else{
                tag=0;
            }
        }
        return count>=n;
    }
}
```