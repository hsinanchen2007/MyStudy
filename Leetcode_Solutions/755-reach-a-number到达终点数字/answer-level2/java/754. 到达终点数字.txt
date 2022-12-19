/**
 * Project:
 * Author : zhaozhen
 * Email  : 2399144252@qq.com
 * Date   : 2019/10/11
 *
 * 解题思路: 该题通过的分析后得出规律
 *
 *1.发现向左移动和享有移动是对称的 对target取绝对值
 *2.最理想的状态是一直向右走 遇到target (但会遇到超过这个target 因此需要想左微调)
 *3.当最终的sum == target 时 直接返回 step
 *4.当最终的sum >  target (diff = sum -target)时
 * 4.1 diff 为偶数 diff/2这个数要向右走, 相当于在sum的基础上减去diff这个数,总步数为step
 * 4.2 diff 为奇数 这个时候要看 step: step 为偶数,再走1步(step+1),因为要把4.2的情况转化为4.1的情况,diff为奇数,step为偶数,下一步为奇数,相当于再走一步sum-target为奇数,转到4.1; step:为奇数,走2步(step+2),,diff为奇数,step为奇数,下一步为偶数,相当于再走一步sum-target为偶数,必须再走两步才能使sum-target为奇数,转到4.1
 *
 * 例如：(目标 让diff为偶数)
 *  1(1) 3(2) 6(3) 10(4) 15(5)  target=4  当sum == 6 , step==3时,step > taget , diff = (6-5)=2 为偶数  return step (相当于当diff/2=1 向左走 -2)
 *  1(1) 3(2) 6(3) 10(4) 15(5)  target=7  当sum == 10 ,step==4时,step > taget , diff = (10-7)=3 为奇数 step为偶数, return step + 1 (相当于再走1步 sum==15 diff为偶数 转化为4.1情况)
 *  1(1) 3(2) 6(3) 10(4) 15(5)  target=5  当sum == 6 , step==3时,step > taget , diff = (6-5)=1 为奇数 step为奇数, return step + 2 (相当于再走2步 sum==15 diff为偶数 转化为4.1情况)
 *
 * 注意: 代码还可以简化 但以下代码更容易理解
 *
 *
 */
```
public int reachNumber(int target) {

    //对称 绝对值
    target = Math.abs(target);

    //步数
    int step = 0;
    //当前位置
    int sum = 0;
    //sum == target || sum > target
    while(sum < target){
        step++;
        sum += step;
    }

    //sum == target || diff偶数
    if((sum - target) % 2 == 0){
        return step;
    }else if(step % 2 == 0){// diff 为奇数 step为偶数
        return step + 1;
    }else{
        return step + 2;//diff 为奇数 step为奇数
    }
}
```