### 解题思路
这是最原始的方法，但是这种方法是可以很好的优化的：（参考[接雨水 方法2](https://leetcode-cn.com/problems/trapping-rain-water/solution/jie-yu-shui-by-leetcode/)）
**lh[i]是lh[i-1]和当前的height[i]的最大值**，这也算是动态规划的思想了，很妙啊我这么没想到！
于是可以用数组来记录每一个lh[i]和rh[i]。
但是这种方式虽然降低了时间复杂度(O(n^2->O(n)))，却增加了空间复杂度(O(1)->O(n))

接下来应该学习一下[接雨水](https://leetcode-cn.com/problems/trapping-rain-water/solution/jie-yu-shui-by-leetcode/)中的另外两中方法。


### 代码

```c
int trap(int* height, int heightSize){
    int i;
    int j,k;
    int count=0;
    for(i=0;i<heightSize;i++){
        //lh表示i左端最大的的值，rh表示i有段最大的值
        int lh=0,rh=0,h=0;
        //找到lh
        for(j=0;j<i;j++){
            if(lh<height[j]) lh=height[j];
        }
        //找到rh
        for(k=i+1;k<heightSize;k++){
            if(rh<height[k]) rh=height[k];
        }

        //当前i的高度height[i]若大于了lh或rh则此时没有水位(h==0)
        if(height[i]>=lh||height[i]>=rh){
            continue;
        } 
        if(lh>rh) h=rh;
        else h=lh;
        count+=h-height[i];        
    }
    
    return count;
}
```