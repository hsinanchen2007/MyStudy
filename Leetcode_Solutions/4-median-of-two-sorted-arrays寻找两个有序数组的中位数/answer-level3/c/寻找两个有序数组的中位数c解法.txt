# 题目

给定两个大小为 m 和 n 的有序数组 nums1 和 nums2。
请你找出这两个有序数组的中位数，并且要求算法的时间复杂度为 O(log(m + n))。
你可以假设 `nums1`和 `nums2` 不会同时为空。

示例 1:
```
nums1 = [1, 3]
nums2 = [2]

则中位数是 2.0
```
示例 2:
```
nums1 = [1, 2]
nums2 = [3, 4]

则中位数是 (2 + 3)/2 = 2.5
```

# 题解
### 暴力法
其实这个方法是最容易想到的方法,把两个`有序`数组合并成一个有序数组.然后直接找到中位数.

##### 实现代码
```
double findMedianSortedArrays(int* nums1, int nums1Size, int* nums2, int nums2Size){
    int allcount = nums1Size+ nums2Size;
    int z = allcount/2;
    int y = allcount%2;
    
    int numOneIndex = z;
    int numTwoIndex = y==1?z:z-1;
    int num1Index=0;
    int num2ndex=0;
    
    if (nums1Size==0) {
        return (nums2[numOneIndex]+nums2[numTwoIndex])/2.0;
    }
    if (nums2Size == 0) {
        return (nums1[numOneIndex]+nums1[numTwoIndex])/2.0;;
    }
    
    double result = 0.0;
    int * allNum = malloc(allcount * sizeof(int));
    
    do {
        if (nums1[num1Index]>nums2[num2ndex]) {
            allNum[num1Index+num2ndex]=nums2[num2ndex];
            num2ndex++;
        }else{
              allNum[num1Index+num2ndex]=nums1[num1Index];
              num1Index++;
            
        }
        if (num2ndex == nums2Size) {
            for (int i=num1Index; i<nums1Size; i++) {
                 allNum[num1Index+num2ndex]=nums1[num1Index];
                 num1Index++;
            }
            break;
        }
        if (num1Index == nums1Size) {
            for (int i=num2ndex; i<nums2Size; i++) {
                 allNum[num1Index+num2ndex]=nums2[num2ndex];
                 num2ndex++;
            }
            break;
        }
        
    } while (1);
    
    
    result=(allNum[numOneIndex]+allNum[numTwoIndex])/2.0;;
    free(allNum);
    return result;
}
```
##### 复杂度分析
`时间复杂度：`
 因为把所有的数都排列了一遍,因此时间复杂度是 O(m+n)
`空间复杂度`:
需要占用 m+n 内存  .因此  空间复杂度也是O(m+n)

### 暴力法之直接找数

因为是两个有序数组,因此我们可以直接查找一半数据,将中位数解答出来.

##### 实现代码
 ```
double findMedianSortedArrays(int* nums1, int nums1Size, int* nums2, int nums2Size){
    int allcount = nums1Size+ nums2Size;
       int z = allcount/2;
       int y = allcount%2;
       
       int numOneIndex = z;
       int numTwoIndex = y==1?z:z-1;
       int num1Index=0;
       int num2ndex=0;
       int * temp = NULL;
    if (nums1Size==0) {
        return (nums2[numOneIndex]+nums2[numTwoIndex])/2.0;
    }
    if (nums2Size == 0) {
        return (nums1[numOneIndex]+nums1[numTwoIndex])/2.0;;
    }
    double result =0.0;
    int frontNum =0.0;
    int currentNum = 0.0;
    do {
          frontNum =currentNum;
        if (num2ndex==nums2Size) {
            currentNum=nums1[num1Index];
            temp=&num1Index;
        }else if (num1Index==nums1Size){
            currentNum=nums2[num2ndex];
             temp=&num2ndex;
        }else{
            if (nums1[num1Index]>nums2[num2ndex] ) {
                currentNum=nums2[num2ndex];
                temp=&num2ndex;
            }else{
                    currentNum=nums1[num1Index];
                    temp=&num1Index;
            }
        }

        if ((num1Index+num2ndex) == numOneIndex) {
            if (y==1) {
                result =(currentNum+currentNum)/2.0;
            }else{
                result =(currentNum + frontNum)/2.0;
            }
            break;
        }
        (*temp)++;
    } while (1);
         
      return result;
}

```
复杂度分析
`时间复杂度：`
因为之查找了一半数据,因此时间复杂度是 O(m/2+n/2)
空间复杂度:
不需要开辟内存 ,复杂度是O(1)

>  上述算法,其实时间复杂度并没有比`暴力法`减少,反而增加了.这是因为,每次都进行了变量之间的反复赋值导致时间增加.

### 递归法(官方解法翻译)
为了解决这个问题，我们需要理解 “中位数的作用是什么”。在统计中，中位数被用来：
> 将一个集合划分为两个长度相等的子集，其中一个子集中的元素总是大于另一个子集中的元素。

如果理解了中位数的划分作用，我们就很接近答案了。
首先，让我们在任一位置 i 将 A 划分成两个部分：
```
                 left_A             |        right_A
    A[0], A[1], ..., A[i-1]  |  A[i], A[i+1], ..., A[m-1]
```
由于 A 中有m 个元素， 所以我们有 m+1 种划分的方法（i=0∼m）。
我们知道：

> len(left_A)=i,len(right_A)=m−i.
> 注意：当 i=0 时，left_A 为空集， 而当 i=m 时, right_A 为空集。

采用同样的方式，我们在任一位置 j 将 B 划分成两个部分：
```
                  left_B            |        right_B
    B[0], B[1], ..., B[j-1]  |  B[j], B[j+1], ..., B[n-1]
```
将 left_A 和 left_B 放入一个集合，并将 right_A 和 right_B 放入另一个集合。 再把这两个新的集合分别命名为left_part 和right_part：

```
               left_part          |        right_part
    A[0], A[1], ..., A[i-1]  |  A[i], A[i+1], ..., A[m-1]
    B[0], B[1], ..., B[j-1]  |  B[j], B[j+1], ..., B[n-1]
```
如果我们可以确认：

> + 1.len(left_part)=len(right_part)
> + 2.max(left_part)≤min(right_part)

那么，我们已经将 {A,B} 中的所有元素划分为相同长度的两个部分，且其中一部分中的元素总是大于另一部分中的元素。那么：

median =$\left(\frac{max(left\_part)+min(right\_part)}{2}\right)$ 
​	
 要确保这两个条件，我们只需要保证：

> 1.   i+j=m−i+n−j（或：m−i+n−j+1）
>   如果 n≥m，只需要使  i=0∼m, j= $(\frac{m+n+1}{2})-i$ 
> 2. B[j−1]≤A[i] 以及 A[i−1]≤B[j]

ps.1 为了简化分析，我假设 
A[i−1],B[j−1],A[i],B[j] 总是存在，哪怕出现 i=0,i=m, j=0,或是 j=n 这样的临界条件。我将在最后讨论如何处理这些临界值。

ps.2 为什么 n≥m？由于0≤i≤m 且  j= $(\frac{m+n+1}{2})-i$，我必须确保 j 不是负数。如果 n<m，那么 j 将可能是负数，而这会造成错误的答案。(在 n≥m的时候,j一定不是负数的)
> 推导
> i<m⟹j>0 以及 i>0⟹j<n 始终成立，这是因为：
> m≤n, i<m⟹j= $(\frac{m+n+1}{2})-i$>$(\frac{m+n+1}{2})-m$≥ $(\frac{2m+1}{2})-m$≥0
> m≤n, i>0⟹j=$(\frac{m+n+1}{2})-i$<$(\frac{m+n+1}{2})≤$(\frac{2n+1}{2})$≤n


所以，我们需要做的是：
> 在 [0，m] 中搜索并找到目标对象 i，以使：B[j−1]≤A[i] 且A[i−1]≤B[j], 其中  j= $(\frac{m+n+1}{2})-i$

接着，我们可以按照以下步骤来进行二叉树搜索：
 + 1. 设 imin=0，imax=m, 然后开始在 [imin,imax] 中进行搜索。
+ 2. 令 i=$\frac{min+max}{2}$, j= $(\frac{m+n+1}{2})-i$

+ 3. 现在我们有 len(left_part)=len(right_part)。 而且我们只会遇到三种情况：

+ + B[j−1]≤A[i] 且 A[i−1]≤B[j]：
这意味着我们找到了目标对象 i，所以可以停止搜索。
+ + [j−1]>A[I]：
这意味着 A[i] 太小，我们必须调整 i 以使 B[j−1]≤A[i]。
`我们可以增大 i 吗？`
      是的，因为当 i 被增大的时候，j 就会被减小。
      因此 B[j−1] 会减小，而 A[i] 会增大，那么 B[j−1]≤A[i] 就可能被满足。
`我们可以减小 i 吗？`
      不行，因为当 i 被减小的时候，j 就会被增大。
      因此 B[j−1] 会增大，而 A[i] 会减小，那么 B[j−1]≤A[i] 就可能不满足。
所以我们必须增大 
i。也就是说，我们必须将搜索范围调整为 [i+1,imax]。
因此，设 imin=i+1，并转到步骤 2。

+ + A[i−1]>B[j]：
这意味着 A[i−1] 太大，我们必须减小 i 以使 A[i−1]≤B[j]。
也就是说，我们必须将搜索范围调整为 [imin,i−1]。
因此，设 imax=i−1，并转到步骤 2。

当找到目标对象 i 时，中位数为：

> max(A[i−1],B[j−1]), 当 m+n 为奇数时
> $\frac{max(A[i−1],B[j−1])+min(A[i],B[j])}{2}$,当m+n为偶数时

现在，让我们来考虑这些临界值 i=0,i=m,j=0,j=n，此时 A[i−1],B[j−1],A[i],B[j] 可能不存在。其实这种情况比你想象的要容易得多。

我们需要做的是确保 max(left_part)≤min(right_part)。 因此，如果 i 和 j不是临界值（这意味着 A[i−1],B[j−1],A[i],B[j] 全部存在）, 那么我们必须同时检查 B[j−1]≤A[i] 以及 
A[i−1]≤B[j] 是否成立。但是如果 A[i−1],B[j−1],A[i],B[j] 中部分不存在，那么我们只需要检查这两个条件中的一个（或不需要检查）。

举个例子，如果 i=0，那么 A[i−1] 不存在，我们就不需要检查 A[i−1]≤B[j] 是否成立。
所以，我们需要做的是：

 > 在 [0，m] 中搜索并找到目标对象 i，以使：
(j=0 or i=m or B[j−1]≤A[i]) 或是(i=0 or j=n or A[i−1]≤B[j]),其中  j= $(\frac{m+n+1}{2})-i$

在循环搜索中，我们只会遇到三种情况：

> 1. (j=0 or i=m or B[j−1]≤A[i]) 或是 (i=0 or j=n or A[i−1]≤B[j])，这意味着 i 是完美的，我们可以停止搜索。
> 2. j>0 and i<m and B[j−1]>A[i] 这意味着 i 太小，我们必须增大它。
> 3. i>0 and j<n and A[i−1]>B[j] 这意味着 i 太大，我们必须减小它。


### 实现代码

```
#define SELFMAX(x,y) x>y?x:y
#define SELFMIN(x,y) x>y?y:x
//官方题解
double findMedianSortedArrays2(int* nums1, int nums1Size, int* nums2, int nums2Size){
    if (nums1Size > nums2Size) { // to ensure nums1Size<=nums2Size
        int*  temp = nums1; nums1 = nums2; nums2 = temp;
        int tmp = nums1Size; nums1Size = nums2Size; nums2Size = tmp;
    }
    int iMin = 0, iMax = nums1Size, halfLen = (nums1Size + nums2Size + 1) / 2;
    while (iMin <= iMax) {
        //找i中间
        int i = (iMin + iMax) / 2;
        int j = halfLen - i;
        //i 太小
        if (i < iMax && nums2[j-1] > nums1[i]){
            iMin = i + 1; // i is too small
        }
        else if (i > iMin && nums1[i-1] > nums2[j]) {
            iMax = i - 1; // i is too big
        }
        else { // i is perfect
            int maxLeft = 0;
            if (i == 0) { maxLeft = nums2[j-1]; }
            else if (j == 0) { maxLeft = nums1[i-1]; }
            
            else { maxLeft = SELFMAX(nums1[i-1], nums2[j-1]); }
            if ( (nums1Size + nums2Size) % 2 == 1 ) { return maxLeft; }

            int minRight = 0;
            if (i == nums1Size) { minRight = nums2[j]; }
            else if (j == nums2Size) { minRight = nums1[i]; }
            else { minRight = SELFMIN(nums2[j], nums1[i]); }

            return (maxLeft + minRight) / 2.0;
        }
    }
    return 0.0;
}

```
### 复杂度分析
 时间复杂度：
O(log(min(m,n)))，
首先，查找的区间是 [0,m]。
而该区间的长度在每次循环之后都会减少为原来的一半。
所以，我们只需要执行 log(m) 次循环。由于我们在每次循环中进行常量次数的操作，所以时间复杂度为 O(log(m))。
由于 m≤n，所以时间复杂度是 O(log(min(m,n)))。
空间复杂度：O(1)
我们只需要恒定的内存来存储 9 个局部变量， 所以空间复杂度为O(1)。

[寻找两个有序数组的中位数](https://leetcode-cn.com/problems/median-of-two-sorted-arrays/)
[github地址](https://github.com/NPOpenSource/leedCode)