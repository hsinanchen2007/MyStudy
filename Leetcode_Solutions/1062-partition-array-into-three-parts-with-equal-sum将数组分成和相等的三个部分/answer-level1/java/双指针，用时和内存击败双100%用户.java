### 解题思路
1.思路很简单，要是三块相等的话，每一块等于总和的1/3即可。我们分为左，中，右。
2.创建两个指针，左右各一个，向中间遍历。先判断左右两边，任何一边等于1/3便跳出，然后只需判断剩下的另一边是否也可以等于1/3即可。
3.整个判断的过程需要注意的一点是，中间的那块不能为空，即 left < right-1 或者 left+1 > right。 
4.遍历完了如果还不成立即返回false。


### 代码

```java
class Solution {
    public boolean canThreePartsEqualSum(int[] A) {
        int sum = 0;
        for(int element: A) sum+=element;
        int one_third = sum/3;
        
        int left=0, right=A.length-1;
        int sum_left = 0, sum_right = 0;
        while(left<right-1){ //中间不为空
            sum_left+=A[left];
            sum_right+=A[right];
            if(sum_right == one_third || sum_left == one_third) break;
            left++;
            right--;}
        
        //开始判断另一边
        if(sum_right == one_third && sum_left == one_third) return true;
        
        //右边还不满足
        else if(sum_left == one_third){
            while(right > left + 1){ //中间不为空
                right--;
                sum_right+=A[right];
                if(sum_right == one_third && right > left + 1) return true; } }
        //左边还不满足
        else if(sum_right == one_third){
            while(right > left + 1){ //中间不为空
                left++;
                sum_left+=A[left];
                if(sum_left == one_third && right > left + 1) return true; } }
        
        return false;
        
    }
}
```