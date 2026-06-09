
Project:
Author : zhaozhen
Email  : 
Date   : 2019/9/17

解题思路1: 模拟法 每次都将非最大值的其余数字+1，知道全部的数字相同 会超时

解题思路2: 观察一段数字

           1 2 3
           3 4 3 (+2)
           4 4 4 (+1) 一共3次

           1 2 3 4
           4 5 6 4(+3)
           6 7 6 6(+2)
           7 7 7 7(+1)一共6次

           也就是说，每次将当前最小值 + m_i 使得最小值变成当前最大值，其余的非最大值也 + m_i , 重复当前动作, 知道所有的数字都相等。
           这里可以排序后从最大值开始，当一次叠加之后，次大值会变成最大值。
           所有的 m_i 的和就是要加的次数

 解题思路3:
          基于思路2,发现其实相加的次数和也就是每一个非最小值和最小值的差值的总和
          求出最小值，用每一个数字减去最小值在求和，就是要加的次数



```
 //time out
public int minMoves(int[] nums) {

    int max = Integer.MIN_VALUE;
    int max_index = -1;
    boolean is_over = true;
    int num = 0;
    while(true){
        is_over = true;
        max = nums[0];
        num++;
        for(int i = 0;i < nums.length;i++){
            if(nums[i] > max){
                max = nums[i];
                max_index = i;
                is_over = false;
            }
            nums[i]++;
        }
        if(is_over == true){
            break;
        }else{
            nums[max_index]--;
        }
    }
    return num-1;
}

public int minMoves2(int[] nums) {
    Arrays.sort(nums);
    int count = 0;
    for(int i = nums.length-1;i > 0;i++){
        count += nums[i] - nums[0];
    }
    return count;
}

public int minMoves3(int[] nums) {

    int min = nums[0];
    int count = 0;
    for(int i = 1;i < nums.length;i++){
        if(min > nums[i]){
            min = nums[i];
        }
    }

    for(int i = 0;i < nums.length;i++){
        count += nums[i] - min;
    }

    return count;
}
```