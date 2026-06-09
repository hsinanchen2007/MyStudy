### 解题思路
此处撰写解题思路

### 代码

```java
class Solution {
    public int smallestRepunitDivByK(int K) {
        if(K%2==0||K%5==0)
        return -1;
        int i=1;
        for(int num=1;num%K!=0;i++){
            num=(num*10+1)%K;
            //num%=K;
        }
        return i;
    }
}
```