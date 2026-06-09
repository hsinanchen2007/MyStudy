### 解题思路
    /*
     * 方法 动态规划
     *
     * 整数翻译的字符串的种数因为有两种翻译方式，
     * 类似于青蛙跳台阶，后一种状态值由前两种状态值决定。
     * 这是一种递归的思想，考虑到重复性，可以归结为动态规划。
     *
     * 动态规划的状态转移方程为： dp[i] =
     *     1. dp[i-1]            当num[i]和num[i-1]不能翻译为一个字符时
     *     2. dp[i-1]+dp[i-2]    当num[i-1]和num[i-2]能翻译为一个字符时
     *
     * 根据状态方程，需要先初始化初始状态值dp[1]和dp[2]，
     * 之后再根据方程公式进行判断即可。
     * */
### 代码

```cpp
int translateNum(int num) {
    // num小于0，不可翻译
    if(num < 0){
        return 0;
    }

    // num只有一个数字，也就只有一种翻译
    if(num < 10){
        return 1;
    }

    // 将num转化为字符串，方便判断
    std::string numStr = std::to_string(num);

    // 存储状态的数组
    int* dp = new int[numStr.length()];

    // 初始化初始状态
    dp[0] = 1;

    if(numStr[0] == '0' || numStr.substr(0, 2) > "25"){
        dp[1] = 1;
    }else{
        dp[1] = 2;
    }

    // 根据状态方程，求每个字符下的翻译种数
    for(int i = 2; i < numStr.length(); i++){
        // 前一个字符为0或两个字符合并大于25时，
        // 当前字符下的翻译种数等于前一字符下的翻译种数
        if(numStr[i-1] == '0' || numStr.substr(i-1, 2) > "25"){
            dp[i] = dp[i-1];
        }else{
            // 当前字符下的翻译种数等于前一字符下的翻译种数
            // 加上前前一字符下的翻译种数
            dp[i] = dp[i-1]+dp[i-2];
        }
    }

    // 保存最终结果
    int count = dp[numStr.length()-1];

    // 释放数组
    delete []dp;
    // 避免野指针
    dp = nullptr;

    return count;
}

```