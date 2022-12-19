### 解题思路
此处撰写解题思路

### 代码

```java
class Solution {
    public int[] sumZero(int n) {
        int[] num=new int[n];
        int x=n;
        if(n%2==0){
            for(int i=0,j=n-1;i<=j;i++,j--){
                num[i]=x;
                num[j]=-x;
                x--;
            }
        }else{
            for(int i=0,j=n-1;i<j;i++,j--){
                num[i]=x;
                num[j]=-x;
                x--;
                if(i+2==j) break;
            }
        }
        return num;
    }
}
```