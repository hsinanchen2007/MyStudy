**注释有些多，但只要能把代码和注释看一遍，肯定能看得懂~整体的过程还是比较清晰的❤**

在这里我提供了两个段代码，代码都是一样的，区别在于：
- 代码段 1：**不带注释的版本**，便于查看代码；
- 代码段 2：**带有详细注释的版本**，便于理解分发糖果的过程。

**代码段 1**：
```java
class Solution {
    public int[] distributeCandies(int candies, int people) {
        if (candies <= 0 || people <= 0) {
            return new int[0];
        } 
        int[] res = new int[people];
        int count = 1;
        int i = 0;
        int remain = candies;
        
        while (remain > 0) {
            if (remain >= count) {
                res[i % people] += count;
                remain -= count;
                count++;
            } else {
                res[i % people] += remain;
                break;
            }
            i++;
        }
        return res;
    }
}
```

**代码段 2**：
```java
class Solution {
    public int[] distributeCandies(int candies, int people) {
        if (candies <= 0 || people <= 0) {
            return new int[0];
        } 
        // 用于将结果进行返回，数组的长度自然就是小朋友的数量
        int[] res = new int[people];
        // 因为第一个小朋友发放 1 个糖果，第二个小朋友发放 2 个糖果......
        // 所以这里从 1 开始，表示要分发糖果的数量，即我打算要给当前小朋友的糖果数量
        int count = 1;
        // 对应小朋友在数组中的下标
        int i = 0;
        // 剩余的糖果数量，也就是给当前小朋友发放完糖果后，我还剩下多少的糖果
        int remain = candies;
        
        // 只要我还有糖果，我就要分给小朋友，直到我的手里没有糖果为止
        while (remain > 0) {
            // 我还能继续给小朋友分发糖果（我就是这么无私）
            // 也就是说，我当前剩余的糖果数量满足下次需要分发的数量
            if (remain >= count) {
                // 既然能够给对应的小朋友分发糖果，那么我就找到对应的小朋友，把糖给他
                // 由于一个小朋友可能会多次得到糖果，所以这里用 += 操作
                res[i % people] += count;
                // 给当前的小朋友分发完 count 个糖果以后，我还剩下的糖果数量
                remain -= count;
                // 准备要给下一个小朋友发放的糖果数量，需要不停的自增
                // 因为下一个小朋友会比前一个小朋友多得到 1 个糖果
                count++;
            // 我剩余的糖果数量不足以给下一个小朋友发放了
            } else {
                // 那我就把剩下的糖果都给这个倒霉的小朋友吧
                res[i % people] += remain;
                // 我已经把所有的糖果都发放完了，我已经没有糖果了，直接溜了~溜了~
                break;
            }
            // 来到下一个小朋友，继续给他分发糖果
            i++;
        }
        return res;
    }
}
```

### 全部题解
《剑指Offer》的全部题解与 LeetCode 的部分题解在此下方，其中还包含**基础算法**与**进阶算法**，欢迎查看~
[LeetCode、SwordToOffer and other algorithms in Java.](https://github.com/dyfloveslife/LeetCodeAndSwordToOffer)