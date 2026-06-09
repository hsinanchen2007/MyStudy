class Solution {
public:
    int findPeakElement(vector<int>& nums) {
       
        
        long l, h, med;
        int size = nums.size();
        
        l = 0;
        h = size-1;
        
        //      [L]   [R]
        //[med]  >     >    /\  ==>  ok
        //       >     <    /   ==>  go right
        //       <     <    \/  ==>  
        //       <     >    \   ==>  go left
        // trouble :  when med = 0 : [med -1] will be error
        
        
        // finally, end with "\"
        // 我们需要考虑最后退出的时候是什么样子的？
        // 可能是 山峰 /\ 或者是单面峰： /  or  \
        // 仔细想想， 单面峰其实更统一一些 因为山峰可以用 单面峰的任何一种来替代
        // 那么接下来是： 那种单面峰更优？
        // 首先应该理解到： 如果是  /
        // 那么， 必定是 h = med -1;的形式（从 /\ 到 /, 显然是h-1了）
        //        也就是 只要[med]>[med+1], 就 h = med-1;
        // 另一面， 自然就是 l = med;
        // (为什么不+1？ 如果 h = med-1了， l 又 l = l+1, 那么最后就分不清是那种单面峰了==》那就不知道是 l是峰还是h是峰)
        //
        // 如果是 \
        // 那么相应就是： l = med+1 (/\ ==》 \)
        //              [med] < [med+1], 就 l = med+1
        // (为什么是和[med+1]比？  因为[med-1]在med == 0时 访存错误)
        // (可是[med+1]在 med==size-1的时候也是错误啊？ 但是med不会取到注意的值， 因为整数除法向下取整！)
        // 另一面 h = med;
        // 相等的情况呢？  没事，问题里规定了 相邻元素是不等的
        // 那 下次遇到 有相等的呢？
        // 如果相等，那么执行 h=med; 或者是 l = med的情况
        // 为什么？ 安全，向前/先后探会踩雷的
        // 理性一点解释： 把各种情况想了想， 都没事（或许我没想全）
        
        // 那 是中单峰都可以吗？
        // 不， 只有 \ 即， l = med+1才行
        // 还是因为 整数除法向下取整： l = med 是无法结束循环的
        
        // 
        
        while(l < h){
            med = (l + h)/2;
           if (nums[med] > nums[med+1]){
                h = med;
           }
            else{
                l = med+1;
            }
        }
        
       
        return l;
    }
};