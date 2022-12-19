### 初步思路
刚拿到题目的时候大致将可能出现的结果分成了两种情况。第一种是所给目标x小于所给数组的最小值或大于所给数组的最大值，这样只需要取数组的前k个或后k个元素即可满足要求。第二种是所给目标x在数组中，这样需要讨论x实际所处的位置即x前是否有k-1个元素。

### 解题思路
如果按照上面最初的思路进行讨论会发现分支情况过多，也就是说需要较多的`else if`结构。如果我们应用所给数组的有序性和不重复性来解题，运用算法提取一段数组元素，解题效率将会大大提升。
使用二分法解题过程中需要明确两点：左右边界何时需要移动以及如何移动。下面来讨论这两点问题。我们换一种思路，不使用二分法寻找待找元素x，而是找满足题目要求区间的起始元素t。寻找元素t过程中，我们引入类似滑动窗口的机制，将arr[mid]的值与待找元素x作差，将其与arr[mid+k]元素与x的差进行比较。如果前者的值小于等于后者，说明该窗口更贴近右侧（即与题目的`smaller elements are always preferred`相违背），需要向左移动，此时我们令`right = mid`从而实现窗口左移。如果前者的值大于后者，说明该窗口过于偏左，即不是与目标元素x**最近**的k个元素，此时我们令`left = mid + 1`从而实现窗口右移。
在窗口左移过程中还有一点需要注意，如果默认`mid+k`的值为合法下标，容易造成数组下标越界问题。我们还需要使用语句比较`mid+k`和length的大小，如果`mid+k >= length`，说明窗口偏右，无法提取符合要求的k个元素，将窗口左移即可。

### 代码

```java
class Solution {
    public List<Integer> findClosestElements(int[] arr, int k, int x) {
        List<Integer> result = new ArrayList<Integer>();
        int left = 0;
        int length = arr.length;
        int right = length - 1;
        while(left < right){
            int mid = (left + right) >>> 1;
            if(mid + k >= length || Math.abs(arr[mid] - x) <= Math.abs(arr[mid+k] - x)){
                right = mid;
            }
            else{
                left = mid + 1;
            }
        }
        for(int i = left;i<left+k;i++){
            result.add(arr[i]);
        }
        return result;
    }
}
```