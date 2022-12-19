for (int i = 0; i < arr.length; i++) {
            if (arr[i] == 0) {
                int tmp = arr.length - 1;
                while (tmp - i > 1) {
                    arr[tmp] = arr[tmp - 1];
                    tmp--;
                }
                arr[tmp] = 0;
                i++;
            }
        }