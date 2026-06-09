基本思路,使用字符与'A'的差值代替hash运算在数组中以O(1)时间搜索当前石头是否为宝石
```
  public int numJewelsInStones(String J, String S) {
        int res = 0;
        int[] arr = new int[58];
        for (char c : J.toCharArray())
            arr[c - 'A'] = 1;
        for (char c : S.toCharArray())
            if (arr[c - 'A'] == 1) res++;
        return res;
    }
```
