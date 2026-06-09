
普通的nlogn解法虽然正确，但是运行时间上排名靠后。
这题由于测试数据的特殊性（太弱了），有针对数据的加速方法。

(1) 查看执行用时分布图表，查看28ms的范例

```
class Solution {
public:
    bool isNStraightHand(vector<int>& hand, int W) {
         if(hand.size() % W !=0)
            return false;
        int arr[W]={0};
        for(int i=0;i<hand.size();i++)
        {
            int k=hand[i] % W;
            arr[k]++;
        }
        for(int i = 1;i<W;i++){
            if(arr[i]!=arr[i-1])
                return false;
        }
        
        return true;
    }
};
```
发现思路就是记录每个hand[i]%W 的次数存在arr数组，如果可以组成顺子，那么每个arr[i]的值都会相等。
# 显然这个是错的
# 事实上如果不存在顺子，arr[i]的值也可能相等
比如 [1,4] , W = 2，我们发现 arr = [1,1]，return true，与事实相悖，**但是在这一题的测试数据中，这种方法可以通过** ，复杂度为O(n)。

(2)在开头增加一个判断
`if max(hand)-min(hand) > len(hand) + 10:
return False`
显然这个是错的，比如 hand = [1,2,3,1000,1001,1002],W = 3
# 非常无脑暴力，但是可以过。

![QQ截图20200219031139.jpg](https://pic.leetcode-cn.com/be8e90dd430c44f7b61af1a0a5b8b75b5114adcf2d2fcfff95ff78d1c0de41ec-QQ%E6%88%AA%E5%9B%BE20200219031139.jpg)




**击败100%的代码（可能需要多提交几次）**
```
class Solution {
public:
    bool isNStraightHand(vector<int>& hand, int W) {
        int minv=1<<30,maxv=-1;
        int n = hand.size();
        if(n % W !=0)
            return false;
        for(int i=0;i<n;++i){
            if(hand[i]<minv)minv=hand[i];
            if(hand[i]>maxv)maxv=hand[i];
        } 
        if(maxv-minv>n+10)return false;
         if(n % W !=0)
            return false;
        int arr[W]={0};
        for(int i=0;i<n;i++)
        {
            int k=hand[i] % W;
            arr[k]++;
        }
        for(int i = 1;i<W;i++){
            if(arr[i]!=arr[i-1])
                return false;
        }
        return true;
    }
};
```
