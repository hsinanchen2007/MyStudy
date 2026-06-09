![image.png](https://pic.leetcode-cn.com/36002a35681532fc601e184c8f9f25e80d6a7c88f404f102ee3560f7d3dd921d-image.png)
此图，目的纯属搞笑，勿喷，的确跑出来就是这个。

一开始并有看明白LeetCode官方说明，然后参考大佬说明，略懂。

下面的两个图形例子为参考大佬的内容，重复引用而不可考，侵权立删。

环状替换比较难理解。如果把数组的数据放在正多边形上，以走跳棋的思路替换数据，画个图就好理解了。
假如 n=5, k=2, 数字1-5依次放在五边形顶点，数字替换的轨迹是1-3-5-2-4-1，回到原点，count = n， 结束。轨迹画出来刚好是个五角星。
假如 n=6, k=2, 数字1-6依次放在六边形顶点，数字替换的轨迹是1-3-5-1，回到原点了，count < n, start++, 接着 2-4-6-2，回到原点，count = n, 结束。轨迹是六边形的2个内嵌正三角形。其它多边形类似，隔k个点往前走，总能走回原点，如果中间有漏的，旋转一个角的方位重复进行上述步骤就能走完所有的顶点了。

​	结合官方的图，大概能够明白意思是：在k = 2，也就是步长是2的时候，在跨越总长度length的时候第一步就会回到原处。

​		算法的大概思路是直接每个数从现在的位置（current）直接放到能够跳到的位置（next），利用中间变量（tmp）实现两个位置元素互换。数组中每个位置的元素都进行一次上述操作，通过for循环实现。

![image.png](https://pic.leetcode-cn.com/7f07b2bf4eb47f20fb00cf64f1aab524c4a21df49cfc37b600cc65aa1f1043b1-image.png)


只是注意“第一轮 i % k = 0 ”不要傻乎乎的看图标，下标应该从0开始的。还需要一个地方，最后移动次数count一定是小于length的。

```
void rotate(vector<int>& nums, int k)
{
    int lens = nums.size();
    int count = 0;
    k = k % lens; //超出length的跳跃是没有意义的，化简一下
    
    for(int i = 0; count < lens; i++){
        int current = i;
        int pre = nums[i];
        do{
            int next = (current + k ) % lens; //计算下一次跳转的位置
            int tmp = nums[next];
            nums[next] = pre;
            pre = tmp;
            current = next;
            count ++;
        }while(i != current);
    }
}
```
