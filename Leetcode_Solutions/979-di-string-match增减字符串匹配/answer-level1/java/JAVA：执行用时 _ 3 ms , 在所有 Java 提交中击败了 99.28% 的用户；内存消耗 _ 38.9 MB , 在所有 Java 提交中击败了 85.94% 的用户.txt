'D'代表着倒序，'I'代表生序，那么如果为'D'，只要取最大值max，同时最大值减一，作为下一个'D'的最大值；如果为'I'，则正好相反，取最小值min，同时加一，作为下一个'I'的最小值；剩下最后一个值，max=min，取啥都行

```
public int[] diStringMatch(String S) {
        int sLen = S.length();
        int[] arr = new int[sLen + 1];
        int max = sLen;
        int min = 0;
        for(int i = 0 ; i < sLen; i++) {
            if('D' == S.charAt(i)) {
                arr[i] = max--;
            } else {
                arr[i] = min++;
            }
        }
        arr[sLen] = max;
        return arr;
    }
```
