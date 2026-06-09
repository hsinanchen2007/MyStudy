[题目描述](https://leetcode-cn.com/explore/interview/card/top-interview-questions-easy/1/array/23/)
给定一个数组，将数组中的元素向右移动 k 个位置，其中 k 是非负数。

>示例 1:
输入: [1,2,3,4,5,6,7] 和 k = 3
输出: [5,6,7,1,2,3,4]
解释:
向右旋转 1 步: [7,1,2,3,4,5,6]
向右旋转 2 步: [6,7,1,2,3,4,5]
向右旋转 3 步: [5,6,7,1,2,3,4]
示例 2:
输入: [-1,-100,3,99] 和 k = 2
输出: [3,99,-1,-100]
解释: 
向右旋转 1 步: [99,-1,-100,3]
向右旋转 2 步: [3,99,-1,-100]
说明:
尽可能想出更多的解决方案，至少有三种不同的方法可以解决这个问题。
要求使用空间复杂度为 O(1) 的 原地 算法。

### 初步思路
这个题由于之前考研的时候遇到过，所以第一想到的就是用数组的逆序原理，三次逆序，就可以得到最终的答案，这种解题思路还是很巧妙的，具体是这么做。
比如： 拿第一个数组来说：
>[1， 2，  3， 4， 5， 6， 7]

首先，对整个数组进行逆序得到
>[7，  6，  5， 4，  3，  2，  1]

然后， 对于这个数组， 再分别对下标0-k-1的元素进行逆序， 比如k=3
>[5， 6， 7， 4， 3， 2， 1]

然后再对下面k-len-1的元素进行逆序
>[5， 6， 7， 1， 2， 3， 4]

这样就得到了最终的答案。 解法很巧妙。三次逆序：
* reverse(arr, 0, len-1)
* reverse(arr, 0, k-1)
* reverse(arr, k, len-1)
代码如下：

```cpp
class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        int len = nums.size();

        if(k <= 0 || len <=0)
                return ;
        k %= len;                    // 别越界

        // 把向量里面的元素逆序
        reverse1(nums, 0, len);
        reverse1(nums, 0, k);
        reverse1(nums, k, len);
    }
    void reverse1(vector<int>& nums, int start, int endd)
    {
        int i=start;
        int j = endd-1;
        for (; i<=j; i++, j--)
        {
            int temp = nums[i];
            nums[i] = nums[j];
            nums[j] = temp;
        }
    }
};

```
当然如果使用STL类库的话，代码会更简洁，但是不如上面的速度快

```cpp
class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        int len = nums.size();

        if(k <= 0 || len <=0)
                return ;
        k %= len;                    // 别越界
        // 把向量里面的元素逆序
        reverse(nums.begin(), nums.end());
        reverse(nums.begin(), nums.begin()+k);
        reverse(nums.begin()+k, nums.end());
    }
};
```

### 改进思路：直接旋转
这个的速度比上面两个快一些，基于一遍遍历，进行元素的直接后移，具体思路如下：
>思路： 直接用循环在原数组上进行后移，这个还是有点麻烦的，思想就是为当前元素元素找移动k个位置之后的位置，然后放上。<br>
>比如：从第一个开始，最终位置是往后移动k个，所以往后移动k个位置放上，但是在放上之前，先保存这个位置上的元素，以防覆盖。
同样，这个位置的元素，也往后移动k个（超了下标就回来），得到新位置，放上
同样，新位置上的元素，也往后移动k个，放上
这样重复上述步骤，直到所有的元素都找到最后的位置为止。
但是，有个比较麻烦的地方就是什么时候应该结束？  设置一个变量cou， 记录放到最终位置上的元素的个数，当cou==总个数，即可以停止
还有个问题，就是在移动过程中，可能会有位置重合的现象，这种情况也要避免。
总之， 看代码吧，有点说不清。

看下面这张图片。
![在这里插入图片描述](https://pic.leetcode-cn.com/cf0c5056aac8be581a7e62b1236c2738f17b2067857b8da159d6b456f1b56b68.png)
代码如下：
```cpp
class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        int len = nums.size();      // 获取数的个数

        int temp1, temp2;   //  temp1和temp2是辅助存储变量，为交换元素值暂存元素以防覆盖
        int index, cou = 0;//cou为计数变量，记录已经到了最终位置上的元素。 index为每轮开始，初始元素的下标，给元素找位置用

        k %= len;    //对k值的前期处理，处理原因是如果k值比len大，那么只有大于len的那部分才是有效移动
        if(k == 0)
        {
            //如果k等于0或者k原本是等于len的，那么就相当于没有移动嘛，直接返回
            return ;
        }


        // 下面是一个大循环
        for (int i = 0; i <= k; i++)    //移动的轮数最多k次，当然计数变量count=len的时候会跳出循环
        {
            if(cou >= len)
                break;               //对计数变量的控制，当所有位置全部移动完了就可以结束了

            index = i;               // 每轮移动的初始下标
            temp1 = nums[i];         // temp1 记录的是需要往后移动的元素

            while((index + k)%len != i) //    这个循环终止的条件，就是要转一圈了
            {
                temp2 = nums[(index + k)%len];    // temp2保存可能要覆盖的那个数
                nums[(index + k)%len] = temp1;     // temp1 往后移动到它最终位置
                index = (index + k)%len;          // index往后走k步，需要给刚才的temp2找最终位置
                temp1 = temp2;               // temp1 记录的是往后移动的元素，把temp2给temp1
                cou++;                  // 一个元素已经归位， cou++
            }
            nums[i] = temp1;           // 转了一圈， nums[i] 这个位置，给temp1
            cou++;                   // 这个也归位
        }
    }
};
```

### 总结
这个题比较好的思想就是三次逆序的那个了， 想第二个改进的，其实不太好想，转着转着就容易转迷糊了， 手写转转吧。 
这个的思路参考的这篇博客：
[https://blog.csdn.net/qq_28584889/article/details/83655019](https://blog.csdn.net/qq_28584889/article/details/83655019)