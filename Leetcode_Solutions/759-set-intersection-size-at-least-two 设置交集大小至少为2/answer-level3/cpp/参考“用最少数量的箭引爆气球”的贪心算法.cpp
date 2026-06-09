// ## 描述
// ### **（回忆）**[“用最少数量引爆气球”](https://leetcode-cn.com/problems/minimum-number-of-arrows-to-burst-balloons/)贪心解法
// 要用最少数量的箭引爆气球，根据贪心思想，保证每一支箭都能够射中最多的气球即可。
// 如下图，先对所有气球按左边界排序，要引爆当前的气球至少需要一支箭，这支箭的射击范围是从气球的左边界到右边界[3,5]。当增加一个气球时，有三种情况。
// 1、增加的气球和当前的射击范围部分重合，气球2 [4,6]和射击范围[3,5]的情形。此时不需要新增加箭，但是射击范围范围会变缩小到重合区域[4,5].
// 2、增加的气球不在当前的射击范围内，气球3 [8,11]和射击范围[4,5]。这时需要增加箭的数量，并且新的射击范围为[8,11],如果气球3是[6,11],还是不在射击范围[4,5]之间，也需要增加箭的数量。
// 3、增加的气球完全包围在射击范围内。气球4 [9,10]和射击范围[8,11]。这时和情形1一样，不需要增加箭的数量，但是需要调整射击范围为[9-10]。
// 当遍历完所有气球时，最少的箭的数量就得到了。
// ![图片.png](https://pic.leetcode-cn.com/cde5486deef05e6cfc5518e0d5fa776b95143b8c5f75683da8c31ec545f14374-%E5%9B%BE%E7%89%87.png)

// ### 本题题解（贪心解法）
// 本题可以理解为每个气球至少需要两支箭才能引爆，并且每支箭必须射在不同的位置。
// 所以我们需要记录这两支箭的边界，先对所有气球按左边界排序。由于排序了，就可以不记录右边的箭的左边界。用left[0]表示左边箭的可射击范围(不能和右边箭重复)，right表示右边箭的可射击范围(不能和左边箭重复)。对于第一个气球，left=[3,4],right=[4,5].增加气球时会出现下面三种情形。
// 1、增加的气球左边界刚好和右边箭的右边界重合，那么这时只需要新增加一支箭即可。气球2和气球1的情形。气球2的左边箭的左边界和右边界只能是5，left=[5,5]。在往右就不能击中气球1了。气球2的右边箭的左边界为6右边界为7，righ=[6,7]。
// 2、增加的气球左边界大于右边箭的右边界，气球4和气球2的情形，此时需要新增加两支箭。左边箭的边界需要调整left=[9,9],右边箭的右边界也需要调整right=[10,10]。
// 3、增加的气球的左边界小于右边箭的右边界。这时🈶又可以分为两种情形。
// >3.1 当新增气球的左边界大于左边箭的右边界时，也就是气球3‘对于气球2的位置。此时需要增加一支箭，因为只有右边箭可以射中。新的左边箭的边界为left=[6,6],右边箭的边界right=[7，7]
// 3.2 当新增气球的左边界刚好等于左边箭的时候，不需要新增箭，即气球3对于气球2的情形。此时左边箭的边界不需要调整。右边箭的右边界调整为[6,6]
 
// ![图片.png](https://pic.leetcode-cn.com/9c6225bffa26fb8fc9c7ed808993d1e71bc7c057cdea8673598fff086efea524-%E5%9B%BE%E7%89%87.png)

// 由于先进行了排序，右边箭的左边界就没什么影响了。细节在于边界调整的过程，一定要考虑周全。
// ## C++代码
// ```c++
bool mycompare(vector<int> a,vector<int> b){
    return a[0]<b[0];
}
class Solution {
public:
    int intersectionSizeTwo(vector<vector<int>>& intervals) {
        sort(intervals.begin(),intervals.end(),mycompare);
        vector<int> left{intervals[0][0],intervals[0][1]-1};
        int right=intervals[0][1];
        int count=2;
        for(int i=0;i<intervals.size();i++){
            if(intervals[i][0]==right){
                count+=1;
                left[0]=intervals[i][0];
                left[1]=intervals[i][0];
                right=intervals[i][1];
            }
            else if(intervals[i][0]>right){
                count+=2;
                left[0]=intervals[i][0];
                left[1]=intervals[i][1]-1;
                right=intervals[i][1];
            }
            else{
                if(intervals[i][0]>left[1]){
                    count++;
                    left[0]=intervals[i][0];
                    left[1]=intervals[i][1]>right?right:intervals[i][1]-1;
                    right=intervals[i][1];
                }
                else
                    right=min(right,intervals[i][1]);
            }
        }
        return count;
    }
};
// ```
