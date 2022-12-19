### 解题思路
要求max(A,B)的深度最小，最直接的办法就是将所有的嵌套深度平分，A和B各一半，平分的办法也有多种，比如：A要前面一半，B要后面一半，或者A要奇数位，B要偶数位等等，如果用第一种方法，需要计算前一半的起点和终点，然后还要避免重复计算的情况，所以要稍微麻烦一些，本题采用第二种奇偶数的方法来分配，如果来一个'('，深度就加1，来一个')'，深度就减1（但需要在处理后再减，因为默认')'的深度和与之对应'('深度一致）

### 代码

```java
class Solution {
    public int[] maxDepthAfterSplit(String seq) {
        if(seq == null || seq.length() <= 0){
            return new int[0];
        }
        char[] chars = seq.toCharArray();
        int[] r = new int[chars.length];
      
        int num = 0;
        for(int i=0; i<chars.length; i++){
            if(chars[i] == '('){
                num++;
            }
            //奇数设为A或者B都行
            if((num & 1) == 0){
                    r[i] = 1;
            //偶数就为另一个
                }else{
                    r[i] = 0;
                }
            if(chars[i] == ')'){
                num--;
            }

        }
        return r;
    }
}
```