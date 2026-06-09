代码相较其他大佬臃肿了，为边界条件也折腾了半天。
时间效率竟然beat 100%


```java
class Solution {
    public boolean canPlaceFlowers(int[] flowerbed, int n) {
        if (n==0) return true;
        if (flowerbed.length == 0) return false;
        int count = 0;
        // zeroNumber记录连续出现0的个数，分为三种情形
        // 1. 头部连续出现0,突然出现1，比如 [0.0.0,1,...
        // 2. 两个1中间夹着的连续的0，比如 ...,1,0,0,0,1,...
        // 3. 1后连续的0直到数组末尾，比如 ...,1,0,0,0]
        // 第一种和第三种情形计算公式一样，第二种不同
        int zeroNumber = 0;
        int i = 0;
        // 从数组头部开始，找连续出现的0个数，一旦出现1就停止
        while(i <flowerbed.length && flowerbed[i]==0){
            zeroNumber++;
            i++;
        }
        // 数组全为0,这个边界没想到
        if (zeroNumber == flowerbed.length) {
            if(zeroNumber>1) {
                count = (zeroNumber%2==0)?(zeroNumber/2):(zeroNumber/2+1);
                return count>=n;
            }else return n<=1;
        }
        // 数组起始端连续0的个数大于1
        if (zeroNumber>1) count += (zeroNumber%2==0)?((zeroNumber-1)/2+1):((zeroNumber-1)/2);
        zeroNumber = 0;
        while(i < flowerbed.length){
            // 找连续的0个数
            // 一旦进入这个循环，表示至少有一个1
            if (flowerbed[i]==0){
                zeroNumber++;
                i++;
                continue;
            }
            // 公式是我试出来的
            if (zeroNumber>1) count += (zeroNumber%2==0)?(zeroNumber/2-1):((zeroNumber-2)/2+1);
            // 更新完count后，zeroNumber重置为0
            zeroNumber = 0;
            i++;
        }
        // 跳出循环了，这步是针对末端连续出现0的情形，公式和头部连续出现0一样
        if (zeroNumber>1) count += (zeroNumber%2==0)?((zeroNumber-1)/2+1):((zeroNumber-1)/2);

        return count>=n;
    }
}
```
