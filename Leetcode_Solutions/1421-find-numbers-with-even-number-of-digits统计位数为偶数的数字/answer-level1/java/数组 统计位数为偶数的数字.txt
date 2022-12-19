### 解题思路
此处撰写解题思路

### 代码

```java
class Solution {
    public int findNumbers(int[] nums) {
int num=0;
for(int a:nums){
if((String.valueOf(a).length()%2)==0){

    num++;
}
}
return num;
    }
}
```