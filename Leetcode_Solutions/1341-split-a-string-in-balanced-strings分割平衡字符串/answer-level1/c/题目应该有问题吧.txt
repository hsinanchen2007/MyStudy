使用C语言写的：
```
int balancedStringSplit(char * s){
    int num = 0, index = 0, leap = 0;
    //有多少个RL/LR边界就有最多多少个数量
    while(index < strlen(s)){
        int target = s[index];
        int next_target = s[index+1];
        if(target == next_target){
            index++;
            leap++;
        }else{
            index+=leap+2;
            num++;
            leap = 0;
        }
    }
    return num;
}
```
而答案是：
![屏幕快照 2019-11-24 16.30.28.png](https://pic.leetcode-cn.com/931c8691d39526e4178191953ce858b70be5f176f376f6b744ddc7640aa3f839-%E5%B1%8F%E5%B9%95%E5%BF%AB%E7%85%A7%202019-11-24%2016.30.28.png)
如果自己算的话也应该是3啊。分别是"RL"、"RRLL"、"RL";
答案怎么得出的两个？是因为使用的贪心的加减法么？感觉题解区包括官方的答案都是错的，两个的结果谁分一下？
