### 解题思路
此处撰写解题思路
最开始打算使用动态规划，从1个是（），2个是（）+1和（1）第n个是（）+n-1和 （n-1）
但是发现不对，缺少对（n-i-1）i这种方式的考虑
所以将递归，改为（a）b类型，再将最后结果去重
之后发现，这样子的结果，没有重复的，所以就使用这样，来对其做深搜

### 代码

```java
class Solution {
    public List<String> generateParenthesis(int n) {
        
    
        
        return new ArrayList(getStringList(n));
    }
    public Set<String> getStringList(int n){
        Set<String> res = new HashSet();
        if(n==0){
            res.add("");
            return res;
        }
            if(n==1){
                res.add("()");
                return res;
            }
            Set<String> leftList = new HashSet();
            Set<String> rightList = new HashSet();
            for(int i=0;i<n;i++){
                leftList = getStringList(i);
                rightList = getStringList(n-1-i);
                for(String left:leftList){
                    for(String right:rightList){
                        res.add("("+left+")"+right);
                    }
                }
            }
            return res;
        }
    

}
```