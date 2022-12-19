### 解题思路

- 一开始想的是转换成数字进行计算，然后再转回List，但发现自己在类型转换上还是需要查很多，仍有许多要加强

- 以下方式是用数组最后的一个数字A[len - 1]和整个K计算，计算完后将个位数留在对应的index位置，然后数组index--，之后重复这个步骤。

- 需要注意的是，答案数组超出A长度的情况，也就是相加之后的数组比原数组要长。也就是i < 0 && lastNum > 0 的情况。

LinkedList是链表，addFirst从首部开始添加元素。

*LinkedList是一个双向链表, 当数据量很大或者操作很频繁的情况下，添加和删除元素时具有比ArrayList更好的性能。但在元素的查询和修改方面要弱于ArrayList。LinkedList类每个结点用内部类Node表示，LinkedList通过first和last引用分别指向链表的第一个和最后一个元素，当链表为空时，first和last都为NULL值。*

### 代码

```java
class Solution {
    public List<Integer> addToArrayForm(int[] A, int K){
        int len = A.length;
        int lastNum = K;
        LinkedList<Integer> ans = new LinkedList<>();

        int i = len - 1;
        while(i >= 0 || lastNum > 0){
            if(i >= 0){
                lastNum += A[i];
            }
            
            ans.addFirst(lastNum % 10);
            lastNum /= 10;
            i--;
        }
        return ans;
    }
}
```