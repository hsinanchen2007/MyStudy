```
public class KthGrammar {
    public int kthGrammar(int n, int k) {
        int kth = k - 1;
        int counter = 0;
        while (kth > 0) {
            counter += (kth % 2);
            kth = kth / 2;
        }
        return counter % 2;
    }
}

```