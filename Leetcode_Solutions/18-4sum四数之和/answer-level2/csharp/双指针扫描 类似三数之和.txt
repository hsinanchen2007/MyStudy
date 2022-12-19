### 解题思路
刚开始看了一下 跟之前的三数之后差别不大 唯一的就是多了一个指针 
我就假想成 左右双扫描点的概念 就在三数之后的基础上改动了一下 发现有一些问题
左进位完成后 让右进位 但是这样会有重复的结果出现 
### 摸索中的代码
```
public class Solution {
    public IList<IList<int>> FourSum(int[] nums, int target) {
           IList<IList<int>> listAll = new List<IList<int>>();
            if (nums.Length < 4) return listAll;
            Array.Sort(nums);
           
            int len = nums.Length;
            int x = 0, y=len, z, e;
            int sum = 0;
            bool go = false;//判断应该左进位 还是右进位
            //x是扫描起点 y是扫描终点 z是左扫描点 e是右扫描点 z<e e<y
            for (; x < len - 1; x++)
            {
                if (x > 0 && nums[x] == nums[x - 1]) continue;
                if (target>0 && nums[x] > target) break;
                y= len - 1;
                z = x + 1;//左扫描点
                e = y - 1;//右扫描点
                while (z<y-1)//这儿不能以e作为循环结束的条件
                {
                    sum = nums[x] + nums[y] + nums[z] + nums[e];
                    if (sum == target)//相等 左进位
                    {
                        listAll.Add(new List<int>() {nums[x],nums[z],nums[e], nums[y]});
                        while (z < e && nums[z] == nums[++z]) ;
                    
                    }
                    else
                    {
                        if (sum > target)
                        {
                            while (z < e && nums[e] == nums[--e]) ;
                        }
                        else
                        {
                            while (z < e && nums[z] == nums[++z]) ;
                        }
                    }
                    if(z>=e)//如果坐标相重合 并且是左进位 那么
                    {
                        while (z < y && nums[y] == nums[--y]) ;
                        e = y - 1;
                        z = x + 1;
                    }
                }
            }
            return listAll;
    }
}

```
在我懊恼不已的时候 我打开了题解 妈的 发现虽然都是双指针 但是左定点其实是不动的 就是在三数之和的版本上增加了一个点 下图的z点

那么问题来了 5数之和 6数之和 亦或是n数之和呢 

难道还是套公式 ？

这窝要去思考一下
### 成功的代码

```csharp
public class Solution {
    public IList<IList<int>> FourSum(int[] nums, int target) {
             IList<IList<int>> listAll = new List<IList<int>>();
            if (nums.Length < 4) return listAll;
            Array.Sort(nums);
           
            int len = nums.Length;
            int x = 0, y=len, z, e;
            int sum = 0;
           
            //x是扫描起点 y是扫描终点 z是左扫描点 e是右扫描点 z<e e<y
            for (; x < len - 1; x++)
            {
                if (x > 0 && nums[x] == nums[x - 1]) continue;
                if (target>0 && nums[x] > target) break;
                z = x + 1;//左第二定点
                for (; z < len-1; z++)
                {
                    if (z>x+1 && nums[z] == nums[z-1]) continue;
                    y = len - 1;//右侧终点
                    e = z + 1;//左扫描点
                    while (e < y)//这儿不能以e作为循环结束的条件
                    {
                        sum = nums[x] + nums[y] + nums[z] + nums[e];
                        if (sum == target)//相等 左进位
                        {
                            listAll.Add(new List<int>() { nums[x], nums[z], nums[e], nums[y] });
                            while (e < y && nums[e] == nums[++e]) ;
                        }
                        else
                        {
                            if (sum > target)
                            {
                                while (e < y && nums[y] == nums[--y]) ;
                            }
                            else
                            {
                                while (e < y && nums[e] == nums[++e]) ;
                            }
                        }

                    }
                }
               
            }
            return listAll;
    }
}
```