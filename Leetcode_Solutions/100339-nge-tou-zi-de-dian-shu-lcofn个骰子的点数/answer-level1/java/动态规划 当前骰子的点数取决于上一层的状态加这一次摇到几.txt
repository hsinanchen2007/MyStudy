### 解题思路
此处撰写解题思路

### 代码

```java
class Solution {
    public double[] twoSum(int n) {
        double[][] arr=new double[n+1][6*n+1];
        for(int i=1;i<=6;i++)
            arr[1][i]=1.0/6.0;
        for(int i=2;i<=n;i++){
            for(int j=i;j<=6*i;j++){
                for(int k=1;k<=6;k++){
                    if((j-k)>0)
                        arr[i][j]+=1.0/6.0* arr[i-1][j-k];
                    else
                        break;
                }
            }
        }

        double[] f=new double[5*n+1];
        int idx=0;
        for(int i=n;i<=6*n;i++)
            f[idx++]=arr[n][i];
        return f;
    }
}
```