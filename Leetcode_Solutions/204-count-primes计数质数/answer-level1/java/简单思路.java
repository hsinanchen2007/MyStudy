### 解题思路
此处撰写解题思路
在每次找到一个素数时，将这个素数的倍数排除掉。
简单吧。哈哈哈。
### 代码

```java
class Solution {
    public int countPrimes(int n) {
        boolean[]a=new boolean[n];
        int ret=0;
        for(int i=2;i<n;i++){
            if(a[i])
                continue;
            ret++;
            for(int j=i;j<n;j+=i){
                a[j]=true;
            }
        }
        return ret;
    }
}
```