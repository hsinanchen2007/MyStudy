```
class Solution {
    public int numTimesAllBlue(int[] light) {
        int len = light.length;
        boolean[] flags = new boolean[len]; // 初始化一个标记数组，用来标记所有灯亮的情况
        int count = 0;
        int maxRightIndex = 0; // 记录检查连续为开着的灯的最右边的位置，用来从这个位置向左边遍历看是否连续的灯都开着的
        for (int i = 0; i < len; i++){
            flags[light[i] - 1] = true; // 标记当前位置的灯为开着的，之所以要-1是因为等是从1开始的，而数组是从0开始的，所以在这里维护一下
            maxRightIndex = light[i] - 1 > maxRightIndex ? light[i] - 1 : maxRightIndex; // 记录当前出现的左右边的灯亮的位置
            int curIndex = maxRightIndex;
            boolean flag = true; // 初始标记目前全都是连续的灯亮着
            while (curIndex >= 0){ // 从记录的最右边的灯向左开始遍历，看是否都是开着的
                if (!flags[curIndex]){ // 如果出现一个没有开着的表示这一次亮灯后，目前全部亮的不都是蓝色的！
                    flag = false;
                    break;
                }
                curIndex--;
            }
            if (flag) count++; // 如果连续的灯都亮着，那就次数+1
        }

        return count;
    }
}
```
