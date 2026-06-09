### 解题思路
把前面解了一部分的解传给下一层函数，就像树一样不断展开，最后设定一个条件返回，这里的条件就是遍历到了digits的最后。

### 代码

```java
class Solution {
    private String[] voc=new String[]{"abc","def","ghi","jkl","mno","pqrs","tuv","wxyz"};
    public List<String> letterCombinations(String digits) {
        List<String> res=new ArrayList();
        if(digits==null||digits.length()==0)return res;
        lc(digits,0,"",res);
        return res;
    }
    public void lc(String digits,int index,String s,List<String> res){
        if(index==digits.length()){
            res.add(s.toString());
            return;
        }
        int i=digits.charAt(index)-'0';
        for(char c:voc[i-2].toCharArray()){
            lc(digits,index+1,s+c,res);
        }

    }
}
```