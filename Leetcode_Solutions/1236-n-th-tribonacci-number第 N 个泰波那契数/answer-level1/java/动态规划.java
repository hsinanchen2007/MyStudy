### 解题思路
用一个数据记录每次计算结果，用空间换时间

### 代码

```java
class Solution {
    public int tribonacci(int n) {
        int[] temp;
        if(n<=3){
            temp = new int[10];
        }else{
            temp = new int[n+1];
        }
        
        temp[0]=0;
        temp[1]=1;
        temp[2]=1;
        for(int i=3; i<=n;i++){
            temp[i]=temp[i-1]+temp[i-2]+temp[i-3];
        }
        return temp[n];
    }
}
```