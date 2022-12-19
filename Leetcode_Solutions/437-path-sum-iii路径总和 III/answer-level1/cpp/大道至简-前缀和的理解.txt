    为了更巧妙的解这道题，让我们首先解释一下什么是**前缀和**：
假设有一组数组为：arr={1,3,5,7,9},数组下标从0~4,我们想要求出数组从i~j元素之和，(0<=i,j<5) 那么我们可以构建出一个前缀数组
```
int n = arr.size();
// 前缀和数组
int[] prefix_sum = new int[n + 1];
preSum[0] = 0;
for (int i = 0; i < n; i++)
    prefix_sum[i + 1] = prefix_sum[i] + arr[i];
```
可以得到prefix_sum={0,1,4,9,16,25},这个前缀和数组 prefix_sum 的含义很好理解，prefix_sum[i] 就是arr[0..i-1] 的和。那么如果我们想求 arr[i..j] 的和，只需要一步操作 prefix_sum[j+1]-prefix_Sum[i] 即可，而不需要重新去遍历数组了。
但使用数组显然不能够很好的存储我们想要的信息，比如：现target=4,要求出数组中是否能够满足有一条符合prefix_sum[i]-prefix_sum[j]=target的路径，这样的话就需要数组整个遍历,时间复杂度为O(N)：

```
for(int i=1;i<prefix_sum.size();i++){
    for(int j=0;j<i;j++)
    {
        if(prefix_sum[i]-prefix_sum[j]==target)
            ....
    }
}

```
所以我们采用更加高效的hash表模式，有如下代码：
```
for(int i=0;i<prefix_sum.size();i++)
{
    if(hash.count(prefix_sum[i])>0)
        ....
    hash[prefix_sum[i]]++;
}
```
这样的话时间复杂度为O(1)，效率更高

好的，让我们进入主题，很显然，从题意可以看出，要求的路径其实就是满足题意前缀和的个数,那么可以看出此前缀和的个数为2条。然后hash[0]=1,这段代码的意思就是满足prefix_sum[i]-target=0的情况即为1。
比如target=8,现有二叉树路径为：4->4,那么4+4-8=0 ，二叉树的路径和即为1。

接下来这段代码是核心代码，为什么要有hash[presum_i]--呢？
我相信很多人有这个疑问，其实是这样的如果此题不为二叉树求前缀和，而是数组的话，那么就不会有这个代码，二叉树的话，大家想想一个问题：
              
![ELV1O\]UI}VIL~VA7`R3A}4Y.png](https://pic.leetcode-cn.com/e6d3a148ab0fc2866eac790fc6b7219d1a5dd0a775f8aca7f997b0225e4230da-ELV1O%5DUI%7DVIL~VA7%60R3A%7D4Y.png)，target=-1， 那么此时的路径有几条？如果没有
hash[presum_i]--这个代码的话，答案是两条，而真正的答案是一条，为什么会出现这样的情况呢？是这样的，1+(-2)=-1这个时候的前缀和hash[-1]=1,而另一条二叉树前缀和1+(-3)=-2,此时hash.count(-2-(-1))>0

很显然这是不符合题意的，因为树的左子树路径的前缀和与右子树路径的前缀和没有一点关系，所以我们在遍历树之后必须加当前这条路径上的前缀和清除掉，避免影响其他路径的前缀和的判断。

```
        hash[presum_i]++;  //前缀和+1
        
        helper(root->left,sum,presum_i);
        helper(root->right,sum,presum_i);
        hash[presum_i]--;//前缀和-1
```

代码原型如下：
```
class Solution {
public:
    int res=0;
    unordered_map<int, int> hash;
    int pathSum(TreeNode* root, int sum) {
        hash[0] = 1;//base case
       helper(root, sum, 0);

       return res;
    }
    
    void helper(TreeNode* root, int sum, int presum_i) {
        if (!root) return ;

        presum_i += root->val;
        if(hash.count(presum_i-sum)){    
            res += hash[presum_i- sum];
        }
        hash[presum_i]++;  
        
        helper(root->left,sum,presum_i);
        helper(root->right,sum,presum_i);
        hash[presum_i]--;
    }
};
```
结尾：leetcode上还有很多应用前缀和的题目，如[https://leetcode-cn.com/problems/subarray-sum-equals-k/](lt560 和为K的连续数组)，[https://leetcode-cn.com/problems/remove-zero-sum-consecutive-nodes-from-linked-list/](lt1171 从链表中删除总和值为0的元素)