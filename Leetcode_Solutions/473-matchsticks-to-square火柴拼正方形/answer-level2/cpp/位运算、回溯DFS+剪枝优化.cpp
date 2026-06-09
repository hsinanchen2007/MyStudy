
例如：[1,1,2,2,2]
对每个元素编码如下：
1   ···00001 对应于1
1   ···00010 对应于2
2   ···00100 对应于3
2   ···01000 对应于4
2   ···10000 对应于5
这个数组共有5个元素，则其所有的元素组合（假设每个元素都不同）共有2的5次方个，即1<<nums.size()个，每个组合的m编码可以用各元素的编码经过或运算得到，如[1,1]编码为00011，对应于第3个组合；再如[1,1,2,2,2]编码为11111，对应于第31个组合。

1）判断明显不能构成正方形的情况：总和不是4的整数倍，或者输入元素数目少于3
```
int sum=0;
for(int i=0;i<nums.size();i++){
    sum+=nums[i];
}
if(sum%4!=0||nums.size()<4){
    return false;
}
```
2）用移位运算得到所有组合的个数，并对所有组合进行遍历，遍历时对每个组合i，循环判断第j元素元素是否在组合i中，若是则计算加和；循环结束后判断加和是否为边长4，如果是，则该组合i是符合单边条件的边，放入vector中暂存。
```
int all_subset=1<<nums.size();
for(int i=0;i<all;i++){
    int sum_edge=0;
    for(int j=0;j<nums.size();j++){
        if(i&(1<<j)){
            sum_edge+=nums[j];
        }
        //cout<<j<<endl;//测试
        //cout<<maybe_edge_subset.size()<<endl;//测试
    }
    if(sum_edge==L){
        maybe_edge_subset.push_back(i);
    }      
}
```
3）这时maybe_edge_subset中包含了所有符合边长条件的组合。但一个元素不能重复使用，所以得去重，看是否存在四个组合互相没有重复元素。对 maybe_edge_subset中所有的组合，先两两进行判断，如果maybe_edge_subset[i]&maybe_edge_subset[j]不为零，说明两个组合i和j中有重复元素，否则无重复元素；无重复元素，则把i和j进行或运算暂存于Two_edges中。
```
vector<int>Two_edges;
for(int i=0;i<maybe_edge_subset.size();i++){
    for(int j=i+1;j<maybe_edge_subset.size();j++){
        if(0==(maybe_edge_subset[i]&maybe_edge_subset[j])){
            Two_edges.push_back(maybe_edge_subset[i]|maybe_edge_subset[j]);
        }
    }
}
```
4）循环完后，这时Two_edges中的每个元素，都是包含两个既符合边长条件同时彼此间无重复元素的组合；
这时在对Two_edges中元素两两进行类似操作，如果Two_edges中存在两个元素彼此无重复元素，则说明至少有四条边组合符合边长条件且彼此间无重复元素，说明可以组成正方形。
```
for(int i=0;i<Two_edges.size();i++){
    for(int j=i+1;j<Two_edges.size();j++){
        if(0==(Two_edges[i]&Two_edges[j])){
            return true;
        }
    }
}
```
5）否则，不能构成正方形：
```
return false;
```


完整代码如下：
```
class Solution {
public:
    bool makesquare(vector<int>& nums) {
        int sum=0;
        for(int i=0;i<nums.size();i++){
            sum+=nums[i];
        }
        if(sum%4!=0||nums.size()<4){
            return false;
        }
        int L=sum/4;//边长
        vector<int>maybe_edge_subset;
        int all=1<<nums.size();
        //cout<<"haha"<<endl;//测试
        //cout<<all<<endl;//测试
        for(int i=0;i<all;i++){
            int sum_edge=0;
            for(int j=0;j<nums.size();j++){
                if(i&(1<<j)){
                    sum_edge+=nums[j];
                }
                //cout<<j<<endl;//测试
                //cout<<maybe_edge_subset.size()<<endl;//测试
            }
            if(sum_edge==L){
                maybe_edge_subset.push_back(i);
            }      
        }
       cout<<maybe_edge_subset.size()<<endl;
        vector<int>Two_edges;
        for(int i=0;i<maybe_edge_subset.size();i++){
            for(int j=i+1;j<maybe_edge_subset.size();j++){
                if(0==(maybe_edge_subset[i]&maybe_edge_subset[j])){
                    Two_edges.push_back(maybe_edge_subset[i]|maybe_edge_subset[j]);
                }
            }
        }
        for(int i=0;i<Two_edges.size();i++){
            for(int j=i+1;j<Two_edges.size();j++){
                if(0==(Two_edges[i]&Two_edges[j])){
                    return true;
                }
            }
        }
        return false;
    }
}; 
```

运行效率不高，还有较大优化空间

回溯算法：评论区一个网友 whererun 对回溯法的一个举例比较通俗易懂——可以看成是固定个数的固定容量的水桶的接水问题。对于例子[1, 1, 2, 2, 2]，按从大到小排列变成[2, 2, 2, 1, 1]。 正方形的四条边抽象成四个水桶，每个水桶的容量为2，超过容量就会溢出。nums[0] = 2，用第一个桶装，刚刚好装满； nums[1] = 2，用第一个桶装，发现2 + 2 = 4 > 2，那么就用第二个桶装，第二个桶也装满；nums[2] = 2，用第一个和第二个 桶都装不下，用第三个桶装，那么第三个桶也装满；nums[3] = 1，只能用第四个桶装，但没装满；nums[4] = 1，也只能用第四个桶装， 第四个桶也装满了。四个桶都恰好装满表示能构成正方形。

算法思路：
1）在进行递归调用前，就可以进行优化处理：如果nums数组长度小于4或者总和不是4的整数倍，一定不能构成正方形；对数组从大到小排序，调用时先放大的后放小的，有利于减少回溯的次数，此时如果最大的那个大于边长，则一定不能构成正方形。
2）递归调用：将四个边看成4个容量一定的桶，将nums的第一个值尝试放第一个桶，如果桶的当前值加这个值不大于桶容量，就将其放入；否则就放入第二个桶，以此类推，直到放进去为止，然后递归地放nums地下一个元素；如果到第四个桶也放不进去，这说明需要进行回溯处理。
对于[4,3,3,2,2,1,1]有如下流程递归树，当然这个不需要回溯处理。
![P90913-220716.jpg](https://pic.leetcode-cn.com/6ccd1680cb32cf241ac2282976072b3c94ac1cfaa09512c46537e613ce3ca129-P90913-220716.jpg)



     



