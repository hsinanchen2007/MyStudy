### 解题思路
此处撰写解题思路
最短距离就是将所有数字都移动到它的中位数即可。这一点应该很好想。
所以只要将数组排序；
设中位数是m,m的左右两个数分别是a和b,那么将a和b移动到m很显然要移动(m-a)+(b-m)=b-a次，所以只要找到有几对这样的数即可，然后分别相减，在相加即可。是不是很简单。
### 代码

```java
class Solution {
    public int minMoves2(int[] nums) {
        int i=0,j=nums.length-1;
        int ret=0;
        Arrays.sort(nums);
        while(i<j){
            ret+=nums[j]-nums[i];
            i++;
            j--;
        }
        return ret;
    }
}
```