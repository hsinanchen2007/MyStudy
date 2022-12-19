广义期望最大算法（Gerneralized Expectation Maximization）:在数据不完全或者缺失变量的情况下参数估计的***迭代算法**。算法的每一次迭代是由**期望（Expectation）*和极大（Maximization）两步操作构成，也是一种广义的***渐进逼近的最优化算法***。在定义一个最优化函数后，主要分为以下两步：（1）根据参数调整模型（E步）  （2）根据模型调整参数（M步）,E步和M步交替进行，直至得到最优解（迭代至收敛时，即遍历完成后，M为所求最优解）。

说明：以上为GEM的概述，我们只采取其部分思想用于解题。详细的GEM算法另请高明。

应用范围：求最优解

问题分析:(1)最大利润即为M,而买卖时机则为E。同时我们在进行最优操作之前假设已经知道E和M,但是此时的E,M为最糟糕的情况（期望最低，最优解为最劣解），才能在进行迭代时对E,M                   进行调整。
        (2)通过迭代来计算是否有更优的E,M可以来替代我们估计的E,M。主要有两步:
            a.计算期望：新Expectation比最优Expectation更优，则调整，否则不变。
            b.计算最大：新Maximization比最优Maximization更优，则调整，否则不变。
        (3)到达或逼近收敛时，结束迭代，此时的E,M即为最优解。M即为所求的最大利润。

运用：根据已知条件，确定什么为Expectation,什么为Maximization。然后估计E和M的值，再通过迭代对E和M进行调整，收敛时即的得到最优解。

![pic.jpg](https://pic.leetcode-cn.com/fa8d4ee8cf3f0fdd6242d4df60fd575db4568bd995991b6045695e877c19a859-pic.jpg)

int maxProfit(int* price,int priceSize){
    
    if(priceSize<2) return 0;

    int max=0,expt=INT_INT;     //初始化E，M为最槽糕的情况

    //执行E步和M步，直到逼近或到达收敛时
    for(int i=0;i<prieSize;++i){
        //计算期望，判断是否调整
        if(price[i]<expt)   
            expt=price[i];
        //计算最大，判断是否调整
        else if(max<price[i]-expt)
            max=price[i]-expt;
    }   //迭代结束时，expt,max即为最优解
    return max;
}



附：学艺不精，还望各位海涵，并对文中不足的地方进行批评和补充，鄙人洗耳恭听，谢谢！！！

