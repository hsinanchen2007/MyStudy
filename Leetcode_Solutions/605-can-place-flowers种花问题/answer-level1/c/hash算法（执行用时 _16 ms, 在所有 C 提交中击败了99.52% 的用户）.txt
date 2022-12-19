解题思路：
1.不改变原始数组值，申请一个临时数组保存数组值。
2.循环标记，标记的前提是，前后都是“0”，并且未种植，标记为“1”，并且cnt++；
    for (i = 0; i < flowerbedSize - 2; i++) {
        j = i + 1;
        k = i + 2;
        if (map[i] == 0 && map[k] == 0 && map[j] != 1) {
            map[j] = 1;
            cnt++;
        }
    }
3.一定要考虑边界：（1）两端可种植情况；（2）只有一块地可种植。

代码流程：
        bool canPlaceFlowers(int* flowerbed, int flowerbedSize, int n){
            int i, j, k;
            int *map;
            int cnt = 0;
            if (flowerbedSize < 0 || flowerbedSize > 20000 || n < 0 || n > flowerbedSize) {
                return false;
            }
            map = (int *)malloc(sizeof(int) * flowerbedSize);
            for (i = 0; i < flowerbedSize; i++) {
                map[i] = flowerbed[i];
            }

            if (map[0] == 0 && flowerbedSize == 1) {
                map[0] = 1;
                cnt++;
            }

            if (map[0] == 0 && map[1] == 0) {
                map[0] = 1;
                cnt++;
            }
            if (map[flowerbedSize - 1] == 0 && map[flowerbedSize - 2] == 0) {
                map[flowerbedSize - 1] = 1;
                cnt++;
            }

            for (i = 0; i < flowerbedSize - 2; i++) {
                j = i + 1;
                k = i + 2;
                if (map[i] == 0 && map[k] == 0 && map[j] != 1) {
                    map[j] = 1;
                    cnt++;
                }
            }
            free(map);
            map = NULL;
            if (n <= cnt) {
                return true;
            } else {
                return false;
            }
        }