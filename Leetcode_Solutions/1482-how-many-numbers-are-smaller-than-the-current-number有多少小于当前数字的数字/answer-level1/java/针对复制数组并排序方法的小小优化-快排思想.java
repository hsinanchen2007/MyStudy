    这里关于其他几种常见解法就不写了，只是想单独讨论一下标题所述的问题，提供一个思路。下面从三个方面来阐述：
    **复制数组并排序方法是什么？**
    **快排如何优化？**
    **代码及运行结果**

# 1.复制数组并排序方法是什么？
    这个方法在很多题解中提到过，思路很简单：
```
arr = Arrays.copyOf(nums,nums.length);//先复制一份数组
Arrays.sort(arr);//将数组排序，步骤A
```
    这样对于arr中处于下标i的元素而言，小于它的元素数量 = arr中等于arr[i]的所有元素的最小下标值。
    例如若arr={1,1,2,2,3,4,4,5};那么对于i=6的元素来说，小于它的元素数量=5，即最左边的4
    因此，第三步就是存储这些值，无论是使用map还是数组，都要遍历一遍arr，这里以数组为例：
```
int[] cnt = new int[101];//由于题设给出数组元素范围为0<=A[i]<=100，所以101个取值可能
//遍历存储下标，步骤B --------------**将要优化的地方，将步骤A和步骤B结合**
for(int i = arr.length-1;i>=0;i--){
    int j = i;
    while(j>0&&arr[j]==arr[j-1]) j--;
    cnt[arr[i]] = j;
}
//构造数组返回
int[] res = new int[nums.length];
for(int i = 0;i<nums.length;i++){
    res[i] = cnt[nums[i]];
}
return res[i];
```
**时间复杂度：**不考虑数组的复制，排序+两次遍历，即O(nlogn)+O(n)+O(n) = O(nlogn)

# **2.快排如何优化？**
  上个解法用到了Arrays.sort方法，然后**必须再遍历一次存储下标。**我的优化思路是：
  能否做到**在排序的时候就顺便把需要的信息存到map或数组中呢？**
  首先，快排的关键在于，一次partition将数组划分为小于临界值和大于临界值的部分。也就是说，对于临界值pivot，我们**经过一次partition就能得到满足“左边<pivot值”条件的数组了，那么pivot的下标不正好就是我们要的值吗？**
  但是，本题会遇到一个问题：
  - 还是举例[1,1,2,2,3,4,4,5],当使用指针交换法等partition方法时，将nums[0]作为pivot，最后返回的下标是1，这不是错了吗？有没有办法返回正确的值呢？这里推荐使用“荷兰国旗”问题的解法实现快排中的partition方法。（具体方法看下面代码或百度）
  - 该方法能够达到的效果是：对于pivot，partition后，数组的形式很严格而友好：{严格小于pivot的数，等于pivot的数，严格大于pivot的数}。该partition方法返回的也是“等于pivot数”区域的左边界和右边界
  - 例如：对于数组[5,9,5,4,3,7,2,5,1],pivot=5,partition后的结果就是[1,4,3,2,5,5,5,7,9]，返回下标数组[4,6],4就是要存储的下标了。
在传统的partition实现方法，即挖坑法和指针交换法中，则无法达到这样的效果。
最后运用递归，即可得到答案。
```
时间复杂度：不考虑数组复制，快排+一次遍历=O(nlogn)+O(n)=O（nlogn），优化了一个O(n)。
```

# 3.代码及运行结果
```
class Solution {
    public int[] smallerNumbersThanCurrent(int[] nums) {
        int[] arr = Arrays.copyOf(nums,nums.length);
        //荷兰国旗式partition，存储小于中间的临界值的数的个数，递归
        int[] cnt = new int[101];
        quickSort(arr,0,arr.length-1,cnt);
        //遍历数组，查询hashmap，返回
        int[] res = new int[nums.length];
        for(int i = 0;i<nums.length;i++){
            res[i] = cnt[nums[i]];
        }
        return res;
    }
    private void quickSort(int[] arr,int l, int r,int[] cnt){
        if(arr==null||l>r)
            return;
        if(l==r&&cnt[arr[l]]==0){
            cnt[arr[l]] = l;//说明arr[l]这个数在全数组中只出现了一次（不然l就不会等于R了），直接存l
            return;
        }
        int[] res = partition(arr,l,r);
       cnt[arr[res[0]]] = res[0];//arr[res[0]]即为pivot，res[0]即为下标
        quickSort(arr,l,res[0]-1,cnt);
        quickSort(arr,res[1]+1,r,cnt);
    }
    private int[] partition(int[] arr, int l, int r){
        int left = l-1;//表示小于pivot的区域的最右边下标，初始时该区域为空，所以下标为l-1
        int right = r+1;//表示大于pivot的区域的最左边下标，初始时该区域为空，所以下标为r+1
        int p = l;//移动指针，用于遍历arr数组
        int temp = arr[l];
        while(p<right){
            if(arr[p]<temp) swap(arr,++left,p++);//将左区域外的第一个数和当前元素交换
            else if(arr[p]>temp) swap(arr,--right,p);//将右区域外的第一个数和当前元素交换
            else p++;//相等的情况下，p继续向前移动
        }
        return new int[]{left+1,right-1};//返回值即为等于pivot数的区域的左界下标和右界下标
    }
    private void swap(int[] arr, int l, int r){
        int temp = arr[l];
        arr[l] = arr[r];
        arr[r] = temp;
    }
}
```
**运行结果：**
![p1365.png](https://pic.leetcode-cn.com/ad733e0c3c1bc3ffc03d21ecbeb0ce83a48234646a63d590a86ea1eb0359c6c5-p1365.png)




