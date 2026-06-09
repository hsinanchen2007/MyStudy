### 解题思路
此处撰写解题思路
1 、先找最短字符串长度
2、 双循环遍历，利用set
### 代码

```java
class Solution {
    public String longestCommonPrefix(String[] strs) {
        StringBuilder res = new StringBuilder();
        int minSize = Integer.MAX_VALUE;
        for(int i= 0; i < strs.length;i++){
           minSize = strs[i].length() < minSize ?strs[i].length():minSize;
        }
        Set<Character> temp = new HashSet<Character>();
        for(int j=0; j<minSize;j++){
            char un = 0;
            for(int k =0; k < strs.length;k++){
                un = strs[k].charAt(j);
                temp.add(un);
            }
            if(temp.size() == 1){
                res.append(String.valueOf(un));
                temp.clear();
            }else{
                return res.toString();
            }
        }
        return res.toString();
    }
}
```