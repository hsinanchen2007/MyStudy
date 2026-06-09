### 解题思路
此处撰写解题思路

### 代码

```java
class Solution {
    public boolean isUnique(String astr) {
        char[] c=astr.toCharArray();
        for(int i=0;i<c.length-1;i++){
            for(int j=i+1;j<c.length;j++){
                if(c[i]==c[j]){
                    return false;
                }
            }
        }
        return true;
    }
}
```按照选择排序的思路来进行比较，将字符串通过toCharArray()方法进行拆分，将最前面的元素和后面的各个元素进行比较，如果发现相同，就返回false,然后每一次叫就将索引号向后进行移位，直至比较到倒数第二个为止。减一是因为最后一个元素不需要比较了，再往后就会出现下标越界。