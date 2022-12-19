### 解题思路
此处撰写解题思路

### 代码

```java
class Solution {
    public int[][] findContinuousSequence(int target) {
        ArrayList<int[]> list = new ArrayList<>();

        for(int i = 1; i <= target/2; i++) {
            int j = i + 1;
            int sum = i;
            while(sum <= target) {
                if(sum == target) {
                    int[] array = new int[j - i];
                    for(int k = 0; k< j-i; k++) {
                        array[k] = i + k;
                    }
                    list.add(array);
                    break;
                } else {
                    sum += j;
                    j++;
                }
            }
        }
        
        return list.toArray(new int[list.size()][]);
    }
}
```