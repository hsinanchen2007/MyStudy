### 解题思路
此处撰写解题思路
就是利用等差数列的性质，找到数列的首项，注意数列长度>=2；然后因为n是递增的，因此n越大，首项越小，题目要求首项小的数组排列在前面，因此要对数组中的元素进行反转

### 代码

```java
class Solution {
    public int[][] findContinuousSequence(int target) {
        List<int[]> list = new ArrayList<>();
        int count = 0;
        for(int n=2;;n++){
            int temp = target-(n-1)*n/2;
            if(temp<0)
                break;
            if(temp==0 || temp%n!=0)
                continue;
            int index = temp/n;
            int[] table = new int[n];
            for(int i=0;i<n;i++){
                table[i] = index + i;
            }
            list.add(table);
            count++;
        }
        Collections.reverse(list);
        int capicity = list.size();
        int[][] result = new int[capicity][];
        for(int i = 0;i<capicity;i++){
            result[i] = list.get(i);
        }
        return result;
    }
}
```