### 解题思路
该题本身不是很难，直接使用双指针即可，只不过需要注意两点的是：

- 1.计算从某一元素 A 到某一元素 B 之间的序列和；
- 2.方法最终需要返回的是二维数组，在转换的时候需要格外注意。

对于第 1 点，直接使用求和公式即可，例如求序列 3、4、5、6、7 的序列和，可以利用`等差数列的求和公式`直接计算：

$$
(7-3+1) * (3+7)/2=25
$$

对于第 2 点，使用`Java`的小伙伴，可以将每次找到的满足要求的序列放进一个`ArrayList`中，里面存放的是一个一个的数组，最后函数返回的时候，调用`toArray()`方法将多个序列（数组）再次转化成数组，使其变成二维数组即可。其实就是在外面又套了一层数组。

### 分析
例如`target = 9`，我们一步一步进行分析。我们让`left`指向第`1`个数，让`right`指向第`2`个数，如下所示：

```
 left
  ↓
  1    2    3    4    5    6    7    8    9
       ↑      
     right
```
**我们规定：left 和 right 指针只能向右走，不能回退（向左走）**。

每次对`left`到`right`范围内的序列进行求和，得到当前的序列和为`curSum`，判断当前的序列和`curSum`与`target`的大小关系。显然，存在三种情况：

- **curSum == target**，说明我们找到了一组等于`target`的序列和，此时将这组序列和进行遍历，放在一个一维数组中即可。
- **curSum < target**，说明我们当前的序列和比目标值`target`要小，此时我们就要移动指针了。如何移动呢？移动`left`还是`right`呢？当然是`right`啦，因为从`1`到`9`本来就是升序的，只有在`left`不动，`right`向右扩的时候，我的序列和才能变大，我才能一步一步增加到`target`。
- **curSum > target**，说明我们当前的序列和比目标值`target`要大，此时我就要向右移动`left`了，让整个序列和变小，这样才能接近`target`。

**注意 curSum == target 情况，既然我已经找到了一组等于`target`的序列和，那么如何再找下一组呢？**
**很简单嘛~直接让`left`向右移动一位，或者让`right`向右移动一位即可，这样的话，由于指针的移动，从而序列和就不会等于`target`了，所以就会在我们的`while`语句中循环操作，继续找下一组序列和了。**

### 例子
还是以`target = 9`为例，我们演示一下流程：
**初始状态：**
```
 left
  ↓
  1    2    3    4    5    6    7    8    9
       ↑      
     right
```
由于上图中的 $1+2=3<9$，所以`right`向右移动一位，如下所示：
```
 left
  ↓
  1    2    3    4    5    6    7    8    9
            ↑      
          right
```
由于上图中的 $1+2+3=6<9$，所以`right`再次向右移动一位，如下所示：
```
 left
  ↓
  1    2    3    4    5    6    7    8    9
                 ↑      
               right
```
由于上图中的 $1+2+3+4=10>9$，此时让`left`向右移动一位，`right`不动，如下所示：
```
      left
       ↓
  1    2    3    4    5    6    7    8    9
                 ↑      
               right
```
由于上图中的 $2+3+4=9=9$，好了，已经找到了一组序列和为`9`的序列，我们将其放进一个数组中保存即可。**此时，为了找到下一组，我们在这里将`left`向右移动一位**。如下图所示：
```
           left
            ↓
  1    2    3    4    5    6    7    8    9
                 ↑      
               right
```
由于上图中的 $3+4=7<9$，此时让`right`向右移动即可。再次根据`left`到`right`范围内的序列和与`target`进行判断，重复此操作，直至结束。（后面的过程就不画了，自己在纸上画一遍流程）


### 代码
以下两个部分的代码都是一样的，只不过一份没有注释，便于查看代码；另一份有注释，便于理解代码。
#### 无注释
```java
class Solution {
    public int[][] findContinuousSequence(int target) {
        if (target < 3) {
            return new int[0][0];
        }
        
        int left = 1;
        int right = 2;
        List<int[]> res = new ArrayList<>();

        while (left < right) {
            int curSum = (right - left + 1) * (left + right) >> 1;
            if (curSum == target) {
                int[] arr = new int[right - left + 1];
                int j = left;
                for (int i = 0; i < arr.length; i++) {
                    arr[i] = j++;
                }
                res.add(arr);
                left++;
            } else if (curSum < target) {
                right++;
            } else {
                left++;
            }
        }
        return res.toArray(new int[0][]);
    }
}
```

#### 有注释
```java
class Solution {
    public int[][] findContinuousSequence(int target) {
        if (target < 3) {
            return new int[0][0];
        }
        
        int left = 1;
        int right = 2;
        // 你看，我的 List 中存放的是数组哟
        // 也就是多组序列
        List<int[]> res = new ArrayList<>();

        while (left < right) {
            // 计算从 left 到 right 范围内的序列和
            // 小技巧：对于 A >> 1 ，就等价于将 A 除以 2 操作，即 A / 2
            int curSum = (right - left + 1) * (left + right) >> 1;
            if (curSum == target) {
                // 既然要将满足要求的序列和存放到数组中，
                // 那么我当然需要计算一下从 left 到 right 一共有多少个数呀
                int[] arr = new int[right - left + 1];
                int j = left;
                // 将 left 到 right 范围内的数存放到 arr 数组中 
                for (int i = 0; i < arr.length; i++) {
                    arr[i] = j++;
                }
                // 我已经找到了一组满足要求的序列，那么就把它放进 List 中吧
                res.add(arr);
                // 这里你当然也可以写成 right++
                left++;
            // 其它情况
            } else if (curSum < target) {
                right++;
            } else {
                left++;
            }
        }
        return res.toArray(new int[0][]);
    }
}
```
### 全部题解
《剑指Offer》的全部题解与 LeetCode 的部分题解在此下方，其中还包含**基础算法**与**进阶算法**，欢迎查看~
[LeetCode、SwordToOffer and other algorithms in Java.](https://github.com/dyfloveslife/LeetCodeAndSwordToOffer)