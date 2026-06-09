
先转换成char数组排序, 再双指针
不过Java里面的`toCharArray()`方法创建了新数组, 所以应该算使用了额外的数据结构
```
 class Solution {
    public boolean isUnique(String astr) {
        char[] c =  astr.toCharArray();
        Arrays.sort(c);
        for(int i = 0, j = 1; i < c.length - 1; i++, j++) {
            if(c[i] == c[j]) {
                return false;
            }
        }
        return true;
    }
}
```
