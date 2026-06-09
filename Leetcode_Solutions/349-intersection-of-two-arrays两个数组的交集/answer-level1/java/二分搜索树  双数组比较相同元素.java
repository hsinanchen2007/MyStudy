### 解题思路
此处撰写解题思路
首先声明一个树结构，将数组一的值放入树结构中。
之后遍历数组2，将相同元素放入新的链表中。
同时删去1数组中的这个元素（防止二次计算）
将最后的链表转化为数组输出
### 代码

```java
import java.util.ArrayList;
import java.util.TreeSet;

class Solution {
        public int[] intersection(int[] nums1, int[] nums2) {
            TreeSet<Integer>set=new TreeSet<>();
            for (int num:nums1){
                set.add(num);
            }
            ArrayList<Integer> list=new ArrayList<>();
            for (int num:nums2){
                if (set.contains(num)){
                    list.add(num);
                    set.remove(num);
                }
            }
            int[] result=new int[list.size()];
            for (int i = 0; i <list.size() ; i++) {
                result[i]=list.get(i);
            }
            return result;
    }
}

```