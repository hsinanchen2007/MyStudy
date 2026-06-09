**思路**
1. 找小的就是从低位到高位遍历二进制，找到1（右侧是0），然后与右侧的0进行交换，同时，将遍历过的低位进行反转
2. 找大的就是从低位到高位遍历二进制，找到1（左侧是0），然后与左侧的0进行交换，同时，将遍历过的低位进行反转

举个例子，假设某个数的二进制位1001,那么小的最接近的数应该是0110。即从低位往高位遍历，发现第二个1才满足上述要求（右侧是0），然后进行交换，同时将低两位的01进行反转。找最接近的大的也是同理。

```java
private void swap(char[] arr, int i, int j) {
        char tmp = arr[i];
        arr[i] = arr[j];
        arr[j] = tmp;
    }

    private void reverse(char[] arr, int left, int right) {
        while (left < right) {
            swap(arr, left, right);
            left++;
            right--;
        }
    }

    // 在高位多加一个0
    private char[] toBinaryCharArr(int num) {
        StringBuilder sb = new StringBuilder();
        while (num > 0) {
            sb.append(num & 1);
            num >>>= 1;
        }

        sb.append('0');
        return sb.reverse().toString().toCharArray();
    }

    private long binaryCharArrToLong(char[] arr) {
        long ans = 0;
        for (int i = 0; i < arr.length; i++) {
            ans <<= 1;
            ans += arr[i] - '0';
        }

        return ans;
    }

    public int[] findClosedNumbers(int num) {
        if (num == 1) {
            return new int[]{2, -1};
        }

        int[] ans = new int[]{-1, -1};

        // 找小的就是从低位到高位遍历二进制，找到1（右侧是0），然后与右边的0进行交换，同时，将遍历过的低位进行反转
        // 找大的就是从低位到高位遍历二进制，找到1（左侧是0），然后与左侧的0进行交换，同时，将遍历过的低位进行反转
        char[] arr = Integer.toBinaryString(num).toCharArray();
        int len = arr.length;

        for (int i = len - 2; i >= 0; i--) {
            if (arr[i] == '1' && arr[i+1] == '0') {
                swap(arr, i, i + 1);
                reverse(arr, i + 2, len - 1);
                break;
            }
        }

        ans[1] = (int) binaryCharArrToLong(arr);

        arr = toBinaryCharArr(num);
        len = arr.length;
        for (int i = len - 1; i >= 1; i--) {
            if (arr[i] == '1' && arr[i-1] == '0') {
                swap(arr, i, i - 1);
                reverse(arr, i + 1, len - 1);
                break;
            }
        }

        long bigger = binaryCharArrToLong(arr);
        if (bigger <= Integer.MAX_VALUE) {
            ans[0] = (int) bigger;
        }

        return ans;
    }
```
