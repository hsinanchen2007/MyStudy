做本题的前提「[下一个更大元素 I](https://leetcode-cn.com/problems/next-greater-element-i/solution/dan-diao-zhan-jie-jue-next-greater-number-yi-lei-w/)」

同样是 Next Greater Number，现在假设给你的数组是个环形的，如何处理？

给你一个数组 $[2,1,2,4,3]$，你返回数组 $[4,2,4,-1,4]$。拥有了环形属性，最后一个元素 3 绕了一圈后找到了比自己大的元素 $4$。

![ink-image (1)](https://pic.leetcode-cn.com/a953749581ae943484e681ffd2c14f8fc9e6ab7cf7ff4fbcb836ec31c0a5b933-file_1560500960938){:width=400}
{:align=center}


首先，计算机的内存都是线性的，没有真正意义上的环形数组，但是我们可以模拟出环形数组的效果，一般是通过 $\%$ 运算符求模（余数），获得环形特效：

```
int[] arr = {1,2,3,4,5};
int n = arr.length, index = 0;
while (true) {
    print(arr[index % n]);
    index++;
}
```

回到 Next Greater Number 的问题，增加了环形属性后，问题的难点在于：**这个 Next 的意义不仅仅是当前元素的右边了，有可能出现在当前元素的左边（如上例）**。

明确问题，问题就已经解决了一半了。我们可以考虑这样的思路：将原始数组 “翻倍”，就是在后面再接一个原始数组，这样的话，按照之前“比身高”的流程，每个元素不仅可以比较自己右边的元素，而且也可以和左边的元素比较了。

![ink-image (2)](https://pic.leetcode-cn.com/c6dda3c6d50dddbd4518619829834235a8f84be0f34f3b32974ad6d8e76cc3b1-file_1560500960943){:width=400}
{:align=center}


怎么实现呢？你当然可以把这个双倍长度的数组构造出来，然后套用算法模板。但是，我们可以不用构造新数组，而是利用循环数组的技巧来模拟。

直接看代码吧：

```C++ []
vector<int> nextGreaterElements(vector<int>& nums) {
    int n = nums.size();
    vector<int> res(n); // 存放结果
    stack<int> s;
    // 假装这个数组长度翻倍了
    for (int i = 2 * n - 1; i >= 0; i--) {
        while (!s.empty() && s.top() <= nums[i % n])
            s.pop();
        res[i % n] = s.empty() ? -1 : s.top();
        s.push(nums[i % n]);
    }
    return res;
}
```

至此，你已经掌握了单调栈的设计方法及代码模板，学会了解决 Next Greater Number，并能够处理循环数组了。


PS：**我的所有算法文章都已经上传到了 Github 仓库**：[**fucking-algorithm**](https://github.com/labuladong/fucking-algorithm)，共 60 多篇，绝对精品，肯定让你收获满满，**求个 star 不过分吧**～

PPS：我最近精心制作了一份电子书《labuladong的算法小抄》，分为「动态规划」「数据结构」「算法思维」「高频面试」四个章节，目录如下，如有需要可扫码到我的公众号 **labuladong** 后台回复关键词「pdf」下载：

![目录](https://pic.leetcode-cn.com/89082bca604614c0b2d86bb995f1ac949fbc99bfea36946580b372e685e59d1f.jpg){:width=450}
{:align=center}