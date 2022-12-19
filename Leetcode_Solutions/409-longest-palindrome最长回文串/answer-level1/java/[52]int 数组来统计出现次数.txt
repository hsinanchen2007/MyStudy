好像跟之前有道题类似的思路，用字符集数组来统计使用次数：

因为只有大小写，共 52 个字母，所以数组长度 52 即可：当然因为小写字母和大写字母的 ASCII 码并不连续，所以对小写字母需要修正：

``` java
    public int longestPalindrome(String s) {
        int[] log = new int[52];
        for (int i = 0; i < s.length(); i++) {
            int in = s.charAt(i);
            if (in >= 'a') {
                //对小写字母的修正
                in = in - 'A' - 6;
            } else {
                in = in - 'A';
            }
            log[in]++;
        }
        int count = 0;
        for (int i = 0; i < log.length; i++) {
            //统计所有使用了偶数次的字母数量，包括 3 次中的 2 次这种
            if (log[i] != 0 && log[i] % 2 == 0) count += log[i];
            else if (log[i] > 2) count += log[i] - 1;
        }

        //以上求和一定是偶数，如果没有全部用过还可以加一个中心字母
        return count != s.length() ? count + 1 : count;
    }

```