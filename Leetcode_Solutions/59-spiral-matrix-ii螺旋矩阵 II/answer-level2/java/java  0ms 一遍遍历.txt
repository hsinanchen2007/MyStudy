![C9511CF4-3A87-4c9d-A990-318DAA3F878C.png](https://pic.leetcode-cn.com/4c6a63d8af84dece280433a2ec1f4a99a4c4a5376f772d15249783e3d830f3fb-C9511CF4-3A87-4c9d-A990-318DAA3F878C.png)
```
int[][] result = new int[n][n];
        int count = 1;
        int dir = 0, i = 0, j = 0, minI = 0, maxI = n - 1, minJ = 0, maxJ = n - 1; //right = 0, down = 1, left = 2, up = 3;
        while (count <= (n * n)) {
            result[i][j] = count;
            count++;
            switch (dir) {
                case 0:
                    if ((j + 1) <= maxJ) {
                        j++;
                    } else {
                        i++;
                        dir = 1;
                        minI++;
                    }
                    break;
                case 1:
                    if ((i + 1) <= maxI) {
                        i++;
                    } else {
                        j--;
                        dir = 2;
                        maxJ--;
                    }
                    break;
                case 2:
                    if ((j - 1) >= minJ) {
                        j--;
                    } else {
                        i--;
                        dir = 3;
                        maxI--;
                    }
                    break;
                case 3:
                    if ((i - 1) >= minI) {
                        i--;
                    } else {
                        j++;
                        dir = 0;
                        minJ++;
                    }
                    break;
            }
        }
        return result;
```
