### 解题思路
先排序，通过比较大小，确定需要替换的B数组索引的值，最后返回B 。

### 代码

```java
class Solution {
   public int[] advantageCount(int[] A, int[] B) {
        Arrays.sort(A);
        List<NUM> list = new ArrayList<>();
        for (int i = 0; i < B.length; i++) {
            list.add(new NUM(i, B[i]));
        }
        Collections.sort(list);
        int a = 0, aLen = A.length - 1, b = 0, bLen = B.length - 1;
        while (a < A.length) {
            if (A[a] > list.get(b).num) {
                B[list.get(b).index] = A[a];
                a++;
                b++;
            }
            else if(A[a] <= list.get(b).num){
                B[list.get(bLen).index]= A[a];
                bLen--;
                a++;
            }
        }
        
        return B;

    }

}

class NUM implements Comparable<NUM> {
    public int index;
    public int num;

    public NUM(int index, int num) {
        this.index = index;
        this.num = num;
    }

    @Override
    public int compareTo(NUM o) {
        return this.num - o.num;
    }
}
```