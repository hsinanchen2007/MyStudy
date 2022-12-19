### 解题思路
透过现象看本质：其实就是两个list求和
注意不要转成int，因为数组可能很长很长。
1、都转成list
2、翻转list
3、分三种情况：两个长度相同、A长度大、B长度大
4、注意边界情况即可

### 代码

```java
class Solution {
    public List<Integer> addToArrayForm(int[] A, int K) {
        String kString = String.valueOf(K);
        List<Integer> listB = new ArrayList<>();
        List<Integer> listA = new ArrayList<>();
        for (int i = 0; i < kString.length(); i++) {
            listB.add(Integer.parseInt(String.valueOf(kString.charAt(i))));
        }

        for (int value : A) {
            listA.add(value);
        }
        Collections.reverse(listA);
        Collections.reverse(listB);

        int lengthA = listA.size();
        int lengthB = listB.size();
        List<Integer> result = new ArrayList<>();
        if (lengthA == lengthB) {
            int jinwei = 0;
            for (int i = 0; i < lengthA; i++) {
                int value = listA.get(i) + listB.get(i) + jinwei;
                if (value >= 10) {
                    jinwei = 1;
                    result.add(value - 10);
                } else {
                    jinwei = 0;
                    result.add(value);
                }
            }
           if (jinwei == 1) {
                result.add(1);
            }
        } else if (lengthA < lengthB) {
            int jinwei = 0;
            for (int i = 0; i < lengthA; i++) {
                int value = listA.get(i) + listB.get(i) + jinwei;
                if (value >= 10) {
                    jinwei = 1;
                    result.add(value - 10);
                } else {
                    jinwei = 0;
                    result.add(value);
                }
            }
            for (int i = lengthA; i < lengthB; i++) {
                int value = listB.get(i) + jinwei;
                if (value >= 10) {
                    jinwei = 1;
                    result.add(value - 10);
                } else {
                    jinwei = 0;
                    result.add(value);
                }
            }
            if (jinwei == 1) {
                result.add(1);
            }
        } else {
            int jinwei = 0;
            for (int i = 0; i < lengthB; i++) {
                int value = listA.get(i) + listB.get(i) + jinwei;
                if (value >= 10) {
                    jinwei = 1;
                    result.add(value - 10);
                } else {
                    jinwei = 0;
                    result.add(value);
                }
            }
            for (int i = lengthB; i < lengthA; i++) {
                int value = listA.get(i) + jinwei;
                if (value >= 10) {
                    jinwei = 1;
                    result.add(value - 10);
                } else {
                    jinwei = 0;
                    result.add(value);
                }
            }
            if (jinwei == 1) {
                result.add(1);
            }
        }
        Collections.reverse(result);
        return result;
    }
}
```