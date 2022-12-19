### 解题思路
![u.PNG](https://pic.leetcode-cn.com/d35c468ae7de15bd882da8506784f86240e6166b1f8f340493581cda1cfdb1d8-u.PNG)
看代码注释

### 代码

```java
class Solution {
    public int majorityElement(int[] nums) {
         int result=-1; //结果先定为-1，下面的代码满足题目条件才会有改变

         for (int i = 0; i < nums.length; i++) {//取需计算个数的元素
            if (nums[i]==-1){continue;}     //不取值为-1的元素，可节省时间

            int s=1;
            for (int j = i+1; j <nums.length ; j++) {//取除值为-1外所有的元素进行比较
                if (nums[j]==-1){continue;}
                if (nums[i]==nums[j]){//若相等，则s加加，并把值变成-1，因为可节省时间
                    s++;
                    nums[j]=-1;
                }
                if (s>nums.length/2){
                    result=nums[i];
                    break;
                }

            }

        }
  if (nums.length==1)result=nums[0];
return result;
    }
}
```