#### 时间复杂度`O(log(sqrt(2*G))+N)`，前一项只有十几，一般可认为是`O(N)`时间复杂度。
#### 看了一下其他的人题解，有些是直接暴力`O(sqrt(G))`，理解起来容易。
#### 有些是用数学公式`O(N)`的，但理解起来比较麻烦。
#### 我的方法算是二者折中，`O(N)`复杂度的前提下，也很容易理解。
# 解题思路：
### 1、首先通过二分查找，找到**最后一个**不会遇到**无糖可分情况下**的孩子**所拿的糖果数**。
##### 听起来很绕，但也不是很难理解，比如：candies=12，num_people=3，那么每个孩子每次分得的糖果数如下：
```
孩子序号    1   2   3
第一次分    1   2   3
第二次分    4   2
```
##### 我们要找的就是**4**这个数字
那么找到有什么用呢？
知道了4这个数字后，我们就可以用**等差数列求和公式**求出4之前（包括4）的所有糖果总数。
我们也可以知道，一共发了几轮糖果，还可以知道最后一个倒霉孩子拿到的糖果数……
### 2、得到**完整发糖果**的轮数
如果当前这一轮发糖果，所有孩子**都**没有遇到无糖可分的情况。
那么我们把所有这样的轮数加起来就是**完整发糖果的轮数**
##### 如上例，我们得到发糖果的轮数**1**之后，我们就又可以使用等差数列的求和公式求出每个孩子可以拿到多少糖果。
等差数列？是的，因为每个孩子**下一轮拿到的糖果数=上一轮拿到的糖果数+num_people**
比如第一个孩子，TA拿到的糖果总数就是`1*1+(1-1)*1/2=1`
### 3、开始发最后一轮糖果
到了第三步，我们已经按照完整发糖轮数发完了糖果，那么最后剩下的糖果，肯定在一轮内发完。

##### 大致思路就是这样，下面上代码，因为二分查找的存在，代码会略长。
```
class Solution {
    int findn(int x,int n){//二分查找到最后一个不会遇到无糖可分情况下的孩子所拿的糖果数
        int l=1,r=x;
        while(l<=r){
            int mid=l+(r-l)/2;
            long long num=1ll*(mid+1)*mid/2;//要用 long long 防止溢出
            if(num>n)r=mid-1;
            else if(num<n)l=mid+1;
            else return mid;
        }
        return r;
    }
public:
    vector<int> distributeCandies(int candies, int num_people) {
        int n=num_people;
        vector<int> res(n,0);
        int num=findn(int(sqrt(2*candies)),candies);
        int times=num/n;//一共发了几轮糖
        int cnt=1;//第一个孩子拿到的糖果数
        if(times){//如果轮数大于1
            for(auto &i:res){//对于一个孩子来说，轮了times次可以拿到的糖总数。
                i=(times*cnt+(times-1)*times*n/2);   
                //等差数列求和公式，这个不用我多讲了吧。
                ++cnt;//下一个孩子拿到的糖果数+1
            } 
        }    
        cnt=times*n;
        candies-=(cnt+1)*cnt/2; //轮了times次后，还剩下的糖果数 
        ++cnt;   //轮了times次后，第一个孩子拿到的糖果数。
        for(auto &i:res){
            num=min(cnt,candies);
            i+=num;//累积这个孩子的糖果数
            candies-=num;
            if(candies==0)break;//没糖了，结束
            ++cnt;//下一个孩子拿到的糖果数+1
        }
        return res;
    }
};
```
##### 最后略微提一嘴`findn()`中第一个参数为什么是`sqrt(2*candies)`
##### 因为我们要找的是满足`(num+1)*num/2<=candies`条件的最大num
##### 略微转化下就成了`num*num<=2*candies-num`
##### 再转化下`num<=sqrt(2*candies-num)`
##### 显然，因为num恒为正，所以`sqrt(2*candies-num)<=sqrt(2*candies）`

![image.png](https://pic.leetcode-cn.com/bb6ae3f507d567d83114830436565d81a257ad58b25c93a6be811ad6020e5866-image.png)
![image.png](https://pic.leetcode-cn.com/449222d48142245767232dd8d869a8e3eeef2ca5f4e545010f0236f7e3e978bc-image.png)
# 码字不易，菜鸡求赞……