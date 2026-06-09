class Solution {
    public int[] deckRevealedIncreasing(int[] deck) {
        Arrays.sort(deck);

        int size = deck.length;
        int[] result = new int[size];
        int index = 0;
        int visit[] = new int[size];//标记是否已被访问
        for (int j = 0; j<size; j++) {
            result[index] = deck[j];
            if (j == size -1) {
                break;
            }
            visit[index] = 1;
            index=(index+1)%size;//第一次加1
            while (visit[index]==1) {
                 index=(index+1)%size;
            }
            if (j <= size-2) {
                 index=(index+1)%size;//第二次加1
                 while (visit[index]==1) {
                    index=(index+1)%size;
                }
            }
        }
        return result;

    }
}