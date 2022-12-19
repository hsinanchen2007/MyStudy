### 解题思路
以下为本人的解题思路，由于本人没有看官方和各位大神的解法，如有雷同，还属班门弄斧，见谅!
此题很难，并不是难在想到用动态规划的思想来做，
而是难在如何考虑子问题、处理顺序和状态转移方程。

我们先将题目的要求转述为
“在任意时刻，骑士的生命值x都大于等于1”

接下来，我们按题目要求定义，假设地牢的尺寸为{m x n}
**

DP[i][j]的含义是，使得 骑士从i,j出发走到右下角这一全部过程中血量都不小于1的 最初血量，最后求得DP[0][0]即可
**

那么是从左上到右下，还是从右下到左上呢？
我们先待定
我们假设骑士的初始生命值为x，并用a表示地牢二维矩阵

根据通常的二维数组移动的动态规划的经验
我们还是将问题先简化，分为以下三种情况

1、如果地牢的尺寸为{1x1}（仅有1个格子）
此时，我们不需要考虑子问题求解的方向
骑士只需要进入唯一房间中，并在生命值与这个房子发生交互后，还保持至少为1的血量
即
![image.png](https://pic.leetcode-cn.com/ab31f094d2e1885613b743a1ca9ea9f42dc427f47af2382bcdc1b1cebf2274cf-image.png)

解得
![image.png](https://pic.leetcode-cn.com/4dd253d52ff399f7e3825605a433f697ec85320d5fd034b4bc879702da19e86f-image.png)


由于我们需要求得初始生命可行的最低值，我们可以将max前面直接取等号

2、如果地牢的尺寸为{1 x n}或{m x 1}
此时，我们需要考虑子问题求解的方向！

我们以一个{1 x n}（1行n列）的地牢为例
这个地牢的a为
![image.png](https://pic.leetcode-cn.com/91ecd30136a7397a707de8039f6849f7ddc3de133a9506c91f68e14d68b63895-image.png)


假设我们从左上(a[0][0])到右下(a[0][n-1])
走过第一个格子，类似上面的”1、“
有
![image.png](https://pic.leetcode-cn.com/4c6481813c954edebd86f96f4a25a1dbfb3384194def4963b967328271f72207-image.png)

但此时，如果不知道a[0][1]~a[0][n-1]的值
我们便无推得dp[0][0]的值，因为我们不知道后面的格子，也就无法确定初始生命值

因此，我们必须考虑从右下往左上演化！
因此，我们先考虑若从最后一个格子a[0][n-1]出发，由于也引发一次生命值交互，
所以，类似”1、“，有
![image.png](https://pic.leetcode-cn.com/2e24ce2ddc914334de3fc4bdaf34c19479bedc9a3d92ec57ded6bcbc0984d1a4-image.png)

我们将起点左移至a[0][n-2]
若以生命值x从a[0][n-2]出发，则要求
![image.png](https://pic.leetcode-cn.com/61d8748674f33eefb7342ecd5a78fbc48c9c2734bb5459a31f4ed425621c8b91-image.png)

我们将上面的第三行移项，得到
![image.png](https://pic.leetcode-cn.com/73fb6762f17f45a944f8f0f1fa1c56e5efbbb99c2289b4ecee7683166b6f674d-image.png)

于是，我们可以将第二行式子和第三行式子合并，得到如下结果
![image.png](https://pic.leetcode-cn.com/4cbd512859459ee8377abf6e91da142d1c9283c6364bb6675097033188b10dc8-image.png)


这个时候，我们奇迹般地发现，合并后右边的式子，不就是DP[0][n-1]吗？？
因此，我们将DP[0][n-1]代入，得到
![image.png](https://pic.leetcode-cn.com/f1f3e8993ae19c41c348cf54757e72a0dd32e661b28f2cce209d0e4ac1b8f4c4-image.png)

我们再将第二行式子的a[0][n-2]移项，得到
![image.png](https://pic.leetcode-cn.com/8e1f7e493c4df37aac5bee0ae6ea7b0bebcd15d36c69ecf3110b859650347b1a-image.png)

易得
![image.png](https://pic.leetcode-cn.com/ccdcdabada7faf7468d70bfa06857e2754b5a76f952f29805d828ecbfb7d166a-image.png)

要想得到最低要求，取等号，得
![image.png](https://pic.leetcode-cn.com/1a5351c817d73e8b20c39ddc75d9fa678f963a491820d7731aa11ced81b1356c-image.png)

对于这个式子，我们推广到这种形状地牢的一般化结论
![image.png](https://pic.leetcode-cn.com/edf922e29d31e85f8fb47bee6ca88e5e182dac572ab987d9922aa71c1c938fa2-image.png)


同理，对于{m x 1}（m行1列）的地牢，我们能推得类似的结论
![image.png](https://pic.leetcode-cn.com/ecf6a00bb498f16dd5a9369acb853fa6ebc08666fc95a3b3c0a741c2a48be7e5-image.png)


这样，我们便解决了一行多列，或一列多行的情况

3、一般情况，即{m x n}(地牢有m行n列，二者都＞1)
由于我们在”2、“中已经得出结论：
在只能选择右移或者下移的前提下，
单行或单列的地牢中，每个格子的DP值只与这一行或这一列有关

即便是m行n列，
如果我们从最后一行出发，那么我们只有一条路线，即一直往右（与其它行的a的数值无关了），
如果我们从最后一列出发，那么我们只有一条路线，即一直往下（与其它列的a的数值无关了），
因此，我们将m行n列中最下面一行和最右面一列，按照”2、“中最后的两个式子初始化

也就是说，要填充DP矩阵，
我们可以根据上面得到的结论，先将下图中灰色部分初始化
![image.png](https://pic.leetcode-cn.com/4db527c70852f8749d01ce4a4f25ff184db6cf0682ef3631cff7fafbffd2410c-image.png)

接下来，我们从a[m-2][n-2]开始填充，可以先填充第m-2行，也可以先填充第n-2列
我们以先填充第m-2行为例，如下所示（此后，我们使用绿色表示已经初始化的格子）
![image.png](https://pic.leetcode-cn.com/66656b287ae4dcb38bc0b812c0b652567b0fed6119a5391485845587d501a842-image.png)

根据处理这类问题的经验，我们将子问题锁定在一个局部的2x2格子中
按照上图的顺序，我们每一次操作都能保证待求DP值的格子i,j的下方、右方和右下方的DP值都是已知
如下图所示
![image.png](https://pic.leetcode-cn.com/eb795c65fa526c1da8da317fd39238e019ff0d1477af52dadd1df05f85c0ed44-image.png)


则 从i,j到i+1,j+1，我们只有两种选择，分别是
（1）i,j —— 下移——> i+1,j—— 右移——>i+1,j+1
（2）i,j —— 右移——> i,j+1—— 下移——>i+1,j+1
若为（1），
假设初始生命为x,有
![image.png](https://pic.leetcode-cn.com/8eb59680483dfa2f86b9f6772e87fbf942e103fe5e62f6f89dce5b624c170f2b-image.png)

它的含义为，初始生命不低于1，经过i,j还不低于1且不低于i+1,j所需的最低要求值

因此
![image.png](https://pic.leetcode-cn.com/ce703351c519ee9ef9210f37fa0cf603619d1df377a7400de9f9fba4b2f9a05e-image.png)

考虑到上面的递推公式，能确保已经求得的DP均不小于1（也可理解为最初血量必定不小于1）
上式可简化为
![image.png](https://pic.leetcode-cn.com/74ba9bedb90b04452845f6f2ec1443bd8c2b27b4dc45d1a1a6edf64f25ceb32f-image.png)

若为(2)，同理，有
![image.png](https://pic.leetcode-cn.com/763e5679a8cabb957c24b192e867008d6b15b86e6ff94bcd329f2675f3800fd9-image.png)


接下来是关键，因为有两条道路可以走，我们要寻得的是最低要求值，
因此，只要有一条满足生命值大于等于1即可，因此，我们将上面两个不等式取或，
即让x大于等于两个max中较小的一个即可

即，当 0 ≤ i ≤ m - 2， 0 ≤ j ≤ n - 2时
![image.png](https://pic.leetcode-cn.com/79af71fe8372fbdbaad4d1f5d2fc25bea0f4cbf12a098a12d7e19e03133623d4-image.png)

当i = m - 1时
![image.png](https://pic.leetcode-cn.com/5c980f69f885b3bf76f33474c40267bbca7e4595f6940af55ec5a48e971cd932-image.png)

当j = n - 1时
![image.png](https://pic.leetcode-cn.com/ca54ce9b37c32c9dcb4cc40ad99f4f4d14e51691917704d41c9eefc35694e7a8-image.png)

这样，我们便得到了动态规划的状态转移方程


### 代码

```python3
class Solution:
    def calculateMinimumHP(self, dungeon: List[List[int]]) -> int:
        m = len(dungeon)
        n = len(dungeon[0])
        if m == 1 and n == 1:#1x1的地牢
            return max(1,1-dungeon[0][0])
        elif m == 1 and n != 1:#1xn的地牢
            newlist = []
            for i in range(n):
                newlist.append(-1)
            newlist[-1] = max(1,1-dungeon[0][-1])
            for i in range(n-1):
                tempindex = n - i - 2
                newlist[tempindex] = max(1,newlist[tempindex+1] - dungeon[0][tempindex])
            return newlist[0]
        elif m != 1 and n == 1:#nx1的地牢
            newlist = []
            for i in range(m):
                newlist.append(-1)
            newlist[-1] = max(1,1-dungeon[-1][0])
            for i in range(m-1):
                tempindex = m - i - 2
                newlist[tempindex] = max(1,newlist[tempindex+1] - dungeon[tempindex][0])
            return newlist[0]
        #以下针对mxn的地牢，m和n都大于1
        #初始化一个m行n列的dplist
        print('地牢的size为',m,n)
        newlist = []
        for i in range(m):
            templist = []
            for j in range(n):
                templist.append(-1)            
            newlist.append(templist)
        #我们先初始化最下面一行和最右边一列
        #先初始化最右下角的
        newlist[m-1][n-1] = max(1,1 - dungeon[-1][-1])
        tempinit = newlist[-1][-1]
        #最下面一行，共n-1个待补充的数字
        for i in range(n-1):
            tempindex = n - i - 2
            newlist[-1][tempindex] = max(1,newlist[-1][tempindex+1] - dungeon[-1][tempindex])
        #最右边一列，共m-1个待补充的数字
        for j in range(m-1):
            tempindex = m - j - 2
            newlist[tempindex][-1] = max(1,newlist[tempindex+1][-1] - dungeon[tempindex][-1])
        #从[m-2][n-2]开始填充,一直到[0][0],共(m-1)x(n-1)个
        #先从倒数第二行倒数第二列开始，然后是倒数第二行倒数第三列，......
        for i in range(m-1):
            tempi = m - i - 2
            for j in range(n-1):
                tempj = n - j - 2
                newlist[tempi][tempj] = max(1,min(newlist[tempi+1][tempj],newlist[tempi][tempj+1])-dungeon[tempi][tempj])
        print(newlist)
        return newlist[0][0]
```