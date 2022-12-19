```
//直接通过上面大佬说的（出入度和）或者是说树的叶子节点的个数比内部节点的个数大1 的简单优化
//直接遍历字符串，不用split函数，需要注意的一点就是数字的位数大于1的时候所占的字节需要用while特殊处理
class Solution {
    public boolean isValidSerialization(String preorder) {
        int len = preorder.length();
        int count = 1;
        for(int i =0;i<len;i++) {
            if (count == 0) {
                return false;
            } else {
                if(preorder.charAt(i)==',') {
                    continue;
                }
                if (preorder.charAt(i)=='#') {
                    count--;
                } else {//是数字的时候直接循环跳到逗号所在处
                    while(i<len &&preorder.charAt(i)!=','){
                        i++;
                    }
                    count++;
                }
            }
        }
        return count == 0;
    }
}
```
