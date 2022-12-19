### 解题思路
低配版是对整个数列排序后，选前k个

### 代码

```java
class Solution {
    public int[] getLeastNumbers(int[] arr, int k) {
        Arrays.sort(arr);
        int[] res = new int[k];
        for(int i=0; i<k; i++) {
            res[i] = arr[i];
        }
        return res;
    }
}
```

### 解题思路
事实上并不需要对整个数列都排序的，借用快排的思想（不了解快排的小盆友可以先看[这里](https://leetcode-cn.com/problems/sort-an-array/solution/shi-shi-hou-biao-yan-zhen-zheng-de-ji-zhu-liao-by-/)），当找到`p`的正确位置后，比较`p`与`k`的大小：
- 如果相等，由于`p`左边的都是比`p`小的，也就是都是比`k`小的，那么事实上前k个数已经找到了，直接返回即可
- 如果`p`大于`k`，说明不需要关心比`p`大的数的顺序如何，只需要进一步对`p`左边的数组快排
- 如果`p`小于`k`，说明`p`左边的数无论顺序如何都要了，只需要进一步对`p`右边的数组快排
总之只需要根据情况对一侧递归而不是两侧都进行递归，省了一半的力气，具体代码也只是在[快排](https://leetcode-cn.com/problems/sort-an-array/solution/shi-shi-hou-biao-yan-zhen-zheng-de-ji-zhu-liao-by-/)的基础上稍作修改即可

### 代码

```java
class Solution {
    public int[] getLeastNumbers(int[] arr, int k) {
        quickselect(arr, 0, arr.length-1, k);
        int[] res = new int[k];
        for(int i=0; i<k; i++) {
            res[i] = arr[i];
        }
        return res;
    }

    public void quickselect(int[] nums, int l, int r, int k) {
        if(l < r) {
            int p = partition(nums, l, r);
            if(k == p) {
                return;
            } else if(k < p) {
                quickselect(nums, l, p-1, k);
            } else {
                quickselect(nums, p+1, r, k);
            }
        }
    }

    public int partition(int[] nums, int l, int r) {
        int p = nums[r];
        int i = l;
        for(int j=l; j<r; j++) {
            if(nums[j] < p) {
                swap(nums, i, j);
                i += 1;
            }
        }
        swap(nums, i, r);
        return i;
    }

    public void swap(int[] nums, int a, int b) {
        int temp = nums[a];
        nums[a] = nums[b];
        nums[b] = temp;
    }
}
```