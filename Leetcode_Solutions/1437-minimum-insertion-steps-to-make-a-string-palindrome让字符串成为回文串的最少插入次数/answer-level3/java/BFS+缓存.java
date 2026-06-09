1.从字符串两端(l,r)开始比对，不相同则插入一个字符使其相同，可能从左侧也可能从右侧(不用真实插入，索引变化就行)。
2.第1步完成后，假如l位置插入了一个和r位置相同的支付，则l不变，r-1，此时l,r外侧的字符串是回文的;反之r不变,l+1。
3.重复1、2步，直到l>=r，说明字符串已经处理完了;此时找到了回文串就是插入次数最小的。
4.插入次数每加1，队列长度都翻倍，指数爆炸。需要缓存处理过的状态，l、r<=500，用二维布尔数组存储即可。

```
public int minInsertions(String s) {
        boolean[][] passed = new boolean[s.length()][s.length()];
        Queue<int[]> queue = new LinkedList<>();
        // leftIndex,rightIndex,0  ; leftIndex和rightIndex以外的字符串是回文串
        queue.offer(new int[]{0, s.length() - 1, 0});
        int[] state;
        while ((state = queue.poll()) != null) {
            // log.info(Arrays.toString(state));
            int l = state[0], r = state[1], changeNum = state[2];
            if (passed[l][r]) continue;
            passed[l][r] = true;
            if (l >= r) return changeNum;
            while (l < r && s.charAt(l) == s.charAt(r)) {
                l++;
                r--;
            }
            if (l >= r) return changeNum;
            queue.offer(new int[]{l + 1, r, changeNum + 1});
            queue.offer(new int[]{l, r - 1, changeNum + 1});
        }
        return -1;
    }
```
