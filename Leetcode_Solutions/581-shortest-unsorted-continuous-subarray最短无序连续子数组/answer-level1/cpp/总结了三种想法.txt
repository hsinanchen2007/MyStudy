### 解题思路：

**解法一：**
寻找就位元素，从 star 到 end，如果数组的最大最小值，分别再两头，那么是就位元素，之后缩短 star 和 end，出现未就位元素可分为三种情况：
- 1)都未就位；
- 2)左边未就位；
- 3)右边未就位；分别处理，返回 end - start + 1。

**解法二：**
另外申请一个空间，复制数组后排序，逐一比对，找到未就位的区间段；

**解法三：** 
时间复杂度 $O(n)$，按照规则数组从小到大排序，那么：

使用 max 记录局部极大值，使用 end 标记这个局部最大值应该出现的位置，比如数组内部出现了一个比较大的数，怎么办呢？
只要后面的数比它小，那么 end 就记录下来当前位置，直到出现比他大的数字，max 值被替换，说明我们已经找到，这个局部极大值应该存放的位置，就这样持续遍历到尾，期间可能出现好几个局部极大值，那么 end 一定会越来越靠后，即它表示局部最大值，组成的集合中最大的那个值应该存放的位置。

同理，从后往前查找，用 min 表示局部极小值，star标记局部极小值应该存放的正确位置，持续遍历整个数组，若期间出现
好几个局部极小，star 一定越来越靠前，即它表示局部极小值组成的集合中最小的那个值应该存放的位置。      
如此看来，我们发现一个极大的数放错位置了，他应该放在 end 之歌位置，同时，一个极小的数也错了，他应该在 star位置，那么，这个最短的子序列长度我们就知道了，它就是 end-star+1；

```C++ [C++]
//方法1
    int findUnsortedSubarray(vector<int>& nums) {
        int star=0,end=nums.size()-1,min,max;
        if(nums.size()<=1) return 0;
        while(star<=end)
        {           
            min=star;
            max=end;
            for(int i=star;i<=end;i++)
            {
                if(nums[min]>nums[i]) min=i;
                if(nums[max]<nums[i]) max=i;
            }
            if(min==star&&max==end) 
            {
                star+=1;
                end-=1;
            }
            else if(min!=star&&max==end)
            {
                end-=1;
            }
            else if(min==star&&max!=end)
            {
                star+=1;
            }
            else
            {
                break;
            }
        }
        return end-star>0?end-star+1:0;        
    }
```
```
//方法3，优秀，高效
 int FindUnsortedSubarray(vector<int>& nums) {
        //此解法参考英文官方LeetCode上的讨论
        //从左到右扫描（或从右到左）找局部极大值（或局部极小值），若位置放置不正确，找到其应该存在的地方
        int n = nums.size();
        //赋初始开始和结束值
        int start = -1;
        int end = -2;
        //结束值赋为-2是考虑在数组本身就是有序时,return也可以给出正确值
        int min = nums[n - 1];
        int max = nums[0];
        for(int i = 0, pos = 0; i < n; i++) {
            pos = n - 1 - i;
            //找出局部极大、极小值
            max = Max(max, nums[i]);
            min = Min(min, nums[pos]);
            //如果当前值小于局部极大值，用end记录该位置，找到该max的合适位置，
            if(nums[i] < max)
                end = i;
            //如果当前值大于局部极小值，用star记录该位置，找到该star的合适位置
            if(nums[pos] > min)
                start = pos;
        }
        //返回开始和结束的索引差
        return end - start + 1;
    }
```