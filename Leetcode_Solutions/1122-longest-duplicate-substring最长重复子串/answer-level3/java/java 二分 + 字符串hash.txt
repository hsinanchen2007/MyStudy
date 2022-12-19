**思路**
1. 首先，我们需要明白的是，假设存在一个长度为L的重复子串，那么必定存在长度为L0（L0 < L）的重复子串，如字符串"banana"中存在长度为3的重复子串“ana”，那么"ana"的子串"an"也一定是重复子串。这就可以使我们可以使用二分去猜可能的最大长度。
2. 假设每次二分猜的长度为subLen，那么我们可以使用滑动窗口（长度即为subLen），从左往右滑动，判断是否存在重复子串。其中由于字符串长度较长，因此我么需要引入字符串hash（即将字符串用一个整型值来表示）来提高字符串判断的效率。但是，有可能存在hash冲突，因此我们需要解决冲突。具体解决冲突的方法就是引入了一个map。map的key是hash值，value是一个list，用于存放相同hash值的子串的不同左边界坐标。具体实现如以下代码：

```java
private static final long P = 805306457;
    private static final long MOD = (int) (1e9+7);
    private long[] hash;
    private long[] power;
    private int[] ansPos;

    private void calcHashAndPower(char[] arr) {
        hash[0] = arr[0];
        power[0] = 1;
        for (int i = 1; i < arr.length; i++) {
            hash[i] = (hash[i-1] * P + arr[i]) % MOD;
            power[i] = (power[i-1] * P) % MOD;
        }
    }

    private long getSubStrHash(int l, int r) {
        if (l == 0) {
            return hash[r];
        }
        return ((hash[r] - power[r-l+1] * hash[l-1]) % MOD + MOD) % MOD;
    }

    private boolean hasTrueExist(char[] arr, int l1, int l2, int subLen) {
        for (int i = 0; i < subLen; i++) {
            if (arr[l1 + i] != arr[l2 + i]) {
                return false;
            }
        }

        return true;
    }

    /**
     * 判断是否存在指定长度的重复子串
     * 由于不同子串可能存在相同的hash值，因此需要解决hash冲突
     */
    private boolean hasDuplicatedStr(char[] arr, int subLen) {
        Map<Long, List<Integer>> map = new HashMap<>();
        for (int l = 0; l <= arr.length - subLen; l++) {
            long strHash = getSubStrHash(l, l + subLen - 1);
            if (map.containsKey(strHash)) {
                List<Integer> oldPosList = map.get(strHash);
                for (Integer oldPos : oldPosList) {
                    if (hasTrueExist(arr, oldPos, l, subLen)) {
                        ansPos[0] = l;
                        ansPos[1] = l + subLen;
                        return true;
                    }
                }

                oldPosList.add(l);
            } else {
                List<Integer> posList = new ArrayList<>();
                posList.add(l);
                map.put(strHash, posList);
            }
        }

        return false;
    }

    public String longestDupSubstring(String str) {
        char[] arr = str.toCharArray();
        int len = arr.length;
        hash = new long[len];
        power = new long[len];
        ansPos = new int[2];

        calcHashAndPower(arr);

        // 二分+滑动窗口
        // 其中二分确定长度，因为当一个长串出现重复串，那么它的子串必定出现重复串。因此可以用二分去猜最大长度
        int low = 1;
        int high = len;
        while (low <= high) {
            int mid = (low + high) >>> 1;
            boolean hasDuplicated = hasDuplicatedStr(arr, mid);
            if (hasDuplicated) {
                low = mid + 1;
            } else {
                high = mid - 1;
            }
        }

        if (ansPos[0] == ansPos[1]) {
            return "";
        }
        
        return str.substring(ansPos[0], ansPos[1]);
    }
```