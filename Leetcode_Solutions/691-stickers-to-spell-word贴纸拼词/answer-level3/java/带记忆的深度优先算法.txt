这个问题跟[Problem638 大礼包](https://leetcode-cn.com/problems/shopping-offers/)有异曲同工之妙。
```
  public int minStickers(String[] stickers, String target) {
    int[] t = new int[26];
    for (int i = 0; i < target.length(); i++) {
      t[target.charAt(i) - 'a'] += 1;
    }
    List<Integer> need = new ArrayList<>();
    List<Character> a = new ArrayList<>();
    for (int i = 0; i < 26; i++) {
      if (t[i] != 0) {
        need.add(t[i]);
        a.add((char) ('a' + i));
      }
    }
    Set<Character> allNeed = new HashSet<>(a);
    Set<Character> has = new HashSet<>();
    List<List<Integer>> stickerList = new ArrayList<>();
    for (String sticker : stickers) {
      Map<Character, Integer> count = new HashMap<>();
      for (int j = 0; j < sticker.length(); j++) {
        Character key = sticker.charAt(j);
        has.add(key);
        int value = count.getOrDefault(key, 0) + 1;
        count.put(key, value);
      }
      List<Integer> pack = new ArrayList<>();
      for (Character c : a) {
        pack.add(count.getOrDefault(c, 0));
      }
      stickerList.add(pack);
    }

    if (allNeed.retainAll(has)) {
      return -1;
    }

    Map<List<Integer>, Integer> memo = new HashMap<>();
    List<Integer> doneKey = new ArrayList<>();
    for (int i = 0; i < need.size(); i++) {
      doneKey.add(0);
    }
    memo.put(doneKey, 0);
    return minStickers(memo, stickerList, need);
  }

  private int minStickers(Map<List<Integer>, Integer> memo, List<List<Integer>> stickerList, List<Integer> need) {
    if (memo.containsKey(need)) {
      return memo.get(need);
    }
    int res = Integer.MAX_VALUE;
    for (List<Integer> sticker : stickerList) {
      if (hasContribute(need, sticker)) {
        List<Integer> restNeed = new ArrayList<>();
        for (int i = 0; i < need.size(); i++) {
          restNeed.add(Math.max(need.get(i) - sticker.get(i), 0));
        }
        int tempRes = minStickers(memo, stickerList, restNeed);
        if (tempRes == -1) {
          continue;
        }
        res = Math.min(res, 1+tempRes);
      }
    }
    if (res == Integer.MAX_VALUE) {
      res = -1;
    }
    memo.put(need, res);
    return res;
  }

  private boolean hasContribute(List<Integer> need, List<Integer> pack) {
    for (int i = 0; i < need.size(); i++) {
      if (need.get(i) != 0 && pack.get(i) != 0) {
        return true;
      }
    }
    return false;
  }
```
