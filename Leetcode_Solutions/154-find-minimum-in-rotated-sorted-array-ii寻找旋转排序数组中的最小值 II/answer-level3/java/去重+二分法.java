这道题是从 [33. 搜索旋转排序数组]一步步衍生过来的。 
在33题中，在旋转数组中查一个数，解题思路是找到旋转点，也就是找到max的位置。
如何寻找max呢?旋转后的数组有几个特点：
 + 1.整个数组会被划分成两个升序的区域。
 + 2.找到一个中间值，如果nums[left]>nums[mid],那么说明峰值(max)一定会在mid-1与left之间，因此收敛右边界。
 + 3.如果nums[left]<=nums[mid],那么说明依旧满足升序，这个时候峰值(max)一定会在left+1与len-1之间，因此收敛左边界的同时，重置右边界。
```java
    // 寻找旋转点(max)的代码如下:
    public int findMax(int[] nums) {
        if (nums.length==0)return -1;
        int l = 0;
        int r = nums.length-1;
        // 查找旋转点 -> max
        while(l<r){
            int mid = (l+r+1) >>>1;
            // 大于 右边收敛
            if(nums[l] > nums[mid] ){
                r = mid -1;
            }
            else {
                l = mid;
                r = nums.length-1;
            }
        }
        return nums[l];
    }
```
以上代码仅仅适用于非重复元素的情况下，那么元素重复了该怎么办呢？例如[2,1,2,2,2].
我的思路其实很简单，就是既然你存在重复，那我遇到重复就给你去掉一个，直到你满足我以上的代码。
分析一下存在重复元素会出现的问题：
 + 基于demo里面的测试用例，第一次判断的时候，mid定位到index=2，而left定位到index=0;根据以上代码的逻辑就出问题了，直接判定左边区域是有序的，最小值在左边区域就直接被pass了。

那如何解决这个问题呢？引发以上问题的原因就是因为首尾元素都相同，导致判断出了问题。一开始我以为将nums[l] > nums[mid]改完nums[l] >= nums[mid]就可以了，但是这样又会导致最小值在右区间的时候被pass掉。
因此有了最后的去重，只需要去除首尾相同的情况就可以了。最后的代码如下：
```java    
    public int findMin(int[] nums) {
        if (nums.length==0)return -1;
        
        int l = 0;
        int r = nums.length-1;
        // 去重
        while(l<r&&nums[l]==nums[r] ){
            l++;
        }
        int t =l;
        // 查找旋转点 -> max
        while(l<r){
            int mid = (l+r+1) >>>1;
            // 大于 右边收敛
            if(nums[l] > nums[mid]){
                r = mid -1;
            }
            else {
                l = mid;
                r = nums.length-1;
            }
        }
        // 如果是全局升序，那么最小值就是index=0
        return l==nums.length-1?nums[t]:nums[l+1];
    }
```
其实说是题解，更像是写的笔记，因为看了下评论和题解没有类似的思路，所以决定记录一下，说不定有哪位同学和我一样的思路呢~
