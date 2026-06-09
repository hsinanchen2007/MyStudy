### 解题思路

##### 1. 题目概述：灯泡开关

##### 2. 思路：
   - 特征：灯的编号从 1 到 n;若当前打开灯的数量,等于目前为止打开的灯的最大编号,就可以说明全部灯都为蓝色了;
   - 方案：遍历,获取最大编号,同时统计打开灯的数量,满足条件,则统计;
   - 结果：最后的统计结果,即为解;

##### 3. 知识点：数组

##### 4. 复杂度分析: 
   - 时间复杂度：O(n)
   - 空间复杂度：O(1)


### 代码

```csharp []
public class Solution {
        public int NumTimesAllBlue(int[] light)
        {
            var forReturn = 0;
            var maxLight = 0;
            for (var i = 0; i < light.Length; i++)
            {
                maxLight = Math.Max(maxLight, light[i]);

                if (i + 1 == maxLight)
                    forReturn++;
            }

            return forReturn;
        }
}
```

### 解题思路

##### 1. 题目概述：灯泡开关 III

##### 2. 思路：
   - 特征：灯泡自身一共有 3 种状态(关闭,打开,蓝色);每次打开的都是之前处于关闭状态的灯泡,至于是否应该变成蓝色,则主要依靠它前面的灯泡;
   - 方案：每次点亮一盏灯,然后通过检测它前面的一盏灯是否为蓝色,决定是否把当前灯,以及后的灯也修改为蓝色;判断每轮全部的灯是否都为蓝色,只需要判断最后一盏打卡的灯是否为蓝色即可
   - 结果：记录每一次全部为蓝色的操作次数,即为最后的结果

##### 3. 知识点：数组

##### 4. 复杂度分析: 
   - 时间复杂度：O(n)
   - 空间复杂度：O(n)


### 代码

```csharp []
public class Solution {
        public int NumTimesAllBlue1(int[] light)
        {
            var flag = new int[light.Length + 1];
            flag[0] = 2;

            var forReturn = 0;
            var maxPos = 0;
            foreach (var lightItem in light)
            {
                maxPos = Math.Max(maxPos, lightItem);

                flag[lightItem] = 1;

                SetBlue(flag, lightItem - 1);

                if (flag[maxPos] == 2)
                    forReturn++;
            }

            return forReturn;
        }

        private void SetBlue(int[] flag, int startIndex)
        {
            if (flag[startIndex] == 0 || flag[startIndex] == 1) return;

            for (var i = startIndex + 1; i < flag.Length; i++)
            {
                if (flag[i] == 1)
                    flag[i] = 2;
                else
                    break;
            }
        }
}
```