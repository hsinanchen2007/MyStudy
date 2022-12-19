### 解题思路
遍历所有格子，符合条件的计数1，不符合的计数0

### 代码

```java
class Solution {
    public int movingCount(int m, int n, int k) {
        int result = 0;
        Map<String,String> map = new HashMap<String,String>();

        for(int i = 0 ;i < m ;i++)
        {
            for(int j = 0 ;j < n ;j++)
            {
                String flag2 = map.get((i-1)+""+j);
                String flag3 = map.get(i+""+(j-1));

                if(sums(i,j) <= k && (("1".equals(flag2)  || "1".equals(flag3)) || (i==0 && j ==0 ) ))
                {
                    map.put(i+""+j,"1");
                    result++;
                }
                else
                {
                    map.put(i+""+j,"0"); 
                }
            }
        }
        return result;
    }

    public int sums(int x,int y){
    int ans=0;
    while (x != 0) {
        ans+=x%10;
        x/=10;
    }
    while (y != 0) {
        ans+=y%10;
        y/=10;
    }
    return ans;
    }

}
```