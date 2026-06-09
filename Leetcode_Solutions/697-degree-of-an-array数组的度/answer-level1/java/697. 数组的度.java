/**
 * Project:
 * Author : zhaozhen
 * Email  :
 * Date   : 2019/10/8
 *
 *  解题思路: 获取当前串的度 然后最大度对应的数值的最大 最小 索引值相减 + 1 即为相同的度的最小连续字串
 *
 *  注意： 1. 会存在最大度对应多个数值 此时取 (最大索引- 最小索引 + 1) 最小的字串
 *        2. java 结构体通常使用的是class 来创建 在实际过程中 常常使用多个线性数组来标识 索引一一对应
 *
 */
```
public int findShortestSubArray(int[] nums) {

    //线性结构体
    int[] num = new int[50001];
    int[] start = new int[50001];
    int[] end = new int[50001];

    //初始化边界值
    for(int i = 0;i < num.length;i++){
        num[i] = 0; //每个数的个数 初始为0
        start[i] = 50001; //当前数的起始位置
        end[i] = -1; //当前数的结束位置
    }


    for(int i = 0;i < nums.length;i++){
        //起始位置只更新一次
        if(start[nums[i]] == 50001){
            start[nums[i]] = i;
        }

        //更新结束位置 和 数值的数量
        end[nums[i]]=i;
        num[nums[i]]++;
    }

    //遍历结果获取相同度的最短连续串的长度
    int max_num = num[0];
    int min_bw = end[0] - start[0] + 1;
    for(int i = 1;i < num.length;i++){
        //数的个数较大 直接更新
        if(max_num < num[i]){
            max_num = num[i];
            min_bw =  end[i] - start[i] + 1;
        }else if(max_num == num[i]){
            //数值相等 取较短的连续串的长度
            if(min_bw > end[i] - start[i] + 1){
                min_bw =  end[i] - start[i] + 1;
            }
        }
    }

    return min_bw;
}
```