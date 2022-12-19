### 解题思路
拿着这题我就大概了解到应该是x y之间的下标差值*两位下标对应的最小值 木桶理论
但是我用单次for循环试了几次发现都满足不了 还是看了题解才清楚了一点

程序就应该用程序的思路 不应该拿着题就开始做

后面用双for循环
```
      public int MaxArea(int[] height)
        {
//可行 但是超出了时间限制
            int len = height.Length;
            if (len > 1)
            {
                int min = 0;//最优最小值下标
                int max =len-1;//最优最大值下标
                for (int i = 0; i < len; i++)//双循环只能优化到700多ms
                {
                    for (int j = len-1; j >= 0; j--)//就这循环里面套循环丢失了大量性能
                    {
                        //这儿也是记录下标并且与之前的解进行判断 
                        if (i != j && j>i &&(j-i)*Math.Min(height[i],height[j])> (max - min) * Math.Min(height[max], height[min])) {
                            max = j;//记录 右坐标
                            min = i;//记录 左坐标
                        }
                    }
                }
                return (max-min)*(Math.Min(height[min],height[max]));//
            }
            return 1;
        }
```

然后这儿才理解到正确的双下标 应该是单次循环 左右递进判断 左小左进 右小右进 每次的面积存储 直接返回 省事 

```csharp
public class Solution {
  public int MaxArea(int[] height)
        {

            if (height.Length < 2)
                return 1;
            int x = 0;
            int y = height.Length - 1; ;
            int area = 0;
            while (x<y)
            {
                area=Math.Max( Math.Min(height[x], height[y]) * (y-x),area);
                if (height[x] > height[y])
                    y--;
                else
                    x++;
            }
            return area;
        
        
        }
}
```