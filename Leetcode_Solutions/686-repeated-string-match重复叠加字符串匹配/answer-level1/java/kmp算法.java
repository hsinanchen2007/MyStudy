因为最多需要 len(a)/len(b) + 2个字符串a（记为A）即可拼出b，之后通过kmp算法判断A中是否有b，最后通过匹配的起始下标判断具体需要几个字符串a

```java
public class P686_RepeatedStringMatch {
    public static int repeatedStringMatch(String a, String b) {
        int la = a.length(), lb = b.length();
        // 最多需要cnt个字符串a即可拼出b，否则一定拼不出b
        int cnt = lb / la + 2;
        char[] arr1 = a.repeat(cnt).toCharArray();
        char[] arr2 = b.toCharArray();
        int index = kmp(arr1, arr2);
        if (index == -1)
            return -1;
        // 正好lb/la个字符串a等于字符串b
        else if (la * cnt - index - lb == la * 2)
            return cnt - 2;
        else if (la * cnt - index - lb >= la)
            return cnt - 1;
        else
            return cnt;
    }

    // 经典kmp算法，返回初次匹配时在arr中的起始下标
    private static int kmp(char[] arr, char[] target){
        int[] next = getNextArray(target);
        int i = 0, j = 0;
        while (i < arr.length && j < target.length){
            if (arr[i] == target[j]){
                i++;
                j++;
            }
            else if (next[j] != -1)
                j = next[j];
            else
                i++;
        }
        if (j == target.length)
            return i - j;
        return -1;
    }

    private static int[] getNextArray(char[] arr){
        int[] next = new int[arr.length + 1];
        next[0] = -1;
        next[1] = 0;
        int c = 0, index = 1;
        while (index < arr.length){
            if (c == -1) {
                next[++index] = 0;
                c = 0;
            }
            else if (arr[c] == arr[index])
                next[++index] = ++c;
            else
                c = next[c];
        }
        return next;
    }

    public static void main(String[] args) {
        String a = "abc";
        String b = "cabcabca";
        System.out.println(repeatedStringMatch(a, b));
    }
}
```
