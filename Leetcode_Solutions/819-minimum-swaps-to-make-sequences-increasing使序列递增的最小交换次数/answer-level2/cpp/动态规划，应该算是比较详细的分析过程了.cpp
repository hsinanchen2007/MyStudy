## 问题描述
我们有两个长度相等且不为空的整型数组 `A` 和 `B` 。

我们可以交换 `A[i]` 和 `B[i]` 的元素。注意这两个元素在各自的序列中应该处于相同的位置。

在交换过一些元素之后，数组 `A` 和 `B` 都应该是严格递增的（数组严格递增的条件仅为`A[0] < A[1] < A[2] < ... < A[A.length - 1]）`。

给定数组 `A` 和 `B` ，请返回使得两个数组均保持严格递增状态的最小交换次数。假设给定的输入总是有效的。

![](https://pic.leetcode-cn.com/f1d1218ce840be5df8b4f7a3c88346c40e9be651c6e5fbe965189de8257aa7e6.png)

## 解决方法

### 一些废话

- 最近没有怎么做题，原因有好几点，主要原因还是归结为自己有点坚持不下来吧，接下来就是抓紧调整自己状态，快开学了，毕业设计和找工作等。应该也就闲不下来了，趁着在家的时候，多做点题吧。

- 叔家小弟最近在我这做c语言的基础题，算是学校留的个人作业吧，看着他刷题想起了自己刚上大一那会，跟他一样，从零开始，啥也不会。现在有时间还可以耐心教教他，愿他在今后的路上坚持下来吧，意识到努力的重要性，不要只有三分钟热度，尽量去坚持做一件事。这些话也送给自己做勉励。

### 动态规划

这个题第一次做是在两天前，中间两天属实颓废，就放着没搭理，今天晚上把他写完，算是了一件事吧。

做完这个题，突然觉得动态规划自己还是一知半解，所以还是加把劲吧。废话不多说，写完过程上床睡觉。

- 我们用`change[i]`表示交换当前`A[i]和B[i]`最小的交换次数。`not_change[i]`表示不交换当前`A[i]和B[i]`最小的交换次数。

- 交换的时候也简单粗暴：如果`A[i]>A[i-1] && B[i]>B[i-1]`的时候,说明当前序列是递增的，我们可以在此基础上再分为两种情况：
	1. `A[i]>B[i-1] && B[i]>A[i-1]`，说明`A[i]和B[i]`是可以交换的，
			`not_change[i]=min(not_change[i-1],change[i-1])`表示当前`A[i]和B[i]`不交换也可以保证序列递增，只需要在`change[i-1]和not_change[i-1]`中取一个最小值即可
			`change[i]=not_change[i]+1 `表示不管上一个数字交换与否，都与`A[i]和B[i]`交换没有关系，所以只需要在`change[i-1]和not_change[i-1]`取一个最小值加一即可
			
	2. 不符合`A[i]>B[i-1] && B[i]>A[i-1]`
			`not_change[i]=not_change[i-1]`;如果不交换当前`A[i]和B[i]`来维持序列递增，只需要继承上一步的值即可
			`change[i]=change[i-1]+1`;如果要交换`A[i]和B[i]`来维持序列递增，那么`A[i-1]和B[i-1]`也必须要交换，所以要取上一步的值加一
			
- `A[i]<A[i-1] || B[i]<B[i-1]`,到这里，如果要不交换当前`A[i]和B[i]`,那么`A[i-1]和B[i-1]`就要就要交换，所以我们取`not_change[i]=change[i-1]`.如果要交换当前`A[i]和B[i]`,则`A[i-1]和B[i-1]`不应该交换，所以`change[i]=not_change[i-1]+1`


```cpp

class Solution {
public:
    int minSwap(vector<int>& A, vector<int>& B) {
        int size=A.size();
        vector<int>change(size,INT_MAX),not_change(size,INT_MAX);
        change[0]=1;
        not_change[0]=0;
        for(int i=1;i<size;i++){
            if(A[i]>A[i-1] && B[i]>B[i-1]){
                if(A[i]>B[i-1] && B[i]>A[i-1]){
                    not_change[i]=min(not_change[i-1],change[i-1]);
                    change[i]=not_change[i]+1;
                }else{
                    not_change[i]=not_change[i-1];
                    change[i]=change[i-1]+1;
                }
            }else{
                not_change[i]=change[i-1];
                change[i]=not_change[i-1]+1;
            }
        }
        return min(not_change[size-1],change[size-1]);
    }
};
```

my site:[https://liyiping.cn](https://liyiping.cn)