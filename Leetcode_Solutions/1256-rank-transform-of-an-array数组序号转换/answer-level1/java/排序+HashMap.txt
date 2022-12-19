### 解题思路
要注意重复数字的编号

### 代码

```java
class Solution {
    public int[] arrayRankTransform(int[] arr) {
        int[] temp = new int[arr.length];
        for (int i = 0; i < arr.length; i++) {
            temp[i] = arr[i];
        }
        Arrays.sort(temp);
        Map<Integer, Integer> m = new HashMap<>();
        int count = 1;
        for (int i = 0; i < temp.length; i++) {
            while (i < temp.length - 1 && temp[i] == temp[i + 1]) {
                i++;
            }
            m.put(temp[i], count);
            count++;
        }
        for (int i = 0; i < arr.length; i++) {
            arr[i] = m.get(arr[i]); 
        }
        return arr;
    }
}
```