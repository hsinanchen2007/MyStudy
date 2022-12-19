/**
 * Project:
 * Author : zhaozhen
 * Email  :
 * Date   : 2019/9/17
 *
 * 解题思路: 找到每一个房子最近的暖气的距离 然后取这些距离的最大值
 *
 * 注意：先排序 然后使用贪婪策略寻找当前最优质  abs(houses[i] - heaters[j]) 与 abs(houses[i] - heaters[j + 1])比较
 *
 * 如果 abs(houses[i] - heaters[j]) >= abs(houses[i] - heaters[j + 1]) , j++再次进行比较
 * 如果 abs(houses[i] - heaters[j]) < abs(houses[i] - heaters[j + 1]) , 当前第j个暖气距离第i个房间最近,更新最大值
 *
 *  ho1 ho2 ho3 ho4 ho5 ... hoi
 *
 *  he1 he2 he3 he4 he5 ... hej
 *
 * ho1 的位置与he1 和 he2 比较，如果 abs(ho1 - he1) < abs(ho1 - he2) 则 he1 必定距离ho1最近
 *
 *  否则 ho1 的位置与he2 和 he3 比较 重复以上动作
 */

```

public int findRadius(int[] houses, int[] heaters) {
    Arrays.sort(houses);
    Arrays.sort(heaters);

    int j = 0;
    int max = -1;
    for(int i = 0;i < houses.length;i++){
        if((j + 1 < heaters.length) && (Math.abs(houses[i] - heaters[j]) >= Math.abs(houses[i] - heaters[j + 1]))){
            j++;
            i--;
        }else{
            if(max < Math.abs(houses[i] - heaters[j])){
                max = Math.abs(houses[i] - heaters[j]);
            }
        }
    }
    return max;
}

```