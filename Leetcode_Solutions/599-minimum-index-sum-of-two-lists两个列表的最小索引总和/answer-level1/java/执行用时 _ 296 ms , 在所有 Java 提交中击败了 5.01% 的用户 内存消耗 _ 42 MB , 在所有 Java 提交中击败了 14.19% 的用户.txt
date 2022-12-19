### 解题思路
原谅本人实力有限，方法很朴实，首先遍历两个字符串数组，找到最小的索引和，然后再次遍历两个数组，一旦两个数组中的值相等且索引为最小值，那么就把该字符串取出到目标字符串数组中去，当遍历完毕后，本题也得到解决。

### 代码

```java
class Solution {
    public String[] findRestaurant(String[] list1, String[] list2) {
        int min = list1.length+list2.length-2;
        String[] arr = new String[list1.length>list2.length?list2.length:list1.length];
        int count = 0;
        for(int i = 0;i<list1.length;i++) {
            for(int j = 0;j<list2.length;j++) {
                if(list1[i].equals(list2[j])) {
                    if(min>=i+j) {
                        min=i+j;
                    }
                }
            }
        }
         for(int i = 0;i<list1.length;i++) {
            for(int j = 0;j<list2.length;j++) {
                if(list1[i].equals(list2[j]) && i+j==min) {
                    arr[count++] = list1[i];
                }
            }
        }
        String[] brr = new String[count];
        for(int i = 0;i<count;i++) {
            brr[i] = arr[i];
        }
        return brr;
    }
}
```