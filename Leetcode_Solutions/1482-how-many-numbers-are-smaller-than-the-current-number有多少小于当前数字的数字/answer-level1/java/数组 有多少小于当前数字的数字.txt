### 解题思路
此处撰写解题思路.

### 代码

```java
class Solution {
    public int[] smallerNumbersThanCurrent(int[] nums) {
int[] lownum=new int[nums.length];
int i=0,j=0;
for(int a:nums){
    for(int b:nums){
        if(a>b){
            i++;
        }
    }
    lownum[j]=i;
    j++;
    i=0;
}
return lownum;
    }
}
```