```
class Solution {
    public static int gcd(int x, int y) {
        return y == 0 ? x : gcd(y, x%y);
    }

    public static int ngcd(List<Integer> list, int z) {
        if(z == 1) {
            return list.get(0);
        }
        return gcd(list.get(z - 1) , ngcd(list , z - 1));
    }
    
    public boolean hasGroupsSizeX(int[] deck) {
        if (deck.length <= 1) {
            return false;
        }

        int[] aa = new int[10001];
        List<Integer> list = new ArrayList<>();
        for (int i=0;i<10001;i++) {
            for (int k: deck) {
                if (i == k) {
                    aa[i]++;
                }
            }
        }

        Arrays.sort(aa);
        int min = 0;

        for (int j=aa.length-1; j>=0; j--) {
            if (aa[j] == 0) {
                break;
            } else{
                list.add(aa[j]);
            }
        }

        // 求最大公约数
        if (ngcd(list, list.size()) == 1) {
            return false;
        }

        return true;
    }
}
```