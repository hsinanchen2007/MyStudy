### 解题思路
小白折腾很久
先排序，遍历房屋数组，求出每个房屋的最小供暖距离，最后至少保证所有房间都能供暖因此取最大数。
相当于求每个房屋在供暖器数组中的插入位置，分为三种情况：
房屋号小于供暖器最小号，最左边
房屋号大于供暖器最大号，最右边
房屋号位于数组中间，二分法求出插入位置，再求出左右的最小距离
注意，这三种情况是互斥的，因此if/else的逻辑写清楚，一开始没有写清楚一直报错。。。。

### 代码

```java
class Solution {
    public int findRadius(int[] houses, int[] heaters) {
        Arrays.sort(houses);
        Arrays.sort(heaters);
        int len1 = houses.length;
        int len2 = heaters.length;
        int result = 0;
        for(int i=0; i<len1; i++){
            //遍历房屋,找到每一个房屋距离供暖器的最短距离
            int min = 0;
            //最左边
            if(houses[i]<heaters[0]){
                min = heaters[0]-houses[i];
            }
            //最右边
            else if(houses[i]>heaters[len2-1]){
                min = houses[i]-heaters[len2-1];
            }
            else{
                //相当于查找目标元素在供暖器数组中的插入位置
                int left = 0;
                int right = len2-1;
                while(left<right){
                    int mid = left+(right-left)/2;
                    if(heaters[mid]<houses[i]){
                        left = mid+1;
                    }
                    else{
                        right = mid;
                    }
                }
                if(heaters[left] == houses[i]){
                    min=0;
                }
                else{
                    min = Math.min(houses[i]-heaters[left-1],heaters[left]-houses[i]);
                }
            }
            result = Math.max(min, result);
        }
        return result;
    }
}
```