```
public int[] deckRevealedIncreasing(int[] deck) {
        int len = deck.length;
        int n = len;
        for (int i = n / 2; i > 0; i--) {
            skin(deck, i, n);
        }
        int[] res = new int[n];
        while (n > 1) {
            swap(deck, 1, n);
            n--;
            //关键方法，只需要将末尾的数移动到前面就行了，其他方法都是堆排序的方法
            move(deck,n,len-1);
            skin(deck, 1, n);
        }
        return deck;
    }

    private void skin(int[] deck, int k, int n) {
        while (k * 2 <= n) {
            int j = k * 2;
            if (j < n && less(deck, j, j + 1)) {
                j = j + 1;
            }
            if (!less(deck, k, j)) {
                break;
            }
            swap(deck, k, j);
            k = j;
        }
    }

    private void move(int[] deck, int k, int n) {
        int temp = deck[n];
        for (int i = n; i >= k; i--) {
            deck[i] = deck[i-1];
        }
        deck[k] = temp;
    }
    private boolean less(int[] deck, int i, int j) {
        return deck[i - 1] < deck[j - 1];
    }

    private void swap(int[] deck, int i, int j) {
        int temp = deck[i - 1];
        deck[i - 1] = deck[j - 1];
        deck[j - 1] = temp;
    }
```
