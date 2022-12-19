### 解题思路
i从0开始，j从数组末尾开始；
1.i为奇数，则i继续后移；
2.i为偶数，则j从末尾向前移动，找到奇数，则进行互换
3.当i和j相遇，则循环结束
### 代码

```java
class Solution {
    public int[] exchange(int[] nums) {
        if(nums==null){
            return nums;
        }
        int i=0;
        int j=nums.length-1;
        while(j>i){
            if((nums[i]&1)==0){
                if((nums[j]&1)==1){
                    //nums[i]为偶数，nums[j]为奇数，则互换数据
                    int tmp=nums[i];
                    nums[i]=nums[j];
                    nums[j]=tmp;
                    i++; 
                }
                //nums[j]不是奇数，则j继续向前移动
                j--;
            }else{
                //nums[i]为奇数，则i继续向后移动
                i++;
            }
        }
        return nums;
    }
}
```