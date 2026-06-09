本题与[424. 替换后的最长重复字符](https://leetcode-cn.com/problems/longest-repeating-character-replacement/solution/hua-dong-chuang-kou-chang-gui-tao-lu-by-xiaoneng/)一样的套路，不过更为简单一点，**直接用count统计窗口内的0的个数**。当窗口内0的个数大于K时，我们需要缩小窗口；当窗口内0的个数小于等于k时，我们就可将窗口大小来与result来进行比较来确定是否更新result了。

**注：窗口内0的个数就是表示可以被1替换的个数！**

代码如下：
```cpp
class Solution {
public:
    int longestOnes(vector<int>& A, int K) {
        //count用来统计窗口中0的个数
        int left=0,right=0,count=0,result=0,size=A.size();
        
        while(right<size)
        {
            count+=A[right]==0;
            while(count>K)//当窗口内0的个数大于K时，需要缩小窗口
            {
                count-=A[left]==0;
                left++;
            }
            //窗口内0的个数小于等于k时，也就是可以该窗口内的0都可以替换，根据该窗口长度来确定是否更新result
            result=max(result,right-left+1);
            right++;
        }
        return result;
    }
};
```
