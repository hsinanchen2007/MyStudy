### 解题思路
如果target可以拆成n位连续数字，那么target-(1+2+3+...+n)=target-n(n+1)/2一定能够整除n，从2位开始递增判断，如果满足上述条件，设整除结果为x,则添加数组[1+x,2+x,3+x,...,n+x],循环到target<n(n+1)/2时结束；

### 代码

```java
class Solution {
    public int[][] findContinuousSequence(int target) {
        List<int[]> res = new ArrayList<>();
        int i=2;
        while(true){
            int base = i*(i+1)/2;
            if(target>=base){
                int w = target-base;
                if(w%i==0){
                    int x = w/i;
                    int[] tmp = new int[i];
                    for(int j=0;j<tmp.length;j++){
                        tmp[j]=x+j+1;
                    }
                    res.add(tmp);
                }
                i++;
            }else{
                break;
            }
        }
        Collections.reverse(res);
        return res.toArray(new int[0][]);
    }
}
```