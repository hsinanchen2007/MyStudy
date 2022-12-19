### 解题思路
此处撰写解题思路

### 代码

```java
class Solution {
    public String frequencySort(String s) {
        if (null == s || 0 == s.length())
            return s;

        StringBuilder sb = new StringBuilder(s.length());


        int[] arr = new int[256];

        for (char c: s.toCharArray()) {
            ++arr[c];
        }

        int cnt = 0;
        int maxIndex = 0;
        while (true) {
            if (cnt == s.length())
                break;
            maxIndex = 0;
            for (int i=0; i<arr.length; ++i) {
                if (arr[maxIndex] < arr[i])
                    maxIndex = i;
            }

            for (int i=0; i<arr[maxIndex]; ++i)
                sb.append((char)maxIndex);
            cnt += arr[maxIndex];
            arr[maxIndex] = 0;

        }
        return sb.toString();
    }
}
```