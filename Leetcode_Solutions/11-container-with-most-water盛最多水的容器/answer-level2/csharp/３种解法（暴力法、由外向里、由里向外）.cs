## 解法一（暴力法）
思路：直接两层遍历，分别计算任意两个桶之间的容积，然后记录最大的结果，作为中等难度的题目，这个方法可能会超时，最终不出所料在最后一个测试用例超时了，超时用例为15000个从大到小排列的数值，测试用例及源码如下：
[https://www.zhenxiangsimple.com/files/tech/testCase20200208.txt](https://www.zhenxiangsimple.com/files/tech/testCase20200208.txt)
1. 第一层遍历作为桶的左侧，第二层遍历，作为桶的右侧
2. 选择较小的值乘以间距，计算桶的容积
* 时间复杂度：O(n^2)
* 空间复杂度：O(1)
```csharp
public class Solution {
    public int MaxArea(int[] height) {
        int t,mx=0;
        for(int i=0;i<height.Length;i++)
        {//桶左侧
            t = 0;
            for(int j=i+1;j<height.Length;j++)
            {//桶右侧
                t = (j-i) * (height[i]>height[j]?height[j]:height[i]);//计算容积
                if(t > mx)
                {
                    mx = t;
                }
            }
        }
        return mx;
    }
}
```
***
## 解法二（从外向里）
思路：用两个指针分别从两边向中间进行查找，如果全部遍历就跟暴力法一样了，本算法使用较小的值向较大值的方向移动，因为X坐标变小后只有Y坐标变大才可能变得更大，因此选择舍弃较小（短）的Y值，向较大的方向移动来寻找更大的值。
1. 分别使用左右两个指针，从数组开始和结尾开始遍历
2. 值小的一边向另一边移动，直到两个指针相遇
* 时间复杂度：O(n)
* 空间复杂度：O(1)

```csharp
public class Solution {
    public int MaxArea(int[] height) {
        int l=0,r=height.Length-1,t,mx=0;
        while(l<r)
        {
            if(height[l] > height[r])
            {//右边小，右指针向左移动
                t = height[r] * (r-l);
                r--;
            }
            else
            {//左边小，左指针向右移动
                t = height[l] * (r-l);
                l++;
            }
            if(t>mx)
            {//记录最大值
                mx = t;
            }
        }
        return mx;
    }
}
```
*** 
## 解法三（从里向外）
思路：基于解法二的由外向里的过程，自然想到从上而下的思路，首先选择两个最高的值，然后桶外侧找最大值，因为高度减小了只有向外才能使得容积变大。
1. 找到最大值和次大值的索引，作为桶的左右边界
2. 在桶外面找最大的一个值，记录桶的容积，直到数组遍历结束
3. 这个跟解法二不同之处是，不是选其中一边里的做大值，而是两边的最大值，因为可能由于选择了较小的值导致拉低高度值

* 时间复杂度：O(n^2)
* 空间复杂度：O(1)

```csharp
public class Solution {
    public int findMaxIdx(int[] height,int l,int r)
    {  //寻找[l,r)内最大索引
        int ti = l;
        for(int i=l + 1;i<r;i++)
        {
            if(height[i] > height[ti])
            {
                ti = i;
            }
        }
        return ti;
    }

    public int findOutIdx(int[] height,int l,int r,out bool lFlag)
    {//寻找[l,r]外面最大索引
        lFlag = true;
        int li = -1;
        if(l > 0)
        {
            li = findMaxIdx(height,0,l);
        }

        if(r < height.Length - 1) 
        {           
            int ri = findMaxIdx(height,r+1,height.Length);
            if(li==-1 || height[li] < height[ri])
            {
                lFlag = false;
                li = ri;
            }
        }
        return li;
    }

    public int MaxArea(int[] height) {
        int t,mx=0,len = height.Length;
        int li=0,ri=-1,ti,tr=-1;
        bool flag;
        for(int i=1;i<len;i++)
        {//li最大值，ri次大值
            if(height[i] > height[li])
            {//比最大值还大
                tr = height[li];
                ri = li;
                li = i;
            }
            else if(height[i] > tr)
            {//介于中间
                tr=height[i];
                ri = i;
            }
        }
        if(li > ri)
        {//li为左边界，ri为右
            t = li;
            li = ri;
            ri = t; 
        }
        mx = (height[ri] > height[li]?height[li]:height[ri]) * (ri-li);
        while(ri<len-1 || li>0)
        {//交替切换
            ti = findOutIdx(height,li,ri,out flag);
            if(flag)
            {//向左拓宽了
                li = ti;
            }
            else
            {//向右
                ri = ti;
            }
            t = (height[ri] > height[li]?height[li]:height[ri]) * (ri-li);
            mx = t>mx?t:mx;
        }
        return mx;
    }
}
```
