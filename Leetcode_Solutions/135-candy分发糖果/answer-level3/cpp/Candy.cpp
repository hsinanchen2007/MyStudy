### 解题思路
![leet.png](https://pic.leetcode-cn.com/8b2988172fbc81c717ab60a13be10933cb88a3037510d9de61ef7f850799e6e1-leet.png)


通过贪婪算法，对输入的rating value进行一次遍历；
注意到任意一个序列都可以拆成若干个严格连续递减的子序列拼接而成；
[1,0,2]=[1,0]+[2];
[1,2,2]=[1]+[2]+[2];
[1,3,4,5,2]=[1]+[3]+[4]+[5,2];
然后我们分析怎样才能得到最少符合要求的糖果数：
1. 单独考虑一个连续递减的子序列，要使得分配的糖果数最少，那么最佳分配方式是，使从倒数第二个位置开始，每个位置分配的糖果数比后一个多1个，理想情况下当然希望最后一个位置只分配1个，所以此时我们要找的是从起始位置pos处最长的递减子序列，此时，子序列的最后一个元素要<=它的下一个元素，这种情况下，最后一个元素才能分配1；
2. 然后从全局考虑，若要符合条件（即有更高value值位置的糖果数比周围的要多），我们还需要使得pos位置处的糖果数比之前子序列中最后位置的糖果数多(如果pos位置处的value值更大，相等则不必考虑)，所以，pos位置处的糖果数应该变为max{cur-pos+1,pre+1}(其中cur是子序列最后一个元素的位置，pre是pos前一个位置的糖果数)，而pos之后位置的与pos前面位置分配的糖果数不相关；
3. 但是注意子序列只有一个元素的情况下我们不能直接将它分配的糖果数设为1，因为它也是起始位置的数，应该符合2.要求（如果pos位置处的value值更大，使得pos位置处的糖果数比之前子序列中最后位置的糖果数多1，因为没有后续元素了）

我们可以不断更新pos的值直到pos>=size(),每次更新，实际上我们都计算了从这个位置开始的最长子序列所需要的最少糖果数，而任意一个序列对应的这种最长连续递减子序列的集合都是唯一的，所以我们这样得到的糖果数目一定最少。

### 代码

```cpp
class Solution {
public:
    int candy(vector<int>& ratings) {
        int count=0,num=ratings.size(),pos=0,pre;
        if(num==0) return 0;
        while(pos<num){
            int cur,next;
            cur=pos;
            next=cur+1;
            while(next<num&&ratings[cur]>ratings[next]){
                cur++;
                next++;
            }
            if(pos==cur){ 
                if(pos==0) { count+=1; pre=1; }
                else{
                if(pos>=1&&ratings[pos]==ratings[pos-1]) {count+=1; pre=1;}
                else { count+=++pre;}
                }
             }
            else{
                if(pos==0) count+=(next-pos+1)*(next-pos)/2; 
                else{
                    if(ratings[pos]==ratings[pos-1]) 
                        count+=(next-pos+1)*(next-pos)/2; 
                    else{
                        if(next-pos>pre) count+=(next-pos+1)*(next-pos)/2;
                        else count+= 1+pre+(next-pos)*(cur-pos)/2;
                    }
                }
                pre=1;
            }
            pos=next;
            }
            return count;
        }
};
```