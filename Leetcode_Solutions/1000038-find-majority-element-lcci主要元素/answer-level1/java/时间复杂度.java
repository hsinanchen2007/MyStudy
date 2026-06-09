### 解题思路
此处撰写解题思路
我的思想:
    用的是希尔排序，排序的效率很快，所以不会出现什么时间超限之类的话题。排序好了以后再用了选择排序的算法进行比较。
如果相同就进行统计，统计完了之后再进行比大小，最后将这个下标的值返回就行 !;
### 代码

```java
class Solution {
    public int majorityElement(int[] nums) {
        int len=0;
        int max=-100000000;
        int index=0;
        if(nums.length==1){
            return nums[0];
        }
  for(int g=nums.length/2;g>=1;g/=2){
      for(int i=g;i<nums.length;i++){
          int j=i;
          int temp=nums[j];
          while(j-g>=0 && temp<nums[j-g] ){
              nums[j]=nums[j-g];
              j-=g;
          }
          nums[j]=temp;
      }
  }
  int a=0;

    for(int i=0;i<nums.length;i++){
        for(int j=i+1;j<nums.length;j++){
            if(nums[i]==nums[j]){
                len++;
                a=nums[i];
            }
        }
        if(len>max){
            max=len;
            index=a;
        }
        len=0;
    }
    return index;
    }
}
```