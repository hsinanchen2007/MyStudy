```
代码块
```

public static boolean carPooling(int[][] trips, int capacity) {

        int[] states = new int[1000];

        for (int i = 0; i < trips.length; i++) {
            for (int j = trips[i][1]; j < trips[i][2]; j++) {
                states[j] += trips[i][0];
            }
        }

        for (int i = 0; i < 1000; i++) {

            if (states[i] > capacity) {
                return false;
            }
        }

        return true;
##    }