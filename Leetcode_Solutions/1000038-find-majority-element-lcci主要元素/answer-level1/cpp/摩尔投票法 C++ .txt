时间复杂度O(n)
空间复杂度O(1)
首先，我们将数组中的元素分类两类：
一类是大于一半的元素组成的派别A
一类是其余元素组成的派别B。
接着，A和B派别火拼，一对一，那么谁的人多谁获胜，最后获胜的肯定是派别A，也就是大于一半的元素。
这就是摩尔投票法，名字很高大上，但是解释起来很简单。
所以我们的目标就是：删除，删除，删除。删到不能删除为止。
实现的算法从第一个数开始扫描整个数组，设置两个变量，为major和cnt。
major存储当前占比较多的数（帮派A成员），cnt记录当前较多的数的个数（成员可数），如果当前数与major相同，则cnt++,
否则cnt--。
当cnt==0时，重新选举，这样来回火并，到最后留下的肯定是大于一半的元素。
代码如下：
```
class Solution {
public:
    //两个派别火拼，一对一，最后人多的派别获胜。
    //摩尔投票法
    int majorityElement(vector<int>& nums) {
        int major=0,cnt=0;
        for(auto num:nums){
            if(cnt==0){
                major=num;
                cnt++;
            }
            else{
                if(major==num){
                    cnt++;
                }
                else{
                    cnt--;
                }
            }
        }
        return major;
    }
};
```
