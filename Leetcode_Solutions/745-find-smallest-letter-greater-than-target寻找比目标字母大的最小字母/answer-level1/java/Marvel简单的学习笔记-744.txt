### 解题思路
本题也是要求在一个有序序列中查找第一个满足某条件的元素。解决本题仅需使用upper_bound()或lower_bound()方法即可，就能找到第一个满足某条件的数。两个方法中，前者用于查找第一个**大于**某值的元素，后者用于查找第一个**大于等于**某值的元素。写法本质一样，如下所示。当题目问是否存在某个数时，就可以使用传统的二分查找。
本题显然查找的是第一个大于某值的元素，这种问题要注意一点：**hi的取值是数组最后一个元素下标加一**。因为数组最大的元素也不一定大于某值，即数组中不存在大于某值的元素。hi这样取值后，如果不存在满足条件的元素，返回的是最后一个元素下标加一。这种做法相当于返回第一个满足某条件的元素的位置，若该元素不存在，则返回假设它存在则它在数组中应处于的位置。

### 代码

```java
class Solution {
    public char nextGreatestLetter(char[] letters, char target) {
        int lo=0,hi=letters.length;
        while(lo<hi)
        {
            int mid=lo+(hi-lo)/2;
            if(letters[mid]>target) hi=mid;
            else                    lo=mid+1;
        }
        if(lo==letters.length)  return letters[0];
        else                    return letters[lo];
    }
}
```