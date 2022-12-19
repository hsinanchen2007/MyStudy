双指针，时间复杂度O(n)，空间复杂度O(1)，Java99.98%

首先使i指向height中的首个不为0元素，j指向i的下一个元素（注意判断越界问题）

初始化ans=0

j向后去找第一个大于等于height[i]的位置，找到后，先假设ij中间的位置全为0，即ans+=（height[i]*(j-i-1)）

再使i逐步++，ans减去每个height[i]，直至i=j（注意height[i]和height[j]不要减掉）

重复以上，直至j延申至末尾结束。

注意，若对于某个height[i]，往后没有比height[i]大的位置了，即i位置是向后的所有元素中最大的一个，要使height[i]--，再重新向后找j的位置，这是唯一需要回退j的地方。

最好的还是看代码

```
class Solution {
    public int trap(int[] height) {
        //若height为空，直接返回
        if(height.length==0)
            return 0;

        //初始化ans，寻找第一个不为0的位置i，使j指向i的下一位元素
        int ans=0;
        int i=0,j;
        while(i<height.length&&height[i]==0){
            i++;
        }
        j=i+1;

        //开始遍历
        while(j<height.length){
            //寻找第一个大于等于height[i]的位置j
            while(j<height.length&&height[j]<height[i]){
                j++;
            }
            //如果后面没有比height[i]大的位置，就将height[i]-1，再次寻找（其实也可以直接使用一个ming记录后面的最大值，这样能减少回退）
            if(j==height.length){
                height[i]--;
                j=i+1;
                continue;
            }
            //先x假设i、j中间的位置均能装水
            ans+=(height[i]*(j-i-1));
            //再在i逐步++的过程中减去不能装水的位置 
            while(i<j-1){
                i++;
                ans-=height[i];
            }
            i=j;
            j++;
        }
        return ans;
    }
}
```
