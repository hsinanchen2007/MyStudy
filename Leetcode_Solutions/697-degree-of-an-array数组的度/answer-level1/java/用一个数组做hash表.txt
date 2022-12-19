![WechatIMG17.png](https://pic.leetcode-cn.com/b8e9b3632a873980f75f81307bdca91751479436c7e5cce5d218b069c0544212-WechatIMG17.png)

```
public int findShortestSubArray(int[] nums) {
        int max = -1;
        for (int i : nums) max = Math.max(max, i);

        int[] data = new int[max + 1];
        for (int i : nums) data[i]++;

        max = -1;
        for (int i : data) max = Math.max(i, max);

        int min = 50001;
        for (int i = 0; i < data.length; i++) {
            if (data[i] == max) {
                int start = -1, end, num = 0;
                for (int j = 0; j < nums.length; j++) {
                    if (nums[j] == i) {
                        if (num == 0) start = j;
                        num++;
                        if (num == max) {
                            end = j;
                            min = Math.min(end - start + 1, min);
                            break;
                        }
                    }
                }
                if (min == max) return min;
            }
        }

        return min;
    }
```

