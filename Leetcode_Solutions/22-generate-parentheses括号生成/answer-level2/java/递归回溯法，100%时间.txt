### 解题思路
递归回溯法，100%时间

### 代码

```java
class Solution {
    public List<String> generateParenthesis(int n) {
        List<String> res=new ArrayList<>();
        if(n<=0) {
            return res;
        }
        char[] temp=new char[n*2];
        backtrack(temp,0,0,res);
        return res;
    }

    /**
     * 回溯
     * @param temp 存储数组
     * @param i 当前递归字符位置
     * @param leftCount 当前i位置左边'('个数
     * @param res 结果集
     */
    private void backtrack(char[] temp,int i,int leftCount,List<String> res) {
        if(i==temp.length) {
            res.add(new String(temp));
            return;
        }
        // 当前i位置左边'('个数为0，那么i位置必须为'('，不然不符合括号匹配规则
        if(leftCount == 0) {
            temp[i]='(';
            backtrack(temp,i+1,++leftCount,res);
        }
        // 如果i位置左边'('个数小于i右边剩下字符数，那么i位置可以为'('也可以为')',否则从i开始右边只能为')'
        else if(leftCount<(temp.length-i)){
            temp[i]='(';
            backtrack(temp,i+1,leftCount+1,res);
            temp[i]=')';
            backtrack(temp,i+1,leftCount-1,res);
        } else {
            // '('已经满了，右边只能是')'了
            while (i<temp.length) {
                temp[i++]=')';
            }
            res.add(new String(temp));
        }
    }
}
```