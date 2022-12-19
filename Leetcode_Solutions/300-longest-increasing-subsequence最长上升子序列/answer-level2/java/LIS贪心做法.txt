### 解题思路
使用贪心的思想维护一个数组，当前数组中元素的个数即为当前的最大长度。
具体：
1 当digit数组中没有元素是直接加入数组
2 当nums[i]大于数组中的最大元素时追加在digit数组上
3 当nums[i]小于数组中的最大元素时使用二分找出第一个比这个元素大的数并替换（注意是替换）
由于求的是最长上升子序列 所以digit数组中不能有重复的元素 所以if(digit[mid]==d) return;
**最后的结果可以保证是最长上升子序列的长度 当digit数组当中的元素不一定合法**
树状数组做法很有意思 各位可以去看看
### 代码

```java
class Solution {
    public int lengthOfLIS(int[] nums) {
        int[] digit=new int[nums.length];
        int cur=0;
        for(int i=0;i<nums.length;i++){
            if(cur==0||nums[i]>digit[cur-1]){
                digit[cur++]=nums[i];
            continue;
            }
            else replaceFirstBigger(digit,cur-1,nums[i]);
        }
        return cur;
    }
    //1 3 7
    private void replaceFirstBigger(int[] digit,int index,int d){
        int l=0,h=index;
        while(l<=h){
            int mid=l+(h-l)/2;
            if(digit[mid]==d) return;
            if(digit[mid]>d) h=mid-1;
            else l=mid+1;
        }
        digit[l]=d;
    }
}
```