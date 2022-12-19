### 解题思路
此处撰写解题思路

### 代码

```java
class Solution {
    public int minArray(int[] numbers) {
int count=Integer.MAX_VALUE;
for(int i=0;i<numbers.length-1;i++){
    if(numbers[i]>numbers[i+1]){
    count=numbers[i+1];
    break;
    }
}
return numbers[0]>count?count:numbers[0];
    }
}
```