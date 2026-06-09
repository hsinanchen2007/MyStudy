![image.png](https://pic.leetcode-cn.com/effb9a0341f1dff85b3fc414c9ed4624d5d42627b5931ed26064ff6b41c64886-image.png)

```
class Solution {
    public String decodeAtIndex(String S, int K) {
        int i, count, lastCount;
        
        count = 0;
        lastCount = 0;
        for(i = 0; i < S.length(); i++){
            if(S.charAt(i) >= '0' && S.charAt(i) <= '9'){
                count *= S.charAt(i) - '0';
                //如果乘了数字以后大于等于K，则返回到上个循环节中找
                if(count >= K)
                    return decodeAtIndex(S, (K - 1) % lastCount + 1); //当整除的时候是找最后一个(lastCount)而不是0
            }else{
                count++;
                lastCount = count;
                if(count == K)
                    return "" + S.charAt(i);
            }
        }
        return null;
    }
}
```
