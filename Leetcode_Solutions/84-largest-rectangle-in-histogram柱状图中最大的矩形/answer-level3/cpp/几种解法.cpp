- 暴力查找
遍历，每次找左边和右边比他小的边界值，想法很简单，
```
// //暴力
// class Solution {
// public:
//     int toleft(vector<int>& heights,int index){
//         int res=0;
//         for(int i=index-1;i>=0;i--){
//             if(heights[i]>=heights[index]){
//                 res++;
//             }else{
//                 break;
//             }
//         }
//         return res;
//     }
//     int toright(vector<int>& heights,int index){
//         int res=0;
//         for(int i=index+1;i<heights.size();i++){
//             if(heights[i]>=heights[index]){
//                 res++;
//             }
//             else{
//                 break;
//             }
//         }
//         return res;
//     }
//     int largestRectangleArea(vector<int>& heights) {
//         int _max=0;
//         for(int i=0;i<heights.size();i++){
//             _max=max(_max,heights[i]*(toleft(heights,i)+toright(heights,i)+1));
//         }
//         return _max;
//     }
// };
```
- 分治法
参考官方题解，但是效率确实不如法一的暴力搜索
```
//分治 超时，不如上一个暴力搜索
// class Solution{
//  public:
//     int helper(vector<int>& heights,int start,int end){
//         if(start>=end)return 0;
//         int index=start;
//         int minHeight=heights[start];
//         for(int i=start;i<end;i++){
//             if(heights[i]<minHeight){
//                 minHeight=heights[i];
//                 index=i;
//             }
//         }
//         return max(max(minHeight*(end-start),helper(heights,0,index)),helper(heights,index+1,end));
//     }
//     int largestRectangleArea(vector<int>& heights) {
//         return helper(heights,0,heights.size());
//     }
// };
```


- 单调栈
这个方法是真的骚，搁我这辈子估计也想不出来。也是看的官方题解，也就是记录一下吧，
很巧妙的解法，维护一个单调栈，栈内元素存放序号，每次遇到`heights[i]<heights[Stack.top()]`的就开始更新最大值，官方题解的图挺好的。
```
//单调栈
class Solution{
 public:
    int largestRectangleArea(vector<int>& heights) {
        stack<int>Stack;
        Stack.push(-1);
        int length=heights.size();
        int res=0;
        for(int i=0;i<heights.size();i++){  
            while(Stack.top()!=-1&&heights[Stack.top()]>=heights[i]){
                int val=Stack.top();
                Stack.pop();
                res=max(heights[val]*(i-Stack.top()-1),res);
            }
            Stack.push(i);
        }
        while(Stack.top()!=-1){
            int val=Stack.top();
            Stack.pop();
            res=max(heights[val]*(length-Stack.top()-1),res);
        }
        return res;
    }
};
```


