### 解题思路
参考思路：李先森的解法

找到每个房屋离加热器的最短距离（即找出离房屋最近的加热器），然后在所有距离中选出最大的一个即为结果。
即：所有最短距离中的最长值
### 代码

```java
class Solution {
    //思路：找到每个房屋离加热器的最短距离（即找出离房屋最近的加热器），然后在所有距离中选出最大的一个即为结果。
    public int findRadius(int[] houses, int[] heaters) {
        //进行排序
        Arrays.sort(houses);
        Arrays.sort(heaters);
        //记录最终的最短管道距离
        int max = 0;
        //寻找每一个房屋的最近加热器的距离，然后记录这些最短距离中的最大值
        for (int i = 0; i < houses.length; i++) {
            int start = 0;
            int end = heaters.length - 1;
            //二分查找，在heaters中寻找与房屋 c 最近的加热器
            while (start < end) {
                int mid = (start + end) / 2;
                if (houses[i] > heaters[mid]) {
                    start = mid+1;
                } else {
                    end=mid;
                }
            }
            //记录当前选中的这个加热器距离目标房屋的距离（可正可负）
            int len = heaters[start] - houses[i];
            //如果是负的，则说明这是在房屋的左边的第一个加热器
            if (len < 0) {
                max = Math.max(max, -len);
            } else if (len > 0) {
                //分两种情况讨论
                //如果start左边还有start-1，则说明start是右边第一个，start-1是左边最接近的，讨论两个中最近的那个返回
                //如果start是第一个数，则直接让他与max比较
                if (start > 0) {
                    max = Math.max(Math.min(houses[i] - heaters[start - 1], len), max);
                } else {
                    max = Math.max(max, len);
                }
            }
        }
        //max即为所求
        return max;
    }
}
```