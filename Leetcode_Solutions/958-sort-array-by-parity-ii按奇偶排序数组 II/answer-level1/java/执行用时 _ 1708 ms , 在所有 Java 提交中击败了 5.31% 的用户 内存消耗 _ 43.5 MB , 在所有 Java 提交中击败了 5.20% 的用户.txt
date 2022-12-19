### 解题思路
菜鸡做法。。。。本题要求在偶数位置插入偶数，奇数位置插入奇数，因此很自然想到先把数组中的数写入集合，因为位置是定的，我们先从0,2,4。。。插入从集合中获取的偶数，取出一个移除一个，偶数取完集合只剩下奇数，随意插入到数组剩下的“坑”即可。

### 代码

```java
class Solution {
    public int[] sortArrayByParityII(int[] A) {
        List<Integer> list = new ArrayList<Integer>();
        for(int i = 0;i<A.length;i++) {
            list.add(A[i]);
        }
        int[] b = new int[A.length];
        for(int i = 0;i<b.length;i+=2) {
            for(int j=0;j<list.size();j++) {
                if(list.get(j)%2==0) {
                    b[i] = list.get(j);
                    list.remove(j);
                    break;
                }
            }
        }
        int count = 0;
        for(int i = 1;i<b.length;i+=2) {
            b[i] = list.get(count++);
        }
        return b;

        
    }
}
```