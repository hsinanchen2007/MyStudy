# 分析:

**写在前面：**

本篇题解将运用动态规划的方法去解决此题，并且会尽可能地去分析题目以及解释思路。希望对大家能有所帮助。

**思路：**

初看此题，貌似此题极其简单：只需将分两种路线（一：从第一个开始抢；二：从第二个开始枪）将每个房间都抢劫一次，最后比较两种路线所得金钱，返回所得最多即可。

但细究之下我们将发现实际并不如此。譬如每个房间金额排列是 9、1、1、9 的情况，其最高所得金额应该是 18 而非依上两种方案所得的 10 。

由此来看，情况似乎变得十分复杂。但是，我们稍加分析可以了解到一个事实，那便是只有将所可以偷取的次数都用完才可以偷取到最大金额。并且，在进行偷窃时，无论 偷 与 不偷 都将获取一个 好处 和 坏处。

1. 偷：获取当前房间金钱，但下个房间的金钱将不可得。

2. 不偷：失去当前房间金钱，但下个房间金钱可得。

——综合上述，可以进行以下推测：

假设有一排足够多的房子。当前处于此排房子的某一房子处。有 **甲** 和 **乙** 值代表 [原先基础加上偷了此次房子的金额] 和 [原先基础上偷了上一个房子的金额和下一个房子的金额]。

通过甲和乙的定义并结合前文可知（利益最大化必然将使用所能最大的窃取次数），故当前最优的窃取选择只能在 甲 和 乙 两种方案中产生，甲、乙两值**其一**必然代表了截至 下一个房子 所能窃取的最大金额数（你可能提前需要了解到，这个与后文中的 s(n) 函数性质相似）。

- 如果 甲 > 乙 ，那么说明按照 [乙] 的方式去偷取钱财并不是利益最大的。所以，我们保留 [甲] 值。
- 如果 乙 > 甲 ，说明要想利益最大化必须得按照 [乙] 的方式去偷。所以，我们保留 [乙] 值。

——进一步推想，可得以下逻辑：

假设有一排房子。

**设函数 s(n) 为一排房子中，截至 n 个房子所能得到的最多财物。（切记）**

设函数 f(n) 为第 n 个房子所能得到的财务。

定义变量 x、y。（x 用于存储目前所能达到的最多钱财数，y 用于存储上一步下所能存储的最多钱财数。注意，此定义并不保证 y 一定小于 x，后文会有解释。）

- 如果：s(n) >= s(n - 1) + f(n + 1)
  y = x
  x = s(n)
- 反之（如果：s(n - 1) + f(n + 1) > s(n)）
  y = x 
  x = s(n - 1) + f(n + 1)

我们可以将以上逻辑进行验证，制图表如下：

![捕获.PNG](https://pic.leetcode-cn.com/dc494428bc3902158ed3b3ec92c92c34031d340f200690266e21a8fe0107ae93-%E6%8D%95%E8%8E%B7.PNG)


可见，这个逻辑并不完美。但是我们可以发现：x 的值正是 s(n - 1)代表了而最优解，并且，y 也代表了上一步的 x 值，即 s(n - 2)。而当 n = 1 时，其最优解是可确定的（s(1) = f(1)）。所以，我们可以得出以下逻辑：

- x = f(1)

- 如果：x >= y + f(n + 1)
  y = x
  x = x
- 反之（如果：y + f(n + 1) > x）
  y = x 
  x = y + f(n + 1)

验证逻辑，得表格如下：

![捕获2.PNG](https://pic.leetcode-cn.com/eecd724caba6f1595872c584bdeb32656f8a190fdbe725f02001e5c8156e0de3-%E6%8D%95%E8%8E%B72.PNG)

依照此逻辑，得可得出初步代码：

```csharp []
public int Rob(int[] nums) 
{
    if(nums.Length < 1)
        return 0;;
    //相当于逻辑中的 x
    int currentMoney = nums[0];
    //相当于逻辑中的 y
    int previousMoney = 0;
    for (int i = 1; i < nums.Length; i++)
    {
        int temp = currentMoney;
        //不同于逻辑，由于在代码的实际操作中，我们没有 s(n) 这样的函数。
        //但是，由于我们是按照顺序遍历，所以，currentMoney 实际上相当于 s(n) 。
        //又因为 previousMoney 代表截至 i - 1 的所能得到的最多钱财，所以 previousMoney 等价于 s(n - 1)
        if(currentMoney >= previousMoney + nums[i])
            currentMoney = currentMoney;
        else
            currentMoney = previousMoney + nums[i];;
        previousMoney = temp;
    }
    return currentMoney;
}
```
```cpp []
public: 
    int rob(vector<int>& nums) {
        if(nums.size() < 1)
            return 0;;
        //相当于逻辑中的 x        
        int currentMoney = nums[0];
        //相当于逻辑中的 y
        int previousMoney = 0;
        for (int i = 1; i < nums.size(); i++){
            int temp = currentMoney;
            //不同于逻辑，由于在代码的实际操作中，我们没有 s(n) 这样的函数。
            //但是，由于我们是按照顺序遍历，所以，currentMoney 实际上相当于 s(n) 。
            //又因为 previousMoney 代表截至 i - 1 的所能得到的最多钱财，所以 previousMoney 等价于 s(n - 1)
            if(currentMoney >= previousMoney + nums[i])
                currentMoney = currentMoney;
            else
                currentMoney = previousMoney + nums[i];;
            previousMoney = temp;
        }
        return currentMoney;
    }
```

*注意，循环中，i 的初始值为 1 ！

细心的你可能会发现，如果 i = 0，currentMoney = 0 时，那么，这次循环后，currentMoney 的值将正好等于 nums[0] !

优化代码如下：

```csharp []
public int Rob(int[] nums) 
{
    //相当于逻辑中的 x
    int currentMoney = 0;
    //相当于逻辑中的 y
    int previousMoney = 0;
    for (int i = 0; i < nums.Length; i++)
    {
        int temp = currentMoney;
        //不同于逻辑，由于在代码的实际操作中，我们没有 s(n) 这样的函数。
        //但是，由于我们是按照顺序遍历，所以，currentMoney 实际上相当于 s(n) 。
        //又因为 previousMoney 代表截至 i - 1 的所能得到的最多钱财，所以 previousMoney 等价于 s(n - 1)
        currentMoney = Math.Max(currentMoney,previousMoney + nums[i]);
        previousMoney = temp;
    }
    return currentMoney;
}
```
```cpp []
public: 
    int rob(vector<int>& nums) {
        //相当于逻辑中的 x        
        int currentMoney = 0;
        //相当于逻辑中的 y
        int previousMoney = 0;
        for(int i = 0; i < nums.size(); i++){
    	    int temp = currentMoney;
            //不同于逻辑，由于在代码的实际操作中，我们没有 s(n) 这样的函数。
            //但是，由于我们是按照顺序遍历，所以，currentMoney 实际上相当于 s(n) 。
            //又因为 previousMoney 代表截至 i - 1 的所能得到的最多钱财，所以 previousMoney 等价于 s(n - 1)
    	    currentMoney = max(currentMoney, previousMoney + nums[i]);
    	    previousMoney = temp;
        }
        return currentMoney;
    }
```

**结尾：**

由于个人能力所限，难以将题解写得尽善尽美，如有不足之处，请各位海涵，并能不吝赐教。

————————————————————————————

编辑历史：

1. 二零一九年八月五日：增加验证逻辑环节、图标分析，补充代码过渡及优化原因，修改部分文字及表述错误。