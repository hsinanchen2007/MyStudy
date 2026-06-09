注意一点就是我一开始准备使用accumulate这个函数的，但是出现超时，所以只能一个一个老老实实加了。。。
```
//看了题解做出来的，基本思路：逆向思维，
//因为每一个大的数字是从小的数字（1，1，1....1）过来的，是一步一步加过来的
//所以现在反过来，我们一个一个减回去，那么结果一定是最初的数字（1，1，1....1）
//即结果全是1。
//这里使用一下优先队列的思想。。。大顶堆（出现1）return true结束。
class Solution {
public:
    bool isPossible(vector<int>& target) {
        //long long sum=accumulate(target.begin(),target.end(),0);//accumulate是vector直接累加的一个函数，比较方便
        long long sum=0;
        priority_queue<int>pq;//大顶堆，小顶堆在内部加一个greater<int>
        for(auto v:target){pq.push(v);sum+=v;}
        while(pq.size()>0){
            long long ans=pq.top();
            if(ans==1)return true;//结束操作符合条件
            long long temp=ans-(sum-ans);
            sum=ans;//更新一下sum，因为sum就是之前小的叠加来的，pq.top()也是当前最大的，是之后小的与1叠加过来的
            pq.pop();
            if(temp>=1)pq.push((int)temp);
            else return false;
        }
        return true;
    }
};
```
