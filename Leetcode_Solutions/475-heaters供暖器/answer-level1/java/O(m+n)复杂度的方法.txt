
```java []
class Solution {
    public int findRadius(int[] houses, int[] heaters) {
        Arrays.sort(houses); //对两个数组排序
        Arrays.sort(heaters);
        int max = 0;
        int temp = 0;
        //从头开始遍历两个数组，每次只有一个下标+1
        for (int i = 0, j = 0; i < houses.length && j < heaters.length; ) {
            if (houses[i] <= heaters[j]) {
                temp = heaters[j] - houses[i];
                i++;
            } else if (j < heaters.length - 1) {
                temp = Math.min(heaters[j+1] - houses[i], houses[i] - heaters[j]);
                if (houses[i] < heaters[j + 1]) {
                    i++;
                } else {
                    j ++;
                }
            } else if (j == heaters.length - 1) {
                temp = houses[i] - heaters[j];
                i++;
            }
            max = max > temp ? max : temp;
        }
        return max;
    }
}
```
