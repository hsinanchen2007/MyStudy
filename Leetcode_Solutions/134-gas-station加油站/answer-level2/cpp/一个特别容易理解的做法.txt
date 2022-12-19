我们可以先算出gas-cost来代表走一段路的贡献，从出发点开始相当于从0贡献开始这样我们可以类似画出一个折线图，这个问题不成立的情况就是折线图折线穿过x轴到下半区则表示此起点行不通（我们总是假设出发点为0）
![无标题.png](https://pic.leetcode-cn.com/b166682decded36e4faf287b73fdb30b2e898dc091073f71bfe4a24ef6d8a45e-%E6%97%A0%E6%A0%87%E9%A2%98.png)
如图我们可得出从0号加油站出发是无法走一圈的因为折线存在负数情况，而假如我们换起点，其折线的幅度是不会边的，这也就相当于把该图沿y轴平移使得起点到0就相当于换起点，那么我们就很容易得出一个结论就是，把最低点平移到0，可以保证没有负数情况出现，所以问题就转换成找最低点即可。

代码如下：
class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        int ans=0,minn=0;
        int pos=0;
        for(int i=1;i<=gas.size();i++){
            ans+=gas[i-1]-cost[i-1];
            if(minn>ans){
                minn=ans;
                pos=i;
            }
        }
        if(ans>=0) return pos;
        else return -1;
    }
};