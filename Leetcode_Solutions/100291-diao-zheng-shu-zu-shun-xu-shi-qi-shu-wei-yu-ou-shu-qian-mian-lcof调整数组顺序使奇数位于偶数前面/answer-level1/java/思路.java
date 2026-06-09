### 解题思路
此处撰写解题思路
我的思路:
    统计原始数组中奇数和偶数的个数，然后再创建一个偶数和奇数的个数的数组
    再然后遍历原始数组判断是否为奇数，如果为奇数就用j赋初值为0，将奇数放入到
    新的数组前，并且j递增，如果是偶数，那么就直接从最后一个递减的方式放入到数组中
最后返回新的数组ok；
### 代码

```java
class Solution {
    public int[] exchange(int[] nums) {
            int j=0;
            int ou=0;
            for(int i=0;i<nums.length;i++){
                if(nums[i]%2==0){
                    ou++;
                }else{
                    j++;
                }
            }
            int k=0;int p=0;
            int arr[]=new int[ou+j];
            for(int i=0;i<nums.length;i++){
                if(nums[i]%2!=0){
                    arr[k]=nums[i];
                    k++;
                }else{
                    arr[arr.length-p-1]=nums[i];
                    p++;
                }
            }
            return arr;
    }
}
```