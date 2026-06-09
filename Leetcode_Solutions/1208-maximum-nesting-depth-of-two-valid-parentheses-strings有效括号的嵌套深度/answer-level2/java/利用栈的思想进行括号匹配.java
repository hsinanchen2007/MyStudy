### 解题思路


### 代码

```java
class Solution {
    public int[] maxDepthAfterSplit(String seq) {
        int[] res = new int[seq.length()];
        //利用index参数模拟栈顶指针
        int index = 0;
        int j = 0;
        for(char c:seq.toCharArray()){
            //将'('依次分配给A和B
            //压栈时指针先自增，后压栈
            if(c=='('){
                index++;
                res[j++]=index%2;
            }
            //出栈时先出栈，指针后自减
            //将')'依次分配给A和B
            if(c==')'){
                res[j++]=index%2;
                index--;
            }
        }
        return res;
    }
}
```