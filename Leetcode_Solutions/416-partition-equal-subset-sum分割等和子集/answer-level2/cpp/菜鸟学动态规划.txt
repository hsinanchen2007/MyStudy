## 引入

这道题目是一个典型的动态规划问题。但是我并不会动态规划，大佬们讲的方法，都是默认已经掌握了动态规划问题的处理方法来讲解。不明真相的我看也看不懂。

因此，我们通过这一道题来理解动态规划中01背包问题的解决原理。

## 1 解决

### 1.1 从枚举开始

最容易想到（甚至不用想就可以得到）的是枚举法。代码我们不再赘述。这样操作的时间复杂度是 $O(n2^n)$ 。主数组中的元素，要么包含、要么不包含在子数组中。枚举每一个可能的子数组，再对数组进行求和，就得到了我们的答案。

但是这样的复杂度是很难让人（和判断程序）接受的。它甚至比指数复杂度还要大。

我们观察这样的过程，找一找可以优化的步骤。我们发现，这样进行了大量的重复求和。从{1,2,3,4,5}到{1,2,3,4,5,6}，我们可以用一些方法来保存{1,2,3,4,5}的加和，就可以节约这些时间。

### 1.2 分治法

这里的分治，实际上仍然是对于主数组的枚举，因此在枚举上的复杂度（ $O(2^n)$ ）是不变的。请看下面这段代码：
```cpp
//0.1 divide and conquer TLE
class Solution {
public:
    bool canPartition(vector<int>::iterator begin, vector<int>::iterator end, int sum) {
        if (begin == end)
            return false;
        if (*begin == sum)
            return true;
        if (*begin > sum)
            return false;
        return canPartition(begin + 1, end, sum - *begin) || canPartition(begin + 1, end, sum);
    }

    bool canPartition(vector<int>& nums) {
        auto it = nums.begin();
        int sum = 0;
        for (; it < nums.end(); it++)
            sum += *it;
        //--------------------------------------------
        if (sum & 1)
            return false;//这里是比较小的一步优化，
            //因为奇数和不可能被分割，就直接得到答案。
        //--------------------------------------------
        it      = nums.begin();
        auto end = nums.end();
        return canPartition(it, end, sum >> 1);
    }
};
```
我们通过函数的调用栈来保存了这个临时的加和。这样整个过程的复杂度就降到$O(2^n)$。

但是这样复杂度仍然非常高。$O(2^n)$的复杂度，在实际的运用中都很难碰到。

我们继续观察这个过程，找一找可以优化的步骤。

我们观察到:
对于问题的一个实例{1,2,3,2,8,7,9,6}：

进行到第三步：这样两个子数组

{1,2,不取}和{不取,不取,3}他们的加和都是3。这样造成了重复，他们接下来的比较实际上是相同的。对于后续的数列{2,8,7,9,6}，3到底是哪些数字加出来的并不会影响。如果去掉这些分支，我们就可以节约这些时间。

### 1.3 基于二维数组的动态规划

动态规划是什么？Quora上有一个很有趣的例子：
>什么是动态规划？
>
>\*在纸上写：1+1+1+1+1+1+1+1=?\* 这个式子等于多少？
>
>\*数了一下\*……8！
>
>\*在式子的左边添一个“1+”\*,现在呢？
>
>等于9！
>
>你怎么算的这么快？
>
>因为你只是添加了一个！
>
>所以你不需要重新加一遍，因为你记住了他以前有8个。“动态规划”只是一种“把东西记下来以节省时间”的洋盘说法。

我们可以看出，我们刚才使用基于递归的分治，就是一种隐性的“利用计算机的调用栈把数据记下来以节省时间”动态规划法，只是你不知道他的名字。

刚刚提到，分治的做法会重复的计算相同和的部分，因此我们现在这样做：

对于一个实例{1,2,3,5}，我们建立如图的这样的一个二维数组表格：

![image.png](https://pic.leetcode-cn.com/ad5db3a370b1241dac3ae288bd1ff010b6adb6a111391c3089191af0917d9045-image.png)


这个表格中的数据是怎样得到的呢？

- 首先计算出目标和（就是分割的子集的和），建立对应的数组。
- 将第一行（也就是空集合对应的行）全部置false。再把空集和为0的(0,0)格子置true。
- 下一行
 - 我们先将上一行为true的对应的和的格子置true。因为这些在新集合的真子集中存在，那么他们在新集合中一定存在。（文中用==>箭头表示。）
 - 我们再将上一行为true对应的和加上新增的集合元素值所得到的和对应的格子置true。（文中用-->和圆圈[与0相加]表示）。
 - 我们判断目标和的格子是否为true。如果true出现那么返回true。(文中用方框标记。)如果true不出现，我们进入下一行，重复这个过程。
- 全部遍历目标和格子仍然为false，我们返回false。
    
我们注意到，现在所需的时间就已经缩短到 $O(N*sum)$ .这样的时间复杂度远远好于前文所述的方法的时间复杂度。这样的一个示例代码给在下方：

```cpp
class Solution {
public:
    bool canPartition(vector<int>& nums) {
        auto it = nums.begin();
        int sum = 0;
        for (; it < nums.end(); it++)
            sum += *it;
        if (sum & 1)
            return false;
        //计算目标和,建立数组。
        bool** b = new bool*[nums.size() + 1];
        for (int i = 0; i <= nums.size(); i++) {
            b[i] = new bool[sum / 2 + 1];
        }

        //第一行的设置
        b[0][0] = true;
        for (int j = 1; j <= sum / 2; j++) {
            b[0][j] = false;
        }

        //接下来的各行
        for (int i = 1; i <= nums.size(); i++) {
            //将上一行为true的对应的和置true。
            for (int j = 0; j <= sum / 2; j++)
                b[i][j] = b[i - 1][j];

            //上一行为true对应的和加新增值置true
            for (int j = 0; j <= sum / 2; j++)
                if (b[i - 1][j] && j + nums[i - 1] <= sum / 2)
                    b[i][j + nums[i - 1]] = true;

            //判断目标和
            if (b[i][sum / 2])
                return true;
        }
        //目标和格子仍然为false，我们返回false。
        return false;
    }
};
```
这样的操作虽然耗时大大减少了，但是空间复杂度更大了。

我们再次观察这个程序，看看有没有可以节约空间的地方。显然，这个二维数组是空间消费的大头。我们注意到，每次我们都会把上面的数组结果复制下来。因此我们可以用一个一维数组来简化这个数组。

### 1.4 基于一维数组的动态规划

用一维数组简化这个数组。需要注意的是在对应新增值相加的时候需要从高位向低位加，否则会出现同一个数被重复加的情况。

代码如下:

```cpp
class Solution {
public:
    bool canPartition(vector<int>& nums) {
        auto it = nums.begin();
        int sum = 0;
        for (; it < nums.end(); it++)
            sum += *it;
        if (sum & 1)
            return false;
        //建立一个一维bool数组
        bool* boolarray = new bool[sum + 1]();
        sum >>= 1;
        for (it = nums.begin(); it < nums.end(); it++) {
            //原本为true对应的和加新增值置true
            for (int j = sum; j >= 0; j--)
                if (boolarray[j])
                    boolarray[j + *it] = 1;
            //自己置true
            boolarray[*it] = 1;
            //判断目标和
            if (boolarray[sum])
                return true;
        }
        //没能达到目标和
        return false;
    }
};
```
整个过程是相同的，但是内存的占用量减小了很多。因为内存动态分配需要消耗大量的时间，这个做法的耗时也比原来的耗时少一半。

当然，在程序堆里分配空间非常耗时，也可以从条件出发，直接将数组定义在程序栈里，可以更节约时间和空间。

---

你可以在[我的博客](https://blog.victrid.dev)找到[这篇文章](https://blog.victrid.dev/2020/02/21/%E5%8A%A8%E6%80%81%E8%A7%84%E5%88%92%E2%80%94%E2%80%94%E5%88%86%E5%89%B2%E7%AD%89%E5%92%8C%E5%AD%90%E9%9B%86/)。希望大家喜欢。