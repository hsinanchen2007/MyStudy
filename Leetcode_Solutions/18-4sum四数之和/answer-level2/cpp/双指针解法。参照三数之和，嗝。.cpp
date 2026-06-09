// 思路：

            
//      四数之和与前面三数之和的思路几乎是一样的，嗝。（刚好前些天才写了三数之和的题解）
//      如果前面的三数之和会做了的话，这里其实就是在前面的基础上多添加一个遍历的指针而已。
//      会做三数之和的可以不用看下面的了。。
      
//      使用四个指针(a<b<c<d)。固定最小的a和b在左边，c=b+1,d=_size-1 移动两个指针包夹求解。
//      保存使得nums[a]+nums[b]+nums[c]+nums[d]==target的解。偏大时d左移，偏小时c右移。c和d相
//      遇时，表示以当前的a和b为最小值的解已经全部求得。b++,进入下一轮循环b循环，当b循环结束后。
//      a++，进入下一轮a循环。 即(a在最外层循环，里面嵌套b循环，再嵌套双指针c,d包夹求解)。

// 准备工作： 
          
//      因为要使用双指针的方法，排序是必须要做der~。 时间复杂度O(NlogN).

// 解决重复解： 
         
//      上面的解法存在重复解的原因是因为移动指针时可能出现重复数字的情况。所以我们要确保移动指针后，
//      对应的数字要发生改变才行哦。

// 时间复杂度：

//     a遍历O(N)里嵌套b遍历O(N)再嵌套c,d双指针O(N)--> O(N^3)。 总比暴力法O(N^4)好些吧。
    
// ![1569476546(1).png](https://pic.leetcode-cn.com/cb421598a0ec2fa6fa6396b580a42411faf9b1483eff0a7582d6b142e41d6fff-1569476546\(1\).png)

// 代码块
// ```
class Solution{
	public: 
	vector<vector<int>> fourSum(vector<int>& nums, int target) {
        sort(nums.begin(),nums.end());
        vector<vector<int> > res;
        if(nums.size()<4)
        return res;
        int a,b,c,d,_size=nums.size();
        for(a=0;a<=_size-4;a++){
        	if(a>0&&nums[a]==nums[a-1]) continue;      //确保nums[a] 改变了
        	for(b=a+1;b<=_size-3;b++){
        		if(b>a+1&&nums[b]==nums[b-1])continue;   //确保nums[b] 改变了
        		c=b+1,d=_size-1;
        		while(c<d){
        			if(nums[a]+nums[b]+nums[c]+nums[d]<target)
        			    c++;
        			else if(nums[a]+nums[b]+nums[c]+nums[d]>target)
        			    d--;
        			else{
        				res.push_back({nums[a],nums[b],nums[c],nums[d]});
        				while(c<d&&nums[c+1]==nums[c])      //确保nums[c] 改变了
        				    c++;
        				while(c<d&&nums[d-1]==nums[d])      //确保nums[d] 改变了
        				    d--;
        				c++;
        				d--;
					}
				}
			}
		}
		return res;
    }
};
// ```
// 有不对的地方麻烦帮忙指正一下😄。

// 觉得有用给点个赞呢，看到右上角小铃铛提示有人点赞的感觉简直不要太爽。

      
     