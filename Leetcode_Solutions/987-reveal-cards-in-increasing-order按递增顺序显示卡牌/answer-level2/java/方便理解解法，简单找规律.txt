```
class Solution {
    public int[] deckRevealedIncreasing(int[] deck) {
        // a b c d e f
        // a < b > c < e > f && a < c < f
        // java arraylist
        // 只能模拟这个过程了
        // 把排好序的数组逆着步骤摆出来
        // 找规律
        // 逆流程找，当当前数组数量是奇数的时候，是偶数的时候
        // 不是奇偶的规律，是3以下是一种规律（混乱的），3以上是整齐的规律
        Arrays.sort(deck);
        if(deck.length <= 2)
            return deck;
        List<Integer> al = new LinkedList<>();
        for(int i = deck.length - 1; i >= 0; -- i) {
            if(al.size() == 0)
                al.add(deck[i]);
            else {
                if(al.size() == 1) {
                    // from odd to even
                    al.add(deck[i]);
                }
                else if(al.size() == 2) {
                    al.add(0, deck[i]);
                }
                else {
                    // from even to odd
                    int tmp = al.remove(al.size() - 1);
                    al.add(0, tmp);
                    al.add(0, deck[i]);
                }
            }

            //System.out.println("current i is " + i + ", al is " + Arrays.toString(al.toArray()));
        }

        int[] res = new int[al.size()];
        for(int i = 0; i < al.size(); ++ i)
            res[i] = al.get(i);
        return res;
    }
}
```
