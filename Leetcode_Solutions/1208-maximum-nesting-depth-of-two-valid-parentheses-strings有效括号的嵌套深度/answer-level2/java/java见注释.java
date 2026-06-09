### 解题思路
此处撰写解题思路

### 代码

```java
public class Solution {
    //要让A和B的最大深度最小，关键就是，AB你俩的深度谁都别涨太快
    //涨深度的时候，谁比较浅，谁涨。降的时候，谁比较深，谁降。
    public int[] maxDepthAfterSplit(String seq) {
        //结果数组
        int[] ans = new int [seq.length()];
        //A,B深度初始0
        int a = 0,b = 0;
        
        char[] c = seq.toCharArray();
        for(int i = 0;i < c.length; i++) {
            //左括号涨深度
            if(c[i] == '('){
                if(a <= b){
                    a += 1;
                    ans[i] = 0;
                }else{
                    b += 1;
                    ans[i] = 1;
                }
            //右括号降深度
            }else if(c[i] == ')'){
                if(a > b){
                    a -= 1;
                    ans[i] = 0;
                }else{
                    b -= 1;
                    ans[i] = 1;
                }
            }
        }
        return ans;
    }
}
```